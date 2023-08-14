/*
 * SpiStrings.h
 *
 * Created: 8/10/2023 2:27:46 PM
 *  Author: Amm
 */ 


#ifndef SPISTRINGS_H_
#define SPISTRINGS_H_

#define SPI_StringsS_CALLBACK_SIZE 4
#define SPI_StringsS_FRAME_SIZE 20
#define SPI_StringsS_STR_SIZE   20
#define SPI_StringsS_ENDFRAM '#'

void SPI_StringsS_Init ();
void SPI_StringsS_Runnable(void);
u8 SPI_StringsS_IsDataReady(void);
void SPI_StringsS_GETdata(u8 *SPI_StringsSptrStr, u16 *SPI_StringsSptrNum);
void SPI_StringsSISRFun();

#endif /* SPISTRINGS_H_ */