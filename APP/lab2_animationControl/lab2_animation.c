#include "STD_TYPES.h"
#include "SYSTICK_Interface.h"
#include "Delay.h"
#include "GPIO_Interface.h"
#include "EXTI_Interface.h"
#include "lab2_animationControl.h"

volatile u8 status = 0;
u8 laststate = 0;
extern GPIO_u8PIN_t LedsArray[LEDNUM];
void (*funcs[3])(u8) = {&Flash, & Fta7y_Ya_wrda,&Ping_Pong };

void lab2_animationControl_Runnable() {
	laststate = status;
	funcs[status](1);
}
void lab2_animationControl_Init() {
	GPIO_u8SetPinV_ID(BCON, HIGH);
	EXTI_u8Setter_IRQ(EXTI_Line7, &BCONFun);
}
void Flash(u8 num) {
	u8 Value = LOW;
	for (u8 i = 0; i < LEDNUM; i++) {
		GPIO_u8SetPinV_ID(LedsArray[i], LOW);
	}
	for (u8 i = 0; i < num * 2 && (laststate == status); i++) {
		Value = !Value;
		for (u8 index = 0; index < LEDNUM && (laststate == status); index++) {
			GPIO_u8SetPinV_ID(LedsArray[index], Value);
		}
		//STK_u8SetBusyWait(500);
		Delay(250);
	}
}
void Fta7y_Ya_wrda(u8 num) { //
	for (u8 i = 0; i < LEDNUM; i++) {
		GPIO_u8SetPinV_ID(LedsArray[i], LOW);
	}
	u8 Value = HIGH;
	s8 frist = 0;
	u8 last = 0;
	for (u8 i = 0; i < num && (laststate == status); i++) {
		frist = (LEDNUM / 2) - 1;
		last = (LEDNUM / 2);
		for (; frist >= 0 && last < LEDNUM && (laststate == status);
				frist--, last++) {
			GPIO_u8SetPinV_ID(LedsArray[frist], Value);
			GPIO_u8SetPinV_ID(LedsArray[last], Value);
			//STK_u8SetBusyWait(250);
			Delay(250);
		}
		frist = 0;
		last = LEDNUM - 1;
		for (; frist <= last && (laststate == status); frist++, last--) {
			GPIO_u8SetPinV_ID(LedsArray[frist], !Value);
			GPIO_u8SetPinV_ID(LedsArray[last], !Value);
			//STK_u8SetBusyWait(250);
			Delay(250);
		}
	}
}
void Ping_Pong(u8 num) {
	for (u8 i = 0; i < LEDNUM; i++) {
		GPIO_u8SetPinV_ID(LedsArray[i], LOW);
	}
	u8 Value = HIGH;
	for (u8 k = 0; k < num && (laststate == status); k++) {

		for (u8 i = 0; i < LEDNUM && (laststate == status); i++) {
			if (i != 0) {
				GPIO_u8SetPinV_ID(LedsArray[i - 1], !Value);
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			}
			{
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			}
			//STK_u8SetBusyWait(250);
			Delay(250);
		}

		for (s8 i = LEDNUM - 1; i >= -1 && (laststate == status); i--) {
			if (i == -1) {

				GPIO_u8SetPinV_ID(LedsArray[i + 1], !Value);
			} else if (i != LEDNUM - 1) {
				GPIO_u8SetPinV_ID(LedsArray[i + 1], !Value);
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			} else {
				GPIO_u8SetPinV_ID(LedsArray[i], !Value);
			}
			//STK_u8SetBusyWait(250);
			Delay(250);

		}

	}
}
void BCONFun() {
	status++;
	status = status % 3;
}

