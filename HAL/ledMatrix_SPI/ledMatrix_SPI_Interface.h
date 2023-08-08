/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                             */
/* Date            : 8/8/2023                                                  */
/* Version         : 1.0                                                       */
/* SW              : ledMatrix_SPI                                                             */
/*****************************************************************************/
#ifndef ledMatrix_SPI_INTERFACE_H_
#define ledMatrix_SPI_INTERFACE_H_

#define ledMatrix_SPI_NOP          0x00
#define ledMatrix_SPI_DIGIT0       0x01
#define ledMatrix_SPI_DIGIT1       0x02
#define ledMatrix_SPI_DIGIT2       0x03
#define ledMatrix_SPI_DIGIT3       0x04
#define ledMatrix_SPI_DIGIT4       0x05
#define ledMatrix_SPI_DIGIT5       0x06
#define ledMatrix_SPI_DIGIT6       0x07
#define ledMatrix_SPI_DIGIT7       0x08
#define ledMatrix_SPI_DECODEMODE   0x09
#define ledMatrix_SPI_INTENSITY    0x0A
#define ledMatrix_SPI_SCANLIMIT    0x0B
#define ledMatrix_SPI_SHUTDOWN     0x0C
#define LedMatrix_SPI_DISPLAYTEST  0x0F

#define ledMatrix_SPI_COLS   8
#define ledMatrix_SPI_ROWS   8

Error_t ledMatrix_SPI_u8SendData(u8 Copy_u8LedMatrixAddress,
		u8 Copy_u8LedMatrixData);
void ledMatrix_SPI_vInit(GPIO_u8PIN_t Copy_u8ControlPin);
Error_t ledMatrix_SPI_u8SendPattern(u8 *PTR_u8_2DLedMatrixData);
Error_t ledMatrix_SPI_u8SendSequance(
		u8 PTR_u8_2DLedMatrixData[][ledMatrix_SPI_COLS],
		u8 Copy_u8_LedMatrixSize, u32 Copy_u8_LedMatrixDelay);
#endif //ledMatrix_SPI_INTERFACE_H_

