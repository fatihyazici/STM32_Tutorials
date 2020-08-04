/*
 * led.c
 *
 *  Created on: Aug 5, 2020
 *      Author: fatih
 */


#include "led.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == BOARD_BUTTON_Pin)
		LED_TOGGLE;
}


