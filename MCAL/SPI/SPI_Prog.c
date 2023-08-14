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

static void (*SPI2_PtrCallBackTX)(void) = NULLPTR;
static void (*SPI2_PtrCallBackRX)(void) = NULLPTR;

void SPI2_vInit(void) {

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
	CLR_BIT(SPI2->SPI_CR1, CPOL);
#elif SPI_CK_PR == SPI_u8CK_PR_HIGH
	SET_BIT(SPI2->SPI_CR1, CPOL);
#endif

	// set Ck phase
#if SPI_CK_PH == SPI_u8CK_PH_LOW
	CLR_BIT(SPI2->SPI_CR1, CPHA);
#elif SPI_CK_PH == SPI_u8CK_PH_HIGH
	SET_BIT(SPI2->SPI_CR1, CPHA);
#endif

	// set mode 8bits , 16 bits
#if SPI_BITMODE == SPI_u8_8_BITMODE
	CLR_BIT(SPI2->SPI_CR1, DFF);
#elif SPI_BITMODE == SPI_u8_16_BITMODE
	SET_BIT(SPI2->SPI_CR1, DFF);
#endif

	// set LSB , MSB
#if SPI_MODE_SEND == SPI_u8_MSB_MODE
	CLR_BIT(SPI2->SPI_CR1, LSBFIRST);
#elif SPI_MODE_SEND == SPI_u8_lSB_MODE
	SET_BIT(SPI2->SPI_CR1, LSBFIRST);
#endif
	// enable spi
	SET_BIT(SPI2->SPI_CR1, SPE);
}

Error_t SPI2_u8SendRecive(u8 copy_u8SendData, u8 *Ptr_u8ReciveData) {
	Error_t local_u8Status = OK;

	SPI2->SPI_DR = copy_u8SendData;
	while (READ_BIT(SPI2->SPI_SR, BSY))
		;
	*Ptr_u8ReciveData = SPI2->SPI_DR;

	return local_u8Status;
}

Error_t SPI2_u8SendBusyW8(u8 copy_u8SendData) {
	Error_t local_u8Status = OK;

	while (READ_BIT(SPI2->SPI_SR, BSY));
	SPI2->SPI_DR = copy_u8SendData;


	return local_u8Status;
}
Error_t SPI2_u8RecieveBusyW8(u8 *PTR_u8RecData) {
	Error_t local_u8Status = OK;
	if (PTR_u8RecData != NULLPTR) {

	while (!READ_BIT(SPI2->SPI_SR,RXNE)){}
		*PTR_u8RecData = SPI2->SPI_DR;
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}

Error_t SPI2_u8RecieveNoBlock(u8 *PTR_u8RecData) {
	Error_t local_u8Status = OK;
	if (PTR_u8RecData != NULLPTR) {
		*PTR_u8RecData = SPI2->SPI_DR;
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;

}
Error_t SPI2_u8SendString(u8 *PTR_u8StringData){
	Error_t local_u8Status = OK;

	for(u8 index = 0 ; PTR_u8StringData[index] ; index ++ ){
	SPI2_u8SendBusyW8(PTR_u8StringData[index]);
}
	return local_u8Status;

}
Error_t SPI2_u8SendNumString(u32 copy_u32num) {
	Error_t local_u8Status = OK;
	u8 local_String[10];
	s8 index;
	for (index = 0; copy_u32num; index++) {
		local_String[index] = copy_u32num % 10 + '0';
		copy_u32num /= 10;
	}
	index--;
	for (; index >= 0; index--) {
		SPI2_u8SendBusyW8(local_String[index]);
	}

	return local_u8Status;

}

Error_t SPI2_u8CallBack_IRQ_TX(void (*CopyFun)(void)) {
	Error_t local_u8Status = OK;
	if (*CopyFun != NULLPTR) {

		SPI2_PtrCallBackTX = CopyFun;
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}
Error_t SPI2_u8CallBack_IRQ_RX(void (*CopyFun)(void)) {
	Error_t local_u8Status = OK;
	if (*CopyFun != NULLPTR) {
		SPI2_PtrCallBackRX = CopyFun;

	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}

void SPI2_vInterruptEnRX() {
	SET_BIT(SPI2->SPI_CR2, RXNEIE);
}
void SPI2_vInterruptDSRX() {
	CLR_BIT(SPI2->SPI_CR2, RXNEIE);

}
void SPI2_vInterruptEnTX() {
	SET_BIT(SPI2->SPI_CR2, TXEIE);
}
void SPI2_vInterruptDSTX() {
	CLR_BIT(SPI2->SPI_CR2, TXEIE);
}

void SPI2_IRQHandler(void){

	if (READ_BIT(SPI2->SPI_SR,TXE)){
		//SPI2_PtrCallBackTX() ;
	}
	if(READ_BIT(SPI2->SPI_SR,RXNE)) {
		//SPI2_PtrCallBackRX() ;
	}

}
