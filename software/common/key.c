#include "key.h"
// #include "delay.h"

//////////////////////////////////////////////////////////////////////////////////

//// 按键初始化函数
//void KEY_Init(void)
//{
//	GPIO_InitTypeDef GPIO_Initure;

//	__HAL_RCC_GPIOA_CLK_ENABLE(); // 开启GPIOA时钟
//	__HAL_RCC_GPIOB_CLK_ENABLE(); // 开启GPIOC时钟

//	GPIO_Initure.Pin = GPIO_PIN_8;		  // PA8
//	GPIO_Initure.Mode = GPIO_MODE_INPUT;  // 输入
//	GPIO_Initure.Pull = GPIO_PULLUP;	  // 上拉
//	GPIO_Initure.Speed = GPIO_SPEED_HIGH; // 高速
//	HAL_GPIO_Init(GPIOA, &GPIO_Initure);

//	GPIO_Initure.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15; // PB12,13,14,15
//	GPIO_Initure.Mode = GPIO_MODE_INPUT;									  // 输入
//	GPIO_Initure.Pull = GPIO_PULLUP;										  // 上拉
//	GPIO_Initure.Speed = GPIO_SPEED_HIGH;									  // 高速
//	HAL_GPIO_Init(GPIOB, &GPIO_Initure);
//
#define PRESS_LONG_TIME  70 // 按键长按时间


uint8_t KEY_Scan(void)
{
	static uint8_t key_up = 1; // 按键按松开标志
	static uint8_t last_press = 0; // 上一次按下的按鍵
	static uint16_t press_time = 0; // 按键按下时间

	if (key_up && (KEY_1 == 0 || KEY_2 == 0 ))//首次按下
	{
		key_up = 0;
		if (KEY_1 == 0)
			last_press = KEY1_PRES;
		else if (KEY_2 == 0)
			last_press = KEY2_PRES;
		return 0;
	}

	if(key_up == 0)//上次有按鍵按下
	{	
		press_time ++;
		LL_mDelay(10);
		//printf("press_time:%d\r\n",press_time);
		if (KEY_1 == 1 && KEY_2 == 1) // 松开
		{
			key_up = 1;

			if(press_time > PRESS_LONG_TIME) //长按結束
			{
				press_time = 0;
				return 0;
			}
			press_time = 0;
			return last_press;
		}
		else if (KEY_1 == 0 && press_time > PRESS_LONG_TIME)//按下200ms以上，判定为长按
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
	return 0; // 无按键按下s
}


int8_t KEY_Process(void)
{
	uint16_t key_value = 0;
	key_value = KEY_Scan(); // 支持连按
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
