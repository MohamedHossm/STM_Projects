/*************************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 26/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : LEDMRX                                                           */
/*************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Delay.h"
#include "SYSTICK_Interface.h"
#include"GPIO_Interface.h"
#include"LEDMRX_Conf.h"
#include"LEDMRX_Pivate.h"
#include"LEDMRX_Interface.h"
#include "math.h"
extern GPIO_u8PIN_t LEDMTRLedsColms[LEDS_COLNUM];
extern GPIO_u8PIN_t LEDMTRLedsRows[LEDS_ROWNUM];
const LED_MRX_CONTANER_t LEDMRX_letters[LEDMRX_lettersSIZE];

void LEDMRX_Init() {
	// do nothing 
}

 Error_t Search(char charcter, s16 *index) {
	Error_t local_u8Status = OK;
	if (charcter >= 'a' && charcter <= 'z') {
		charcter = charcter - ('a' - 'A');
	} else if (charcter >= 'A' && charcter <= 'Z') {

	} else {
		local_u8Status = NOK;
	}
	if (local_u8Status == OK) {
		for (u8 i = 0; i < LEDMRX_lettersSIZE; i++) {
			if (LEDMRX_letters[i].search == charcter) {
				*index = i;
				local_u8Status = OK;
				break;
			} else {
				local_u8Status = NOK;
			}
		}
	}
	return local_u8Status;

}
u8 pow2(u8 index) {
	u8 returnval = 0;
	for (u8 i = 0; i < index; i++) {
		returnval |= (1 << index);
	}
	return returnval;
}
 void LEDMRX_voidCopyvalue(const u8 Source[], u8 distination[], s8 index) {
	u8 Signflage = 0;
	if (index < 0) {
		index = index * (-1);
		Signflage = 1;
	}
	for (u8 i = 0; i < LEDMRXCOLSIZE; i++) {

		distination[i] = Source[i];
		//distination[i] = (distination[i] << 1);
		if (Signflage) {
			distination[i] = (distination[i] >> (index));
		} else {
			distination[i] = (distination[i] << index);
		}
	}

}

Error_t LEDMRX_u8WriteStringMove(char *string , u16 Rating) {
	Error_t local_u8Status = OK;
	//u8 rebeat = 0;
	s16 returnindex = 0;
	u8 DisValue[8] = { 0 };
	for (u16 index = 0; string[index]; index++) {
		//rebeat = RETING;
		if (Search(string[index], &returnindex) == OK) {

			for (s8 i = -5; i < LEDMRXCOLSIZE; i++) {
				for (u8 j = 0; j < Rating; j++) {
					LEDMRX_voidCopyvalue(LEDMRX_letters[returnindex].arr,
							DisValue, i);
					LEDMRX_u8Display(DisValue);
				}
			}
		} else {
			for (s8 i = -5; i < LEDMRXCOLSIZE; i++) {
				for (u8 j = 0; j < Rating; j++) {
					LEDMRX_voidCopyvalue(LEDMRX_letters[LEDMRXEROR].arr,
							DisValue, i);
					LEDMRX_u8Display(DisValue);
				}
			}
		}
	}
	//Delay(500);

	return local_u8Status;
}

Error_t LEDMRX_u8WriteString(char *string, u16 rating) {
	Error_t local_u8Status = OK;
	u8 rebeat = 0;
	s16 returnindex = 0;
	for (u16 index = 0; string[index]; index++) {
		rebeat = rating;
		if (Search(string[index], &returnindex) == OK) {
			for (; rebeat > 0; rebeat--) {
				LEDMRX_u8Display((u8*) LEDMRX_letters[returnindex].arr);
			}
		} else {
			for (; rebeat > 0; rebeat--) {
				LEDMRX_u8Display((u8*) LEDMRX_letters[LEDMRXEROR].arr);
			}
			//STK_u8SetBusyWait(250000);
		}
		//Delay(500);
	}
	return local_u8Status;
}

Error_t LEDMRX_u8Display(u8 arr_MRXvalue[]) {
	/* write low on all led matrix COLS */
	for (u8 i = 0; i < LEDMRXCOLSIZE; i++) {
		GPIO_u8SetPinV_ID(LEDMTRLedsColms[i], HIGH);
	}
	/* write high on all led matrix ROWS */
	for (u8 i = 0; i < LEDMRXROWSIZE; i++) {
		GPIO_u8SetPinV_ID(LEDMTRLedsRows[i], LOW);
	}
//******************************************
	for (u8 i = 0; i < LEDMRXCOLSIZE; i++) {
		for (u8 j = 0; j < LEDMRXROWSIZE; j++) {
			// i --> COLSS
			// j --> ROWS all iteration select value
			// read bit value and out on row array
			GPIO_u8SetPinV_ID(LEDMTRLedsRows[j], READ_BIT(arr_MRXvalue[i], j));
			/*
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[1],HIGH );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[2], HIGH );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[3],HIGH );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[4],HIGH  );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[5], HIGH );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[6],HIGH  );
			 GPIO_u8SetPinV_ID(LEDMTRLedsRows[7], HIGH );
			 */
		}
		if (i == 0) {
			GPIO_u8SetPinV_ID(LEDMTRLedsColms[i], LOW);
		} else {
			// set prev high and clr curr
			GPIO_u8SetPinV_ID(LEDMTRLedsColms[i - 1], HIGH);
			GPIO_u8SetPinV_ID(LEDMTRLedsColms[i], LOW);
			//STK_u8SetBusyWait(3);
			Delay(3);
		}
		GPIO_u8SetPinV_ID(LEDMTRLedsColms[i], HIGH);
	}
	return OK;
}
