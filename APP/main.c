/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 8/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : UART_Control                                                          */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "Delay.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
//#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "UART_Interface.h"
#include "SPI_Interface.h"
//#include "ledMatrix_SPI_Interface.h"
#include "UartCommandControl_Interface.h"
//#include "ADC_Interface.h"
//u16 ADC_ReadData = 0;
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
	//RCC_voidEnablePeriphralCLK(APB2_ADC1EN);
	//RCC_vSetADC_CLK(RCC_ADC_CLK_D_8);

	//gpoi init
	GPIO_u8Init();
	//GPIO_u8GetPinV_ID(Pin_B7, HIGH);

	//ADC_u8Init();

	// enable uart interrupt nvic
	NVIC_u8Set_EN_IRQ(INTERRUPT_USART1);

	//UartCommandControl_vIint();
	//uart init
	UART1_voidInit();
	UART1_u8EnterruptEnRX();
	//UART1_u8SendStringBasyW8("data");
	SPI2_vInit();
	UartCommandControl_vIint();
	//GPIO_u8SetPinV_ID(Pin_B7, HIGH);

	while (1) {
		UartCommandControl_vRunnable();
		/*
		 ADC_u8ReadCH(ADC_ch0, &ADC_ReadData);
		 if (ADC_ReadData > 4000) {
		 GPIO_u8SetPinV_ID(Pin_A7, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A6, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A5, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A4, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A3, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);

		 } else if (ADC_ReadData > 3000) {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A5, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A4, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A3, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);
		 } else if (ADC_ReadData > 2500) {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, LOW);
		 GPIO_u8SetPinV_ID(Pin_A5, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A4, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A3, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);
		 } else if (ADC_ReadData > 1500) {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, LOW);
		 GPIO_u8SetPinV_ID(Pin_A5, LOW);
		 GPIO_u8SetPinV_ID(Pin_A4, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A3, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);
		 } else if (ADC_ReadData > 1000) {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, LOW);
		 GPIO_u8SetPinV_ID(Pin_A5, LOW);
		 GPIO_u8SetPinV_ID(Pin_A4, LOW);
		 GPIO_u8SetPinV_ID(Pin_A3, HIGH);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);
		 } else if (ADC_ReadData > 500) {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, LOW);
		 GPIO_u8SetPinV_ID(Pin_A5, LOW);
		 GPIO_u8SetPinV_ID(Pin_A4, LOW);
		 GPIO_u8SetPinV_ID(Pin_A3, LOW);
		 GPIO_u8SetPinV_ID(Pin_A2, HIGH);
		 } else {
		 GPIO_u8SetPinV_ID(Pin_A7, LOW);
		 GPIO_u8SetPinV_ID(Pin_A6, LOW);
		 GPIO_u8SetPinV_ID(Pin_A5, LOW);
		 GPIO_u8SetPinV_ID(Pin_A4, LOW);
		 GPIO_u8SetPinV_ID(Pin_A3, LOW);
		 GPIO_u8SetPinV_ID(Pin_A2, LOW);
		 }
		 */
	}
	return 0;
}
