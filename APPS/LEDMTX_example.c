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

#include "Delay.h"
#include "EXTI_Interface.h"
#include "AFIO_Interface.h"
#include "SYSTICK_Interface.h"
#include "LEDMRX_Interface.h"

u8 IMAGES[8] = {0, 102, 126, 90, 66, 66, 66, 0};
extern GPIO_u8PIN_t LEDMTRLedsColms[8];
extern GPIO_u8PIN_t LEDMTRLedsRows[8];
int main(void) {

	RCC_voidInitSystemClock();
	STK_u8Init();
	NVIC_u8Set_PR_options();

	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);

	GPIO_u8Init();

	while (1) {
		LEDMRX_u8WriteString("Mohamedhossam#",200);
		LEDMRX_u8WriteStringMove("Mohamedhossam#");

	}

	return 0;
}

