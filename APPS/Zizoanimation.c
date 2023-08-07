/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 2/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : LED_Matrex IR                                                         */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "Delay.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "LEDMRX_Interface.h"
#include "AFIO_Interface.h"
volatile static u8 funstatus = 0;
u8 Zizo_animation[10][8] = { { 0, 192, 192, 16, 203, 63, 203, 16 }, { 0, 96, 96,
		144, 75, 63, 203, 16 }, { 48, 48, 0, 144, 75, 63, 203, 16 }, { 0, 12,
		12, 144, 75, 63, 203, 16 }, { 0, 0, 3, 147, 72, 63, 75, 147 }, { 3, 3,
		0, 147, 75, 63, 72, 144 }, { 0, 24, 88, 83, 75, 63, 72, 144 }, { 0, 48,
		114, 68, 75, 63, 75, 144 }, { 0, 192, 200, 136, 75, 63, 203, 16 }, { 0,
		192, 192, 16, 203, 63, 203, 16 } };
void Fun() {
	//Delay(10);
	funstatus++;
	GPIO_u8SetPinV_ID(Pin_C13, HIGH);
}
int main(void) {

	//enable RCC 8-MHz

	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	RCC_voidEnablePeriphralCLK(APB2_AFIOEN);
	AFIO_u8setInterrupt(EXTI_Line11, AFIO_SEL_PB);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI15_10);
	GPIO_u8Init();
	GPIO_u8SetPinV_ID(Pin_B11, HIGH);
	EXTI_u8Setter_IRQ(EXTI_Line11, Fun);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line11, EXTI_FAILING);
	EXTI_u8En(EXTI_Line11);

	while (1) {
		//
		if (funstatus > 0) {
			LEDMRX_u8DisplayArray(Zizo_animation + 1, 100, 8);
			funstatus--;
		} else {
			LEDMRX_u8DisplayArray(Zizo_animation, 100, 1);
		}

	}

	return 0;
}
