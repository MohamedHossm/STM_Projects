/*
 * lab2_animationControl_config.c
 *
 *  Created on: Jul 28, 2023
 *      Author: Amm
 */
#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "lab2_animationControl.h"

GPIO_u8PIN_t LedsArray[LEDNUM] = { Pin_A0, Pin_A1, Pin_A2, Pin_A3, Pin_A4,
		Pin_A5, Pin_A6, Pin_A7 };
