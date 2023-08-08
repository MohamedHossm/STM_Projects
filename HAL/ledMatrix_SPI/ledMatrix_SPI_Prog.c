/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                             */
/* Date            : 8/8/2023                                                  */
/* Version         : 1.0                                                       */
/* SW              : ledMatrix_SPI                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"

#include "GPIO_Interface.h"
#include "SPI_Interface.h"
#include "Delay.h"
//#include "SYSTICK_Interface.h"

#include "ledMatrix_SPI_Conf.h"
#include "ledMatrix_SPI_Interface.h"
#include "ledMatrix_SPI_Pivate.h"

static GPIO_u8PIN_t Global_u8ControlPin = PINTOTAL;

void ledMatrix_SPI_vInit(GPIO_u8PIN_t Copy_u8ControlPin) {

	Global_u8ControlPin = Copy_u8ControlPin;
	ledMatrix_SPI_u8SendData(ledMatrix_SPI_SCANLIMIT, 0x07); // Display all 8 digits
	ledMatrix_SPI_u8SendData(ledMatrix_SPI_DECODEMODE, 0x00); // Use matrix (not digits) decoding
	ledMatrix_SPI_u8SendData(LedMatrix_SPI_DISPLAYTEST, 0x00); // Disable display test mode
	ledMatrix_SPI_u8SendData(ledMatrix_SPI_SHUTDOWN, 0x01); // Enable the chip
	ledMatrix_SPI_u8SendData(ledMatrix_SPI_INTENSITY, 0x08); // Set the brightness (0x00 - 0x0F)

}

Error_t ledMatrix_SPI_u8SendData(u8 Copy_u8LedMatrixAddress,
		u8 Copy_u8LedMatrixData) {

	Error_t Local_u8Status = OK;

	GPIO_u8SetPinV_ID(Global_u8ControlPin, LOW);
	SPI2_u8Send(Copy_u8LedMatrixAddress);
	SPI2_u8Send(Copy_u8LedMatrixData);
	GPIO_u8SetPinV_ID(Global_u8ControlPin, HIGH);

	return Local_u8Status;

}
Error_t ledMatrix_SPI_u8SendPattern(u8 *PTR_u8_2DLedMatrixData) {

	Error_t Local_u8Status = OK;
	for (u8 indexColms = 1; indexColms < ledMatrix_SPI_COLS + 1; indexColms++) {
		ledMatrix_SPI_u8SendData(indexColms,
				PTR_u8_2DLedMatrixData[indexColms]);
	}

	return Local_u8Status;

}
Error_t ledMatrix_SPI_u8SendSequance(
		u8 PTR_u8_2DLedMatrixData[][ledMatrix_SPI_COLS],
		u8 Copy_u8_LedMatrixSize, u32 Copy_u8_LedMatrixDelay) {

	Error_t Local_u8Status = OK;
	for (u8 indexArray = 0; indexArray < Copy_u8_LedMatrixSize; indexArray++) {
		for (u8 indexColms = 1; indexColms < ledMatrix_SPI_COLS + 1;
				indexColms++) {
			ledMatrix_SPI_u8SendData(indexColms,
					PTR_u8_2DLedMatrixData[indexArray][indexColms]);
		}
		Delay(Copy_u8_LedMatrixDelay);

	}

	return Local_u8Status;

}
