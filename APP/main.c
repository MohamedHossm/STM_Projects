/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 17/8/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : I2C                                                          */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "Delay.h"
#include "RCC_Interface.h"

#include "SYSTICK_Interface.h"
#include "GPIO_Interface.h"
#include "I2C_Interface.h"

int main(void) {

	//enable RCC 8-MHz

	RCC_voidInitSystemClock();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	// enable I2C clock
	RCC_voidEnablePeriphralCLK(APB1_I2C1EN);
	//gpoi init
	GPIO_u8Init();

	I2C1_u8Init();
// address <<1  // 0x20
	// address + 1
	u8 Copy_u8Data = 0x0;
I2C1_u8ReceiveByte(0x0B, &Copy_u8Data);
GPIO_u8SetPinV_ID(Pin_B10, HIGH);
Copy_u8Data =Copy_u8Data<<1;
I2C1_u8SendArray(0x0B, &Copy_u8Data,1);
GPIO_u8SetPinV_ID(Pin_B11, HIGH);
;

	while (1) {

	}
	return 0;
}
