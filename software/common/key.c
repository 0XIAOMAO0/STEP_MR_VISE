#include "key.h"
// #include "delay.h"

//////////////////////////////////////////////////////////////////////////////////

//// ������ʼ������
//void KEY_Init(void)
//{
//	GPIO_InitTypeDef GPIO_Initure;

//	__HAL_RCC_GPIOA_CLK_ENABLE(); // ����GPIOAʱ��
//	__HAL_RCC_GPIOB_CLK_ENABLE(); // ����GPIOCʱ��

//	GPIO_Initure.Pin = GPIO_PIN_8;		  // PA8
//	GPIO_Initure.Mode = GPIO_MODE_INPUT;  // ����
//	GPIO_Initure.Pull = GPIO_PULLUP;	  // ����
//	GPIO_Initure.Speed = GPIO_SPEED_HIGH; // ����
//	HAL_GPIO_Init(GPIOA, &GPIO_Initure);

//	GPIO_Initure.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; // PB12,13,14,15
//	GPIO_Initure.Mode = GPIO_MODE_INPUT;									  // ����
//	GPIO_Initure.Pull = GPIO_PULLUP;										  // ����
//	GPIO_Initure.Speed = GPIO_SPEED_HIGH;									  // ����
//	HAL_GPIO_Init(GPIOB, &GPIO_Initure);
//
#define PRESS_LONG_TIME  70 // ��������ʱ��


uint8_t KEY_Scan(void)
{
	static uint8_t key_up = 1; // �������ɿ���־
	static uint8_t last_press = 0; // ��һ�ΰ��µİ��I
	static uint16_t press_time = 0; // ��������ʱ��

	if (key_up && (KEY_1 == 0 || KEY_2 == 0 ))//�״ΰ���
	{
		key_up = 0;
		if (KEY_1 == 0)
			last_press = KEY1_PRES;
		else if (KEY_2 == 0)
			last_press = KEY2_PRES;
		return 0;
	}

	if(key_up == 0)//�ϴ��а��I����
	{	
		press_time ++;
		LL_mDelay(10);
		//printf("press_time:%d\r\n",press_time);
		if (KEY_1 == 1 && KEY_2 == 1) // �ɿ�
		{
			key_up = 1;

			if(press_time > PRESS_LONG_TIME) //�����Y��
			{
				press_time = 0;
				return 0;
			}
			press_time = 0;
			return last_press;
		}
		else if (KEY_1 == 0 && press_time > PRESS_LONG_TIME)//����200ms���ϣ��ж�Ϊ����
		{
			last_press = KEY1_PRES;
			return KEY1_LONG;
		}
		else if (KEY_2 == 0 && press_time > PRESS_LONG_TIME)
		{
			last_press = KEY2_PRES;
			return KEY2_LONG;
		}
	}
	return 0; // �ް�������s
}


int8_t KEY_Process(void)
{
	uint16_t key_value = 0;
	key_value = KEY_Scan(); // ֧������
	if (key_value == 0) return -1;
	
	switch (key_value)
	{
	case KEY1_PRES:
		step_input += 6400/(stepangle/2.56f);//helf turn
		break;
	case KEY2_PRES:
		step_input -= 6400/(stepangle/2.56f);//helf turn
		break;
	case KEY1_LONG:
		step_input += 256/(stepangle/2.56f);
		break;
	case KEY2_LONG:
		step_input -= 256/(stepangle/2.56f);
		break;
	
	default:
		break;
	}
	return 0;
}
