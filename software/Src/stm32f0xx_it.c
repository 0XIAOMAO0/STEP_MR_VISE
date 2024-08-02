#include "stm32f0xx.h"
#include "stm32f0xx_it.h"


void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
    while(1)
    {
    }
}


void SVC_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
}

uint8_t TimerCallBack_CheakDIR(void)
{
    return DIRIN == DIR_ACTIVE_LEVEL;
}

//���ݷ�������źŸı�����������¼�������
void EXTI0_1_IRQHandler(void)
{
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_1) != RESET)
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_1);
        if(TimerCallBack_CheakDIR())
        {
            LL_TIM_SetCounterMode(TIM1, LL_TIM_COUNTERMODE_UP);
        }
        else
        {
            LL_TIM_SetCounterMode(TIM1, LL_TIM_COUNTERMODE_DOWN);
        }
    }
}

uint8_t InputCallBack_CheakENN(void)
{
    return ENIN == EN_ACTIVE_LEVEL;
}

void InputCallBack_ENABLE(void)
{
    encoder_cnt = *(volatile uint16_t *)(ReadAngle() * 2 + FLASH_BASS_ADDRESS);
    step_input_sum = encoder_cnt;
    step_input = 0;
    step_input_last = 0;
    motor_pos_set = encoder_cnt;
    motor_pos_set_last = motor_pos_set;
    encoder_cnt_last = encoder_cnt;
    motor_pos = encoder_cnt;
    motor_pos_last = motor_pos;
    motor_rev_cnt = 0;
    en_mode = ENABLE;
}

void InputCallBack_DISABLE(void)
{
    en_mode = DISABLE;
}

//���ʹ���ź��ⲿ�жϺ���
void EXTI2_3_IRQHandler(void)
{
    if(LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_2) != RESET)
    {
        LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_2);
        if(InputCallBack_CheakENN())
        {
            InputCallBack_ENABLE();
            LL_TIM_SetCounter(TIM1, 0);
            LL_TIM_EnableCounter(TIM1);
        }
        else
        {
            InputCallBack_DISABLE();
            LL_TIM_DisableCounter(TIM1);
            LL_TIM_OC_SetCompareCH1(TIM3, 0);
            LL_TIM_OC_SetCompareCH2(TIM3, 0);
        }
    }
}


void TimerCallBack_Controler(void)
{
    if(en_mode == ENABLE)
    {
        if(closedloop_mode == ENABLE)
        {
            encoder_cnt = *(volatile uint16_t *)(ReadAngle() * 2 + FLASH_BASS_ADDRESS); //�����������ĽǶ�λ��ֵ
            step_input = LL_TIM_GetCounter(TIM1); //�����������������ⲿstep����������
            step_input = 0;
            if(step_input - step_input_last < -(STEP_INPUT_COUNTER_RELOAD_VAL / 2))
            {
                step_input_sum += stepangle * (STEP_INPUT_COUNTER_RELOAD_VAL + 1);
            }
            else if(step_input - step_input_last > (STEP_INPUT_COUNTER_RELOAD_VAL / 2))
            {
                step_input_sum -= stepangle * (STEP_INPUT_COUNTER_RELOAD_VAL + 1);
            }
            motor_pos_set = step_input_sum + stepangle * step_input; //����������ݵ��ӳ������ָ����λ��
            step_input_last = step_input;
            if(encoder_cnt - encoder_cnt_last > (ENCODER_CNT_PER_REV / 2))
            {
                motor_rev_cnt--;
            }
            else if(encoder_cnt - encoder_cnt_last < -(ENCODER_CNT_PER_REV / 2))
            {
                motor_rev_cnt++;
            }
            motor_pos = encoder_cnt + ENCODER_CNT_PER_REV * motor_rev_cnt; //�������ĽǶ�λ��ֵ�����������Ȧ�����ʵ�ʵ��λ��ֵ
            motor_pos_err = motor_pos_set - motor_pos; //���ֵ
            if((motor_pos_err<30 && motor_pos_err>0) ||	(motor_pos_err>-30 && motor_pos_err<0))
            {
            	motor_pos_err = 0;
						}
            if(motor_pos_err > (ENCODER_CNT_PER_REV * 0.1))  //���ֵ��С����
            {
                motor_pos_err = (ENCODER_CNT_PER_REV * 0.1);
                LED_H;
            }
            else if(motor_pos_err < -(ENCODER_CNT_PER_REV * 0.1))
            {
                motor_pos_err = -(ENCODER_CNT_PER_REV * 0.1);
                LED_H;
            }
            else
            {
                LED_L;
            }
            pid_iterm += ki * motor_pos_err / 32; //���������
            if(pid_iterm > CLOSED_LOOP_MODE_CURRENT_SUM_MAX)  //���ֱ�������
            {
                pid_iterm = CLOSED_LOOP_MODE_CURRENT_SUM_MAX;
            }
            else if(pid_iterm < -CLOSED_LOOP_MODE_CURRENT_SUM_MAX)
            {
                pid_iterm = -CLOSED_LOOP_MODE_CURRENT_SUM_MAX;
            }
            pid_dterm = LOWPASS_FILTERING_A * pid_dterm / 128 - LOWPASS_FILTERING_B * kd * (motor_pos - motor_pos_last) / 8; //΢�������
            vector_current = (kp * motor_pos_err + pid_iterm + pid_dterm) / 128; //PID�������ֵ
            advance = (motor_pos - motor_pos_last) * 3;
            encoder_cnt_last = encoder_cnt;
            motor_pos_last = motor_pos;
            if(vector_current > 0)
            {
                encoder_cnt += ((ENCODER_CNT_PER_REV / MOTOR_STEPS_PER_REV) + advance); //����ʸ������1.8�ȼ���ǰ����
            }
            else if(vector_current < 0)
            {
                encoder_cnt -= ((ENCODER_CNT_PER_REV / MOTOR_STEPS_PER_REV) - advance);
                vector_current = -vector_current;
            }
            if(vector_current > CLOSED_LOOP_MODE_CURRENT_MAX)
            {
                vector_current = CLOSED_LOOP_MODE_CURRENT_MAX;    //����ʸ�����ֵ����
            }
           Output(encoder_cnt, vector_current);
        }
        else
        {
            step_input = LL_TIM_GetCounter(TIM1);
            if(step_input - step_input_last < -(STEP_INPUT_COUNTER_RELOAD_VAL / 2))
            {
                step_input_sum += stepangle * (STEP_INPUT_COUNTER_RELOAD_VAL + 1);
            }
            else if(step_input - step_input_last > (STEP_INPUT_COUNTER_RELOAD_VAL / 2))
            {
                step_input_sum -= stepangle * (STEP_INPUT_COUNTER_RELOAD_VAL + 1);
            }
            motor_pos_set = step_input_sum + stepangle * step_input;
            step_input_last = step_input;
            if(motor_pos_set == motor_pos_set_last)
            {
                half_current_cnt++;
                if(half_current_cnt >= HALF_CURRENT_CNT_MAX)
                {
                    half_current_cnt = HALF_CURRENT_CNT_MAX;
                }
            }
            else
            {
                half_current_cnt = 0;
            }
            if(half_current_cnt >= OPEN_LOOP_MODE_CURRENT_MAX)  //1s�Զ��������ģʽ
            {
                Output(motor_pos_set, OPEN_LOOP_MODE_CURRENT_MAX / 2);
            }
            else
            {
                Output(motor_pos_set, OPEN_LOOP_MODE_CURRENT_MAX);
            }
            motor_pos_set_last = motor_pos_set;
        }
    }
}

void TIM6_IRQHandler(void)
{
    if(LL_TIM_IsActiveFlag_UPDATE(TIM6) == SET)
    {
        LL_TIM_ClearFlag_UPDATE(TIM6);
        LL_IWDG_ReloadCounter(IWDG);//�忴�Ź�
        TimerCallBack_Controler();
    }
}


