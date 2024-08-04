#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f0xx_ll_iwdg.h"
#include "stm32f0xx_ll_crs.h"
#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_exti.h"
#include "stm32f0xx_ll_cortex.h"
#include "stm32f0xx_ll_utils.h"
#include "stm32f0xx_ll_pwr.h"
#include "stm32f0xx_ll_dma.h"
#include "stm32f0xx_ll_spi.h"
#include "stm32f0xx_ll_tim.h"
#include "stm32f0xx_ll_usart.h"
#include "stm32f0xx_ll_gpio.h"
#include "math.h"
#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "key.h"

#define MISO_Pin LL_GPIO_PIN_6
#define MISO_GPIO_Port GPIOA
#define MOSI_Pin LL_GPIO_PIN_7
#define MOSI_GPIO_Port GPIOA
#define CAL_Pin LL_GPIO_PIN_0
#define CAL_GPIO_Port GPIOA
#define CLOSE_Pin LL_GPIO_PIN_1
#define CLOSE_GPIO_Port GPIOA
#define SET2_Pin LL_GPIO_PIN_2
#define SET2_GPIO_Port GPIOA
#define SET1_Pin LL_GPIO_PIN_3
#define SET1_GPIO_Port GPIOA
#define CLKIN_Pin LL_GPIO_PIN_0
#define CLKIN_GPIO_Port GPIOB
#define CLKIN_EXTI_IRQn EXTI0_1_IRQn
#define DIRIN_Pin LL_GPIO_PIN_1
#define DIRIN_GPIO_Port GPIOB
#define DIRIN_EXTI_IRQn EXTI0_1_IRQn
#define ENIN_Pin LL_GPIO_PIN_2
#define ENIN_GPIO_Port GPIOB
#define ENIN_EXTI_IRQn EXTI2_3_IRQn
#define LED_Pin LL_GPIO_PIN_11
#define LED_GPIO_Port GPIOB
#define PWM1_Pin LL_GPIO_PIN_4
#define PWM1_GPIO_Port GPIOB
#define PWM2_Pin LL_GPIO_PIN_5
#define PWM2_GPIO_Port GPIOB
#define IN1_Pin LL_GPIO_PIN_8
#define IN1_GPIO_Port GPIOB
#define IN2_Pin LL_GPIO_PIN_9
#define IN2_GPIO_Port GPIOB
#define IN3_Pin LL_GPIO_PIN_7
#define IN3_GPIO_Port GPIOB
#define IN4_Pin LL_GPIO_PIN_6
#define IN4_GPIO_Port GPIOB
#define NSS_Pin LL_GPIO_PIN_4
#define NSS_GPIO_Port GPIOA
#define KEY1_Pin LL_GPIO_PIN_3
#define KEY1_GPIO_Port GPIOB
#define KEY2_Pin LL_GPIO_PIN_15
#define KEY2_GPIO_Port GPIOA


#ifndef NVIC_PRIORITYGROUP_0
    #define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
    4 bits for subpriority */
    #define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
    3 bits for subpriority */
    #define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
    2 bits for subpriority */
    #define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
    1 bit  for subpriority */
    #define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
    0 bit  for subpriority */
#endif

#define HIGH        1
#define LOW         0

#define CAL     LL_GPIO_IsInputPinSet(CAL_GPIO_Port,  CAL_Pin)
#define CLOSE   LL_GPIO_IsInputPinSet(CLOSE_GPIO_Port, CLOSE_Pin)
#define SET1    LL_GPIO_IsInputPinSet(SET1_GPIO_Port, SET1_Pin)
#define SET2    LL_GPIO_IsInputPinSet(SET2_GPIO_Port, SET2_Pin)
#define ENIN    LL_GPIO_IsInputPinSet(ENIN_GPIO_Port, ENIN_Pin)
#define DIRIN   LL_GPIO_IsInputPinSet(DIRIN_GPIO_Port,DIRIN_Pin) 

#define LED_H     LL_GPIO_SetOutputPin(LED_GPIO_Port, LED_Pin)
#define LED_L     LL_GPIO_ResetOutputPin(LED_GPIO_Port, LED_Pin)
#define LED_F     LL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin)
#define IN1_HIGH  LL_GPIO_SetOutputPin(IN1_GPIO_Port, IN1_Pin)
#define IN1_LOW   LL_GPIO_ResetOutputPin(IN1_GPIO_Port, IN1_Pin)
#define IN2_HIGH  LL_GPIO_SetOutputPin(IN2_GPIO_Port, IN2_Pin)
#define IN2_LOW   LL_GPIO_ResetOutputPin(IN2_GPIO_Port, IN2_Pin)
#define IN3_HIGH  LL_GPIO_SetOutputPin(IN3_GPIO_Port, IN3_Pin)
#define IN3_LOW   LL_GPIO_ResetOutputPin(IN3_GPIO_Port, IN3_Pin)
#define IN4_HIGH  LL_GPIO_SetOutputPin(IN4_GPIO_Port, IN4_Pin)
#define IN4_LOW   LL_GPIO_ResetOutputPin(IN4_GPIO_Port, IN4_Pin)

#define NSS_H   LL_GPIO_SetOutputPin(NSS_GPIO_Port, NSS_Pin)
#define NSS_L   LL_GPIO_ResetOutputPin(NSS_GPIO_Port, NSS_Pin)

#define SPI_TX_OD  LL_GPIO_SetPinOutputType(MOSI_GPIO_Port, MOSI_Pin, LL_GPIO_OUTPUT_OPENDRAIN)
#define SPI_TX_PP  LL_GPIO_SetPinOutputType(MOSI_GPIO_Port, MOSI_Pin, LL_GPIO_OUTPUT_PUSHPULL)


/* SPI command for TLE5012 */
#define READ_STATUS				0x8001			//8000
#define READ_ANGLE_VALUE		0x8021			//8020
#define READ_SPEED_VALUE		0x8031			//8030

#define WRITE_MOD1_VALUE		0x5060			//0_1010_0_000110_0001
#define MOD1_VALUE	0x0001

#define WRITE_MOD2_VALUE		0x5080			//0_1010_0_001000_0001
#define MOD2_VALUE	0x0800

#define WRITE_MOD3_VALUE		0x5091			//0_1010_0_001001_0001
#define MOD3_VALUE	0x0000

#define WRITE_MOD4_VALUE		0x50E0			//0_1010_0_001110_0001
#define MOD4_VALUE	0x0098						//9bit 512

#define WRITE_IFAB_VALUE		0x50B1
#define IFAB_VALUE 0x000D

#define ONE_FULL_STEP_DELAY_MS              1               // 一个全步所需要的时间
#define MOTOR_STEPS_PER_REV                 200             // 步进电机整步数
#define ENCODER_CNT_PER_REV                 16384           // 编码器分辨率
#define FLASH_BASS_ADDRESS                  0x08008000UL    // FLASH起始地址
#define HALF_CURRENT_CNT_MAX                10000L          // 自动半流时间
#define EN_ACTIVE_LEVEL                     HIGH             // EN有效电平
#define DIR_ACTIVE_LEVEL                    LOW            // DIR有效电平
#define SET1_SET2_CL_CAL_PULL               LL_GPIO_PULL_UP// SET1/SET2/CL/CAL引脚上下拉 LL_GPIO_PULL_UP LL_GPIO_PULL_DOWN
#define STEP_INPUT_COUNTER_RELOAD_VAL       64999L          // step输入脉冲计数器自动重装值
#define CLOSED_LOOP_MODE_CURRENT_MAX        10             // 闭环模式最大电流设置，0.1欧姆采样电阻255对应3.3A电流
#define OPEN_LOOP_MODE_CURRENT_MAX          160             // 开环模式最大电流设置，0.1欧姆采样电阻255对应3.3A电流
#define CALIBRATION_MODE_CURRENT            30              // 校准模式电流设置，0.1欧姆采样电阻255对应3.3A电流
#define CLOSED_LOOP_MODE_CURRENT_SUM_MAX    100           // 闭环模式最大电流x128，用于积分项目饱和限制
#define LOWPASS_FILTERING_A                 110             // 低通滤波参数变量
#define LOWPASS_FILTERING_B                 10              // 低通滤波参数变量

#define my_abs(x)  ((x)>0?(x):(-(x)))


extern int16_t kp;
extern int16_t ki;
extern int16_t kd;
extern int32_t step_input;
extern int32_t step_input_last;
extern int32_t step_input_sum;
extern int32_t motor_pos_set;
extern int32_t motor_pos_set_last;
extern uint8_t dir;
extern int16_t encoder_cnt;
extern int16_t encoder_cnt_last;
extern int32_t motor_pos;
extern int32_t motor_pos_last;
extern int32_t advance;
extern int32_t motor_rev_cnt;
extern int32_t motor_pos_err;
extern int32_t pid_iterm;
extern int32_t pid_dterm;
extern int32_t vector_current;
extern int32_t stepnumber;
extern float stepangle;

extern uint16_t half_current_cnt;
extern uint8_t closedloop_mode;
extern uint8_t en_mode;

extern void Output(int32_t theta, uint8_t effort);
extern uint16_t ReadAngle(void);


#ifdef __cplusplus
extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif
