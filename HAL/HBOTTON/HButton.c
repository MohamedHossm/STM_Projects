/*************************************************************************************/
/* Author         : Mohamed Hoasm                                                    */
/* Date           : 16/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : Button                                                           */
/*************************************************************************************/
#include "STD_TYPES.h"

#include "GPIO_Interface.h"
#include "HButton.h"

Error_t HBUTTON_u8Init() {
 // do nothing
	return OK ;
}

Error_t HBUTTON_u8GetRead(u8* ptr_ReturnValue) {
	u8 Local_u8State = OK ;
	Local_u8State =	GPIO_u8GetPinV_ID(Pin_B0,ptr_ReturnValue);
return Local_u8State ;
}
