/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 1/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : IR                                                         */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"

#define LED1 Pin_A1
#define LED2 Pin_A2
#define LED3 Pin_A3

volatile u8 IR_Start_Status = 0;
volatile u16 TimesArray[50] = { 0 };
volatile u8 IR_counter = 0;
volatile u8 IRR_com = 0;
u8 key = 0;

void convertFunction() {
	u8 i = 0;
	key = 0;
	if (IRR_com) {
		IRR_com = 0;
		for (u8 index = 17; index < 25; index++, i++) {
			if (TimesArray[index] > 2000) {
				key |= 1 << i;

			} else {
				// do nothing
			}
		}
	}
}
void vGetAction(void) {
	//asm("NOP");
	IR_Start_Status = 0;
	IR_counter = 0;
	IRR_com = 1;
}
void vGetframe(void) {
	u32 result = 0;
	if (IR_Start_Status == 0) {
		STK_u8SetIntervalSingleOV(50000, vGetAction);
		IR_Start_Status = 1;
	} else {
		STK_u8SpentTimer(&result);
		STK_u8SetIntervalSingleOV(50000, vGetAction);
		TimesArray[IR_counter] = result;
		IR_counter++;
	}
}
int IR_runnable(void) {

	//enable RCC 8-MHz
	RCC_voidInitSystemClock();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	GPIO_u8Init();
	STK_u8Init();

	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI0);
	EXTI_u8En(EXTI_Line0);

	GPIO_u8SetPinV_ID(Pin_A4, HIGH);
	GPIO_u8SetPinV_ID(Pin_A5, LOW);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line0, EXTI_FAILING);

	EXTI_u8Setter_IRQ(EXTI_Line0, vGetframe);


		convertFunction();
		if (key != 0) {
			if (key == 6) {
				key = 0;
				GPIO_u8SetPinV_ID(LED1, HIGH);
			} else if (key == 10) {
				key = 0;
				GPIO_u8SetPinV_ID(LED2, HIGH);
			} else if (key == 30) {
				key = 0;
				GPIO_u8SetPinV_ID(LED1, LOW);
			} else if (key == 50) {
				key = 0;
				GPIO_u8SetPinV_ID(LED2, LOW);
			}

	}

return 0 ;
}
