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
#include "HlED.h"
#include "HButton.h"
#include "EXTI_Interface.h"
void Delay(u32 local_u32Time_delay);

int main(void) {

	RCC_voidInitSystemClock();

	NVIC_u8Set_PR_options();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
// set gpio in pull up
	GPIO_u8Init();
	GPIO_u8SetPinV_ID(Pin_A0, HIGH);
	GPIO_u8SetPinV_ID(Pin_A1, HIGH);
	GPIO_u8SetPinV_ID(Pin_A2, HIGH);
//enable NVIC ex1 , ex2 , ex0
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI0);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI1);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI2);
	NVIC_u8Set_PR_Value(INTERRUPT_EXTI0, 2, 2);
	NVIC_u8Set_PR_Value(INTERRUPT_EXTI1, 0, 1);
	NVIC_u8Set_PR_Value(INTERRUPT_EXTI2, 0, 1);
//enable exti peripheral and set latch
	EXTI_u8En(EXTI_Line0);
	EXTI_u8En(EXTI_Line1);
	EXTI_u8En(EXTI_Line2);

	EXTI_u8Set_Inturrupt_latch(EXTI_Line0, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line1, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line2, EXTI_FAILING);

	//NVIC_u8Set_Pend_IRQ(INTERRUPT_EXTI0);
	GPIO_u8SetPinV_ID(Pin_B0, LOW);
	GPIO_u8SetPinV_ID(Pin_B1, LOW);
	GPIO_u8SetPinV_ID(Pin_B2, LOW);

	while (1) {

		/*
		 Delay(500) ;
		 NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI0);
		 NVIC_u8Set_Pend_IRQ(INTERRUPT_EXTI0);
		 Delay(500) ;
		 */
	}

	return 0;
}
void EXTI0_IRQHandler(void) {

	static u8 local_flage = HIGH;
	GPIO_u8SetPinV_ID(Pin_B0, local_flage);
	local_flage = !local_flage;
	EXTI_u8CLR_pend(EXTI_Line0);
}

void EXTI1_IRQHandler(void) {
	static u8 local_flage = HIGH;
	GPIO_u8SetPinV_ID(Pin_B1, local_flage);
	local_flage = !local_flage;
	EXTI_u8CLR_pend(EXTI_Line2);
}
void EXTI2_IRQHandler(void) {
	static u8 local_flage = HIGH;
	GPIO_u8SetPinV_ID(Pin_B2, local_flage);
	local_flage = !local_flage;
	EXTI_u8CLR_pend(EXTI_Line2);
}

void Delay(u32 local_u32Time_delay) {

	for (u32 local_index = 0; local_index <= local_u32Time_delay;
			local_index++) {
		for (u32 local_index = 0; local_index <= local_u32Time_delay;
				local_index++)
			asm("NOP");
	}
}

