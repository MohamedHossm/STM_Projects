/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 2/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : ZIZO animation                                                         */
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
#include "UART_Interface.h"

u8 rdata = 0;
u8 uartStringReturn[30] = "walla ya 3la2";
u16 uartNUMReturn = 0;

int main(void) {

	//enable RCC 8-MHz

	RCC_voidInitSystemClock();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);

	//gpoi init
	GPIO_u8Init();

	// enable uart clock
	RCC_voidEnablePeriphralCLK(APB2_USART1EN);

	// enable uart interrupt nvic
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	//uart init
	UART1_voidInit();
	//UART1_u8EnterruptEnRX();
UART1_u8SendStringBasyW8("data");
	while (1) {
		//

	}

	return 0;
}
