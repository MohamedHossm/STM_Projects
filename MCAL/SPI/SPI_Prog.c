/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                                    */
/* Date            : 8/8/2023                                                        */
/* Version         : 1.0                                                              */
/* SW              : SPI                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include "SPI_Conf.h"
#include "SPI_Interface.h"
#include "SPI_Pivate.h"

void SPI2_vInit() {

#if SPI_MODE == SPI_u8MASTER
	// set master
	SET_BIT(SPI2->SPI_CR1, MSTR);
	// set clock
	WRITE_BIT(SPI2->SPI_CR1, BR0, READ_BIT(BAUDRATE,0));
	WRITE_BIT(SPI2->SPI_CR1, BR1, READ_BIT(BAUDRATE,1));
	WRITE_BIT(SPI2->SPI_CR1, BR2, READ_BIT(BAUDRATE,2));

#elif SPI_MODE == SPI_u8SLAVE
	// set slave
	CLR_BIT(SPI2->SPI_CR1, MSTR);
#endif

	// set CK pr
#if SPI_CK_PR == SPI_u8CK_PR_LOW

#elif SPI_CK_PR == SPI_u8CK_PR_HIGH

#endif
	// set Ck phase
	// set mode 8bits , 16 bits
	// set LSB , MSB

	// enable spi

}
