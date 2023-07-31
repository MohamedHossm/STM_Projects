/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 16/7/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : mian                                                         */
/*****************************************************************************/

#include "STD_TYPES.h"

#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "NVIC_Interface.h"

#include "Delay.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LEDMRX_Interface.h"
#include "Lap1_LedMatixControl.h"



u16 i =0;
int main(void) {

	RCC_voidInitSystemClock();
	// init systick as 1MHz
	STK_u8Init();
	//setting groubs
	//NVIC_u8Set_PR_options();            // no need
// enable RCC
	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	RCC_voidEnablePeriphralCLK(APB2_AFIOEN);
// set LED matrix out bottuns in pull up
	GPIO_u8Init();
//set up for in pull up

// enable NVIC for

	NVIC_u8Set_EN_IRQ(INTERRUPT_EXTI9_5);

// enable EXIT

	EXTI_u8En(EXTI_Line7);
//-------------------------------------------------------------------

// enable AFIO port b

	AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line7, AFIO_SEL_PB);

	//set latching

	EXTI_u8Set_Inturrupt_latch(EXTI_Line7, EXTI_FAILING);

	//set callback

//lab2_animationControl_Init();

	while (1) {


		 LEDMRX_u8WriteStringMoveEnglishControlled("mohamed", 80, i);
		 i ++ ;
		//LEDMRX_u8WriteStringMoveArabic("m7md ",100);
	//	LEDMRX_u8WriteStringMoveEnglish("mohamed ",100);
	}

	return 0;
}

