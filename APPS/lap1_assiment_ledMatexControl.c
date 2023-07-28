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

//#include "Delay.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LEDMRX_Interface.h"

#define B1 Pin_B0
#define B2 Pin_B1
#define B3 Pin_B4
#define B4 Pin_B5

#define NORMALSPEED 144
#define LIMITSPEAD_HIGH 12
#define LIMITSPEAD_LOW 3

volatile u8 LedMRX_stateV = 1;
volatile u8 LedMRX_Speed = LIMITSPEAD_LOW;
const LED_MRX_CONTANER_t LEDMRX_letters[LEDMRX_lettersSIZE];

void B1Fun();
void B2Fun();
void B3Fun();
void B4Fun();

void ledmatrex(char name[]);
Error_t APPLEDMRX_u8WriteStringMove(char *string, u16 Rating);
int main(void) {

	RCC_voidInitSystemClock();
	STK_u8Init();
	NVIC_u8Set_PR_options();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	RCC_voidEnablePeriphralCLK(APB2_AFIOEN);
	// set LED matrix out bottuns in pull up
	GPIO_u8Init();
	//set up
	GPIO_u8SetPinV_ID(B1, HIGH);
	GPIO_u8SetPinV_ID(B2, HIGH);
	GPIO_u8SetPinV_ID(B3, HIGH);
	GPIO_u8SetPinV_ID(B4, HIGH);
	// enable NVIC for
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI0);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI1);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI2);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI9_5);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI4);

// enable EXIT
	EXTI_u8En(EXTI_Line0);
	EXTI_u8En(EXTI_Line1);
	EXTI_u8En(EXTI_Line4);
	EXTI_u8En(EXTI_Line5);
//-------------------------------------------------------------------

// enable AFIO port b
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line0, AFIO_SEL_PB);
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line1, AFIO_SEL_PB);
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line4, AFIO_SEL_PB);
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line5, AFIO_SEL_PB);

	//set latching
	EXTI_u8Set_Inturrupt_latch(EXTI_Line0, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line1, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line4, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line5, EXTI_FAILING);

	//set callback
	EXTI_u8Setter_IRQ(EXTI_Line0, &B1Fun);
	EXTI_u8Setter_IRQ(EXTI_Line1, &B2Fun);
	EXTI_u8Setter_IRQ(EXTI_Line4, &B3Fun);
	EXTI_u8Setter_IRQ(EXTI_Line5, &B4Fun);
	GPIO_u8SetPinV_ID(Pin_B10, HIGH);
	while (1) {

		ledmatrex("mohamed");

		// do nothing
	}

	return 0;
}

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
	GPIO_u8SetPinV_ID(Pin_B10, HIGH);
}
void B2Fun() {
	LedMRX_stateV = 0;
	GPIO_u8SetPinV_ID(Pin_B10, LOW);
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
