/*
* SpiStrings.c
*
* Created: 8/10/2023 2:27:26 PM
*  Author: Amm
*/
#include "StdTypes.h"
#include "Utils.h"
#include "SPI.h"
#include "SpiStrings.h"


static volatile u8 SPI_StringsS_u8GlobalFrame[SPI_StringsS_FRAME_SIZE] = { 0 };
static volatile u8 SPI_StringsS_u8index = 0;
static volatile u8 SPI_StringsS_u8EndFrameRecieved = 0;

static char SPI_StringsS_StringRX[SPI_StringsS_STR_SIZE] = { 0 };
static u16 SPI_StringsS_MUNRX = 0;

static u8 SPI_StringsS_DataReady = 0;


void separate_string() {
	u8 i, j = 0;
	for (i = 0;
	SPI_StringsS_u8GlobalFrame[i] != '#' && SPI_StringsS_u8GlobalFrame[i] != ' '
	&& i < SPI_StringsS_FRAME_SIZE; i++) {
		if (SPI_StringsS_u8GlobalFrame[i] >= 'a' && SPI_StringsS_u8GlobalFrame[i] <= 'z') {
			SPI_StringsS_StringRX[j] = SPI_StringsS_u8GlobalFrame[i];
			j++;
		}
	}
	SPI_StringsS_StringRX[j] = 0;
	SPI_StringsS_MUNRX = 0;
	for (; SPI_StringsS_u8GlobalFrame[i] != '#' && i < SPI_StringsS_FRAME_SIZE; i++) {
		if (SPI_StringsS_u8GlobalFrame[i] >= '0' && SPI_StringsS_u8GlobalFrame[i] <= '9') {
			SPI_StringsS_MUNRX = (SPI_StringsS_MUNRX * 10) + (SPI_StringsS_u8GlobalFrame[i] - '0');
		}
	}
}

void SPI_StringsS_Init (){
	SPI_Interrupt_CAll_Back(&SPI_StringsSISRFun);
}
void SPI_StringsS_Runnable(void) {
	if (SPI_StringsS_u8EndFrameRecieved) {

		separate_string();
		SPI_StringsS_DataReady = 1;
		SPI_StringsS_u8EndFrameRecieved = 0;
		SPI_StringsS_u8index = 0;
		} else {
		//do nothing
	}

}

u8 SPI_StringsS_IsDataReady(void) {
	return SPI_StringsS_DataReady;
}

void SPI_StringsS_GETdata(u8 *SPI_StringsSptrStr, u16 *SPI_StringsSptrNum) {
	u8 index = 0;
	*SPI_StringsSptrNum = SPI_StringsS_MUNRX;
	for (; SPI_StringsS_StringRX[index]; index++) {
		SPI_StringsSptrStr[index] = SPI_StringsS_StringRX[index];
		SPI_StringsS_StringRX[index] = 0;
	}
	SPI_StringsSptrStr[index] = 0;
	SPI_StringsS_MUNRX = 0;
	SPI_StringsS_DataReady = 0;
}

void SPI_StringsSISRFun(){
	SPI_StringsS_u8GlobalFrame[SPI_StringsS_u8index]=SPI_Recive_NOblock(); //-
	if (SPI_StringsS_u8GlobalFrame[SPI_StringsS_u8index] == SPI_StringsS_ENDFRAM
	|| SPI_StringsS_u8index == SPI_StringsS_FRAME_SIZE - 1) {
		SPI_StringsS_u8EndFrameRecieved = 1;
	}
	if (SPI_StringsS_u8index < SPI_StringsS_FRAME_SIZE - 1) {
		SPI_StringsS_u8index++;
		} else {
		// do nothing
	}
}