/*
 * lap1_ledMarixControl.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Amm
 */
#include "STD_TYPES.h"
#include "../HAL/LEDMRX/LEDMRX_Interface.h"
#include "Lap1_LedMatixControl.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

volatile u8 LedMRX_stateV = 1;
volatile u8 LedMRX_Speed = LIMITSPEAD_LOW;
const LED_MRX_CONTANER_t LEDMRX_letters[LEDMRX_lettersSIZE];



void ledmatrex(char name[]) {
	char chardata[2];

	u8 speed;
	chardata[1] = 0;

	for (u8 i = 0; name[i]; i++) {
		speed = NORMALSPEED / LedMRX_Speed;
		chardata[0] = name[i];
		APPLEDMRX_u8WriteStringMove(chardata, speed);
	}
}
void B1Fun() {
	LedMRX_stateV = 1;
	//GPIO_u8SetPinV_ID(Pin_B10, HIGH);
}
void B2Fun() {
	LedMRX_stateV = 0;
	//GPIO_u8SetPinV_ID(Pin_B10, LOW);
}
void B3Fun() {
	LedMRX_Speed += 3;
	if (LedMRX_Speed > LIMITSPEAD_HIGH) {
		LedMRX_Speed = LIMITSPEAD_HIGH;
	}
}
void B4Fun() {
	LedMRX_Speed -= 3;
	if (LedMRX_Speed <= LIMITSPEAD_LOW) {
		LedMRX_Speed = LIMITSPEAD_LOW;
	}

}
Error_t APPLEDMRX_u8WriteStringMove(char *string, u16 Rating) {
	Error_t local_u8Status = OK;
	//u8 rebeat = 0;
	s16 returnindex = 0;
	u8 DisValue[8] = { 0 };
	for (u16 index = 0; string[index]; index++) {
		//rebeat = RETING;
		if (Search(string[index], &returnindex) == OK) {

			for (s8 i = -5; i < LEDMRXCOLSIZE; i++) {
				for (u8 j = 0; j < Rating;) {

					LEDMRX_voidCopyvalue(LEDMRX_letters[returnindex].arr,
							DisValue, i);
					LEDMRX_u8Display(DisValue);
					if (LedMRX_stateV == 1) {
						j++;
					} else {
						//do notiong
					}
				}
			}
		} else {
			for (s8 i = -5; i < LEDMRXCOLSIZE; i++) {
				for (u8 j = 0; j < Rating;) {
					LEDMRX_voidCopyvalue(LEDMRX_letters[LEDMRXEROR].arr,
							DisValue, i);
					LEDMRX_u8Display(DisValue);
					if (LedMRX_stateV == 1) {
						j++;
					} else {
						//do notiong
					}
				}
			}
		}
	}
	//Delay(500);

	return local_u8Status;
}
