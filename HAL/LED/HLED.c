/*****************************************************************************/
/* Author         : Mohamed Hoasm                                                    */
/* Date           : 16/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : LED                                                             */
/*****************************************************************************/

#include "STD_TYPES.h"

#include "../MCAL/GPIO/GPIO_Interface.h"
#include "HlED.h"

Error_t HLED_Init(); // do noting

Error_t HLED_ON() {
	GPIO_u8SetPinV_ID(LED, HIGH);
	return OK;
}

Error_t HLED_OFF() {
	GPIO_u8SetPinV_ID(LED, LOW);
	return OK;
}
