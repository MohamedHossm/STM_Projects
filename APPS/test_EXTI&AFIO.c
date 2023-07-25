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
#include "AFIO_Interface.h"
void Delay(u32 local_u32Time_delay);
void ButtonONE ();
void ButtonTWO ();
void ButtonThree ();
int main(void) {

	RCC_voidInitSystemClock();

	NVIC_u8Set_PR_options();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
// set gpio in pull up
	GPIO_u8Init();
	GPIO_u8SetPinV_ID(Pin_B0, HIGH);
	GPIO_u8SetPinV_ID(Pin_B15, HIGH);
	GPIO_u8SetPinV_ID(Pin_B7, HIGH);
//enable NVIC ex1 , ex2 , ex0
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI0);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI9_5);
	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI15_10);

//enable exti peripheral and set latch
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line0 ,AFIO_SEL_PB);

	EXTI_u8En(EXTI_Line15);
	EXTI_u8En(EXTI_Line7);
	EXTI_u8En(EXTI_Line0);



	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line7 ,AFIO_SEL_PB);
	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line15 ,AFIO_SEL_PB);

	EXTI_u8Set_Inturrupt_latch(EXTI_Line15, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line7, EXTI_FAILING);
	EXTI_u8Set_Inturrupt_latch(EXTI_Line0, EXTI_FAILING);


	EXTI_u8Setter_IRQ(EXTI_Line15 ,&ButtonONE);
	EXTI_u8Setter_IRQ(EXTI_Line7 ,&ButtonTWO);
	EXTI_u8Setter_IRQ(EXTI_Line0 ,&ButtonThree);

	//NVIC_u8Set_Pend_IRQ(INTERRUPT_EXTI0);
	GPIO_u8SetPinV_ID(Pin_B3, LOW);
	GPIO_u8SetPinV_ID(Pin_B1, LOW);
	GPIO_u8SetPinV_ID(Pin_B2, LOW);

	while (1) {


	}

	return 0;
}
void ButtonONE (){
	GPIO_u8SetPinV_ID(Pin_B3, HIGH);
}
void ButtonTWO (){
	GPIO_u8SetPinV_ID(Pin_B1, HIGH);
}
void ButtonThree (){
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

