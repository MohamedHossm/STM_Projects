/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 17/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : I2C                                                      */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include "I2C_Conf.h"
#include "I2C_Private.h"
#include "I2C_Interface.h"


#define FLAG_Mask               ((u32)0x00FFFFFF)


Error_t I2C1_u8Init(void) {
	Error_t Local_u8Status = OK;
	// Reset I2C
	SET_BIT(I2C1->I2C_CR1, I2C_SWRST);
	CLR_BIT(I2C1->I2C_CR1, I2C_SWRST);

	// Program the peripheral input clock
	I2C1->I2C_CR2 &= (~(0b111111));
	I2C1->I2C_CR2 |= I2C_Priphral_CLK;
	//Configure the clock control registers
	CLR_BIT(I2C1->I2C_CCR, I2C_F_S);
	I2C1->I2C_CCR &= ~(0b11111111111);
	I2C1->I2C_CCR |= I2C_CCR_CLK;
	//Configure the rise time register
	I2C1->I2C_TRISE = I2C_TRISE_CLK;
	//Slave Address
	I2C1_u8SetAddress(I2C_SlAVE_ADD);
	//Program the I2C_CR1 register to enable the peripheral
	SET_BIT(I2C1->I2C_CR1, I2C_PE);
	//Config I2C options
	//1- enable Ack
	//SET_BIT(I2C1->I2C_CR1, I2C_ACK);
	//-------------------------------------------------

	return Local_u8Status;
}
Error_t I2C1_CheckEvent(u32 I2C_EVENT) {
	u32 lastevent = 0;
	u32 flag1 = 0, flag2 = 0;
	Error_t status = NOK;

	/* Read the I2Cx status register */
	flag1 = I2C1->I2C_SR1;
	flag2 = I2C1->I2C_SR2;
	flag2 = flag2 << 16;

	/* Get the last event value from I2C status register */
	lastevent = (flag1 | flag2) & FLAG_Mask;

	/* Check whether the last event contains the I2C_EVENT */
	if ((lastevent & I2C_EVENT) == I2C_EVENT) {
		/* SUCCESS: last event is equal to I2C_EVENT */
		status = OK;
	} else {
		/* ERROR: last event is different from I2C_EVENT */
		status = NOK;
	}
	/* Return status */
	return status;
}
Error_t I2C1_u8SetAddress(u16 Copy_u16_I2CAddress) {
	Error_t Local_u8Status = OK;
// 7-bits configration
	CLR_BIT(I2C1->I2C_OAR1, I2C_ADD_MODE);
	//set address
	I2C1->I2C_OAR1 &= (~(0b1111111) << 1);
	I2C1->I2C_OAR1 |= ((Copy_u16_I2CAddress) << 1);
	return Local_u8Status;
}
Error_t I2C1_u8StartCondition() {
	Error_t Local_u8Status = OK;
	//1- enable Ack
	SET_BIT(I2C1->I2C_CR1, I2C_ACK);
	// Generate  Start condition
	SET_BIT(I2C1->I2C_CR1, I2C_START);
	return Local_u8Status;

}
Error_t I2C1_u8StopCondition(void) {
	Error_t Local_u8Status = OK;
	SET_BIT(I2C1->I2C_CR1, I2C_STOP);
	return Local_u8Status;
}
Error_t I2C1_u8SendData(u8 Copy_u8Data_tx) {
	Error_t Local_u8Status = OK;
	I2C1->I2C_DR = Copy_u8Data_tx;
	return Local_u8Status;
}
Error_t I2C1_u8ReciveData(u8 *Copy_u8Data_RX) {
	Error_t Local_u8Status = OK;
	*Copy_u8Data_RX = I2C1->I2C_DR;
	return Local_u8Status;
}

// send Byte function
Error_t I2C1_u8SendByte(u8 Copy_u8SlaveAddress, u8 Copy_u8Data) {
	Error_t Local_u8Status = OK;

	I2C1_u8StartCondition();

	//send address no  thing to check
	I2C1_u8SendData(Copy_u8SlaveAddress << 1);

	//wait for address matching
	while (IS_I2C1ADD_MATCH)
		;

	// need to clear SR1 & SR2 by reading them
	u8 Local_u8status1, Local_u8status2;
	I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);

	// check tx buffer
	while (IS_I2C1TX_READY)
		;
	I2C1_u8SendData(Copy_u8Data);
	// wait for tx transfer finished
	while (IS_I2C1TX_COMP)
		;

	I2C1_u8StopCondition();
	return Local_u8Status;

}

// send Array function
Error_t I2C1_u8SendArray(u8 Copy_u8SlaveAddress, u8 *Copy_u8Data,
		u8 Copy_ArraySize) {
	Error_t Local_u8Status = OK;

	I2C1_u8StartCondition();

//send address no  thing to check
	I2C1_u8SendData(Copy_u8SlaveAddress << 1);

//wait for address matching
	while (IS_I2C1ADD_MATCH)
		;

// need to clear SR1 & SR2 by reading them
	u8 Local_u8status1, Local_u8status2;
	I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);
	for (u8 local_indexDataSend = 0; local_indexDataSend < Copy_ArraySize;
			local_indexDataSend++) {
// check tx buffer
		while (IS_I2C1TX_READY)
			;
		I2C1_u8SendData(Copy_u8Data[local_indexDataSend]);
// wait for tx transfer finished
		while (IS_I2C1TX_COMP)
			;
	}
	I2C1_u8StopCondition();
	return Local_u8Status;

}
// send string function
Error_t I2C1_u8SendStr(u8 Copy_u8SlaveAddress, char *Copy_u8string) {
	Error_t Local_u8Status = OK;

	I2C1_u8StartCondition();

//send address no  thing to check
	I2C1_u8SendData(Copy_u8SlaveAddress << 1);

//wait for address matching
	while (IS_I2C1ADD_MATCH)
		;

// need to clear SR1 & SR2 by reading them
	u8 Local_u8status1, Local_u8status2;
	I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);
	for (u8 local_indexDataSend = 0; Copy_u8string[local_indexDataSend];
			local_indexDataSend++) {
// check tx buffer
		while (IS_I2C1TX_READY)
			;
		I2C1_u8SendData(Copy_u8string[local_indexDataSend]);
// wait for tx transfer finished
		while (IS_I2C1TX_COMP)
			;
	}
	I2C1_u8StopCondition();
	return Local_u8Status;

}
/*
 Error_t I2C1_u8ReceiveByte(u8 Copy_u8SlaveAddress, u8 *Copy_u8Data) {
 Error_t Local_u8Status = OK;
 u32 timeout = TIMEOUT ;
 u8 Local_u8status1, Local_u8status2;
 I2C1_u8StartCondition();
 //read status Registers
 I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);

 //disable I2C Ack
 //CLR_BIT(I2C1->I2C_CR1, I2C_ACK);

 //send address no  thing to check
 I2C1_u8SendData((Copy_u8SlaveAddress << 1) | 1);

 //wait for address matching
 while (IS_I2C1ADD_MATCH)
 ;
 // need to clear SR1 & SR2 by reading them
 I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);
 //I2C1_u8ReciveData(&Local_u8status1);
 while ( !I2C1_CheckEvent( I2C_EVENT_MASTER_BYTE_RECEIVED)){
 if (--timeout == 0 ){
 return NOK ;
 }
 }
 I2C1_u8ReciveData(&Local_u8status1);
 I2C1_u8StopCondition();

 return Local_u8Status;
 }
 */
Error_t I2C1_u8ReceiveByte(u8 Copy_u8SlaveAddress, u8 *Copy_u8Data) {
	Error_t Local_u8Status = OK;
	u8 Local_u8status1, Local_u8status2;

	//start condition
	I2C1_u8StartCondition();

	//send address nothing to check
	I2C1_u8SendData((Copy_u8SlaveAddress << 1) +1);

	//wait for address matching
	while (IS_I2C1ADD_MATCH) {
	}

	// need to clear SR1 & SR2 by reading them
	I2C1_u8ReadStatus(&Local_u8status1, &Local_u8status2);

	while (IS_I2C1RX_READY) {
	}
	//read Data
	I2C1_u8ReciveData(Copy_u8Data);
	while (!IS_I2C1RX_READY) {
		}
	//disable ack
	CLR_BIT(I2C1->I2C_CR1, I2C_ACK);
	I2C1_u8StopCondition();

	//enable ACK
	SET_BIT(I2C1->I2C_CR1, I2C_ACK);

	return Local_u8Status;
}

u8 I2C1_u8CheckRXBuffer(void) {
	return !READ_BIT(I2C1->I2C_SR1, I2C_RxNE);
}
u8 I2C1_u8CheckTXBuffer(void) {
	return !READ_BIT(I2C1->I2C_SR1, I2C_TxE);
}

u8 I2C1_u8CheckTransferFinished(void) {
	return !READ_BIT(I2C1->I2C_SR1, I2C_BTF);
}

u8 I2C1_u8CheckAdressMatching(void) {
	return !READ_BIT(I2C1->I2C_SR1, I2C_ADDR);
}

/*
 u8 I2C1_u8CheckStart() {
 return !READ_BIT(I2C1->I2C_SR1, I2C_SB);
 }
 */

Error_t I2C1_u8ReadStatus(u8 *ptrI2C_CurStatus1, u8 *ptrI2C_CurStatus2) {
	Error_t Local_u8Status = OK;
	*ptrI2C_CurStatus1 = I2C1->I2C_SR1;
	*ptrI2C_CurStatus2 = I2C1->I2C_SR2;
	return Local_u8Status;
}
Error_t I2C1_u8Interrupt_EN() {
	Error_t Local_u8Status = OK;

	return Local_u8Status;
}
Error_t I2C1_u8Interrupt_DIS() {
	Error_t Local_u8Status = OK;

	return Local_u8Status;
}
