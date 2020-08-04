/*
 * led.c
 *
 *  Created on: Aug 5, 2020
 *      Author: fatih
 */


#include "led.h"



extern UART_HandleTypeDef huart2;

uint8_t button_pressed_flag  = 0;
uint8_t button_pressed_count = 0;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if((GPIO_Pin == BOARD_BUTTON_Pin))
	{
		button_pressed_flag = 1;
		button_pressed_count++;
	}
}





void Uart_Send_Data(UART_HandleTypeDef *huart, uint8_t* data, uint8_t size)
{
	HAL_UART_Transmit(huart, data, size, HAL_MAX_DELAY);
}


//if button pressed , write to uart 2 "button pressed" and toggle led according to press count
void main_process()
{
	if(button_pressed_flag)
	{
		button_pressed_flag = 0;
		Uart_Send_Data(&huart2, (uint8_t *)"button pressed", sizeof("button pressed"));
	}

	if(button_pressed_count % 2 )
		LED_ON;
	else
		LED_OFF;



}
