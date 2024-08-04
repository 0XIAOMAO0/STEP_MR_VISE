#ifndef _KEY_H
#define _KEY_H

#include "main.h"
#include "stm32f0xx_ll_gpio.h"
// #define KEY0   PCin(8)
// #define KEY1   PCin(9)
// #define KEY2   PDin(2)
// #define WK_UP  PAin(0)


#define KEY_1 LL_GPIO_IsInputPinSet(KEY1_GPIO_Port, KEY1_Pin)
#define KEY_2 LL_GPIO_IsInputPinSet(KEY2_GPIO_Port, KEY2_Pin)
// #define KEY_U HAL_GPIO_ReadPin(KEY_U_GPIO_Port, KEY_U_Pin)
// #define KEY_D HAL_GPIO_ReadPin(KEY_D_GPIO_Port, KEY_D_Pin)
// #define KEY_L HAL_GPIO_ReadPin(KEY_L_GPIO_Port, KEY_L_Pin)
// #define KEY_R HAL_GPIO_ReadPin(KEY_R_GPIO_Port, KEY_R_Pin)
// #define KEY_O HAL_GPIO_ReadPin(KEY_O_GPIO_Port, KEY_O_Pin)

#define KEY1_PRES 1 // KEY0
#define KEY2_PRES 2 // KEY1
#define KEY1_LONG 3 // KEY0
#define KEY2_LONG 4 // KEY1

uint8_t KEY_Scan(void);
int8_t KEY_Process(void);
#endif
