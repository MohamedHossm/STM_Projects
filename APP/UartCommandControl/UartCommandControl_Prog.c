/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                             */
/* Date            : 8/8/2023                                                  */
/* Version         : 1.0                                                       */
/* SW              : UartCommandControl                                                             */
/*****************************************************************************/

#include "STD_TYPES.h"

#include "GPIO_Interface.h"
#include "SPI_Interface.h"
#include "SYSTICK_Interface.h"
#include "ledMatrix_SPI_Interface.h"
#include "UART_Interface.h"

#include "UartCommandControl_Conf.h"
#include "UartCommandControl_Interface.h"
#include "UartCommandControl_Pivate.h"
u8 uartStringReturn[30] = { 0 };
u16 uartNUMReturn = 0;
u8 UART_SellectedFunction = 0;

UATR_Controlled_t FunDataBase[UARTSEARCHFUN_MSIZE] = { { "ledon",
		LEDARR_u8DisplayON }, { "ledoff", LEDARR_u8DisplayOFF }, { "ledm",
		LedM_u8Display }, { "spis", LedM_u8Display }

};
u8 LedMtrixPatterns[LEDMXPATTERNSIZE][ledMatrix_SPI_COLS] = { { 0, 102, 255,
		255, 255, 126, 60, 24 }, { 0, 36, 36, 0, 129, 66, 60, 0 }, { 219, 165,
		165, 129, 129, 195, 189, 255 }, { 0, 62, 42, 127, 62, 34, 34, 0 }

};
// on my hard ware
/*
GPIO_u8PIN_t LEDARR[LEDARRSIZE] = { Pin_A0, Pin_A1, Pin_A2, Pin_A3, Pin_A4,
		Pin_A5, Pin_A6, Pin_A7 };
*/
// on simu
 GPIO_u8PIN_t LEDARR[LEDARRSIZE] = { Pin_B0, Pin_B1, Pin_B2, Pin_B3, Pin_B4,
 Pin_B5, Pin_B6, Pin_B7 };


void UartCommandControl_vIint() {
	/*
	RCC_voidInitSystemClock();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	// enable uart clock
	RCC_voidEnablePeriphralCLK(APB2_USART1EN);
	// enable spi2 clock
	RCC_voidEnablePeriphralCLK(APB1_SPI2EN);
	//gpoi init
	GPIO_u8Init();

	// enable uart interrupt nvic
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	UartCommandControl_vIint();
	//uart init
	UART1_voidInit();
	UART1_u8EnterruptEnRX();
	//UART1_u8SendStringBusyW8("data");
	SPI2_vInit();
	*/
	ledMatrix_SPI_vInit(LEDMTRIXLOAD);
}
void UartCommandControl_vRunnable(void) {
	UART1_Runnable();
	if (UART1_IsDataReady()) {
		UART1_GETdata(uartStringReturn, &uartNUMReturn);

		if (UART_u8SearchFunctions_String(uartStringReturn,
				&UART_SellectedFunction) == OK) {

			FunDataBase[UART_SellectedFunction].Sellected_FUN(uartNUMReturn);
		} else {
			//do nothing
		}

	} else {

	}
	//STK_u8SetBusyWait(5000);

}
Error_t LedM_u8Display(u8 Copy_u8PatternID) {
	Error_t Local_u8Status = OK;
	Copy_u8PatternID--;
	if (Copy_u8PatternID < LEDMXPATTERNSIZE) {
		ledMatrix_SPI_u8SendPattern(LedMtrixPatterns[Copy_u8PatternID]);

	} else {
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}
Error_t LEDARR_u8DisplayON(u8 Copy_u8LedID) {
	Error_t Local_u8Status = OK;
	Copy_u8LedID--;
	if (Copy_u8LedID < LEDARRSIZE) {
		GPIO_u8SetPinV_ID(LEDARR[Copy_u8LedID], HIGH);
		//------------------------------------------------------
		UART1_u8SendStringBusyW8("led on");             // debug
		//-------------------------------------------------------
	} else {
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}

Error_t LEDARR_u8DisplayOFF(u8 Copy_u8LedID) {

	Error_t Local_u8Status = OK;
	Copy_u8LedID--;

	if (Copy_u8LedID < LEDARRSIZE) {
		GPIO_u8SetPinV_ID(LEDARR[Copy_u8LedID], LOW);
		//------------------------------------------------------
		UART1_u8SendStringBusyW8("led off");         // debug
		//-------------------------------------------------------

	} else {
		Local_u8Status = NOK;
	}
	return Local_u8Status;
}
Error_t Srting_COMP(u8 *string1, u8 *string2) {
	Error_t Local_u8Status = OK;
	for (u8 index = 0; string1[index] || string2[index]; index++) {
		if (string1[index] != string2[index]) {
			Local_u8Status = NOK;
			break;
		} else {
			//do nothing
		}
	}
	return Local_u8Status;
}

Error_t UART_u8SearchFunctions_String(u8 *PTR_SearchString,
		u8 *PTR_ReturnElementIndex) {
	Error_t Local_u8Status = NOK;
	u8 local_u8elementsIndex;
	for (local_u8elementsIndex = 0; local_u8elementsIndex < UARTSEARCHFUN_MSIZE;
			local_u8elementsIndex++) {
		if (Srting_COMP(PTR_SearchString,
				FunDataBase[local_u8elementsIndex].SearchString) == OK) {
			*PTR_ReturnElementIndex = local_u8elementsIndex;
			Local_u8Status = OK;
			break;
		} else {
			//do nothing
		}
	}
	return Local_u8Status;
}

