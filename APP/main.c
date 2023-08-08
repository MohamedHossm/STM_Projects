/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 8/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : UART_Control                                                          */
/*****************************************************************************/

#include "STD_TYPES.h"
//#include "Delay.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "EXTI_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "AFIO_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
#include "ledMatrix_SPI_Interface.h"
#include "UartCommandControl_Interface.h"
int main(void) {

	//enable RCC 8-MHz

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
	//UART1_u8SendStringBasyW8("data");
	SPI2_vInit();
	UartCommandControl_vIint();
	while (1) {

		UartCommandControl_vRunnable();
	}
	return 0;
}
