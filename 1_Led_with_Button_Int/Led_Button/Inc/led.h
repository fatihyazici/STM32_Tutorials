/*
 * led.h
 *
 *  Created on: Aug 5, 2020
 *      Author: fatih
 */

#ifndef LED_H_
#define LED_H_



#include "main.h"



/*Led Control Commands*/
#define LED_OFF			((BOARD_LED_GPIO_Port)->BSRR = (uint32_t)(((uint32_t)BOARD_LED_Pin) << 16))
#define LED_ON			((BOARD_LED_GPIO_Port)->BSRR = (uint32_t)(BOARD_LED_Pin))
#define LED_TOGGLE		((BOARD_LED_GPIO_Port)->ODR ^= (BOARD_LED_Pin))


#endif /* LED_H_ */
