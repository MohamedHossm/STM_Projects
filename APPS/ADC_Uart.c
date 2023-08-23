/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 8/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : UART_Control                                                          */
/*****************************************************************************/

#include <I2C_Interface.h>
#include "STD_TYPES.h"
#include "Delay.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "UART_Interface.h"
#include "ADC_Interface.h"
u16 ADC_ReadData = 0;
int main(void) {

	//enable RCC 8-MHz

	RCC_voidInitSystemClock();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	// enable uart clock
	RCC_voidEnablePeriphralCLK(APB2_USART1EN);
	// enable spi2 clock
	//RCC_voidEnablePeriphralCLK(APB1_SPI2EN);
	RCC_voidEnablePeriphralCLK(APB2_ADC1EN);
	RCC_vSetADC_CLK(RCC_ADC_CLK_D_8);

	//gpoi init
	GPIO_u8Init();
	GPIO_u8SetPinV_ID(Pin_B7, HIGH);

	ADC_u8Init();

	// enable uart interrupt nvic
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	//uart init
	UART1_voidInit();
	UART1_u8EnterruptEnRX();
	while (1) {
		//ADC_u8SetNSequance(0);
		ADC_u8ReadCHSequance(ADC_ch1, &ADC_ReadData, 0);

		ADC_u8ReadCH(ADC_ch1, &ADC_ReadData);
		UART1_u8SendNumString(ADC_ReadData);

		UART1_u8SendByteBusyw8(13);
		UART1_u8SendByteBusyw8(10);
		Delay(500);
		//STK_u8SetBusyWait(1000);
	}
	return 0;
}
