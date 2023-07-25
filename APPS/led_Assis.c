/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 16/7/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : Blink led                                                        */
/*****************************************************************************/

#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"

#include "EXTI_Interface.h"
#include "AFIO_Interface.h"
#include "SYSTICK_Interface.h"
#define LEDS_NUM 8
GPIO_u8PIN_t LedsArray[LEDS_NUM] = { Pin_B12, Pin_B13, Pin_A8, Pin_A9, Pin_A10,
		Pin_A11, Pin_A12, Pin_B6 };
void Delay(u32 local_u32Time_delay);
void ButtonONE();
void ButtonTWO();
void ButtonThree();

void Ping_Pong(u8 num);
void Fta7y_Ya_wrda(u8 num);
void Flash(u8 num);
int main(void) {

	RCC_voidInitSystemClock();
	STK_u8Init();
	NVIC_u8Set_PR_options();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);

	GPIO_u8Init();

	while (1) {
		Ping_Pong(4);
		Fta7y_Ya_wrda(4);
		Flash(5);

	}

	return 0;
}
void Flash(u8 num) {
	u8 Value = LOW;
	for (u8 i = 0; i < num * 2; i++) {

		Value = !Value;

		for (u8 index = 0; index < LEDS_NUM; index++) {
			GPIO_u8SetPinV_ID(LedsArray[index], Value);

		}
		STK_u8SetBusyWait(500);
		//Delay(500);
	}
}
void Fta7y_Ya_wrda(u8 num) { //

	u8 Value = HIGH;
	s8 frist = 0;
	u8 last = 0;
	for (u8 i = 0; i < num; i++) {
		frist = (LEDS_NUM / 2) - 1;
		last = (LEDS_NUM / 2);
		for (; frist >= 0 && last < LEDS_NUM; frist--, last++) {
			GPIO_u8SetPinV_ID(LedsArray[frist], Value);
			GPIO_u8SetPinV_ID(LedsArray[last], Value);
			STK_u8SetBusyWait(250);
			//Delay(250);
		}
		frist = 0;
		last = LEDS_NUM - 1;
		for (; frist <= last; frist++, last--) {
			GPIO_u8SetPinV_ID(LedsArray[frist], !Value);
			GPIO_u8SetPinV_ID(LedsArray[last], !Value);
			STK_u8SetBusyWait(250);
			//Delay(250);
		}
	}
}
void Ping_Pong(u8 num) {
	u8 Value = HIGH;
	for (u8 k = 0; k < num; k++) {

		for (u8 i = 0; i < LEDS_NUM; i++) {
			if (i != 0) {
				GPIO_u8SetPinV_ID(LedsArray[i - 1], !Value);
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			}
			{
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			}
			STK_u8SetBusyWait(250);
			//Delay(250);
		}

		for (s8 i = LEDS_NUM - 1; i >= -1; i--) {
			if (i == -1) {

				GPIO_u8SetPinV_ID(LedsArray[i + 1], !Value);
			} else if (i != LEDS_NUM - 1) {
				GPIO_u8SetPinV_ID(LedsArray[i + 1], !Value);
				GPIO_u8SetPinV_ID(LedsArray[i], Value);
			} else {
				GPIO_u8SetPinV_ID(LedsArray[i], !Value);
			}
			STK_u8SetBusyWait(250);
			//Delay(250);

		}

	}
}

void ButtonONE() {
	static u8 Flage = LOW;
	GPIO_u8SetPinV_ID(Pin_C13, Flage);
	Flage = !Flage;
}
void ButtonTWO() {
	GPIO_u8SetPinV_ID(Pin_B1, HIGH);
}
void ButtonThree() {
	GPIO_u8SetPinV_ID(Pin_B2, HIGH);
}

void Delay(u32 local_u32Time_delay) {

	for (u32 local_index = 0; local_index <= local_u32Time_delay;
			local_index++) {
		for (u32 local_index = 0; local_index <= local_u32Time_delay;
				local_index++)
			asm("NOP");
	}
}

