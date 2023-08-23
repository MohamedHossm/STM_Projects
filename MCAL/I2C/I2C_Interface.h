/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 17/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : I2C                                                      */
/*****************************************************************************/
#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
/******************************************************/
typedef struct {
	u32 CR1; /*!< I2C Control register 1,     Address offset: 0x00 */
	u32 CR2; /*!< I2C Control register 2,     Address offset: 0x04 */
	u32 OAR1; /*!< I2C Own address register 1, Address offset: 0x08 */
	u32 OAR2; /*!< I2C Own address register 2, Address offset: 0x0C */
	u32 DR; /*!< I2C Data register,          Address offset: 0x10 */
	u32 SR1; /*!< I2C Status register 1,      Address offset: 0x14 */
	u32 SR2; /*!< I2C Status register 2,      Address offset: 0x18 */
	u32 CCR; /*!< I2C Clock control register, Address offset: 0x1C */
	u32 TRISE; /*!< I2C TRISE register,         Address offset: 0x20 */
} I2C_TypeDef;
#define  I2C_EVENT_MASTER_MODE_SELECT                      ((u32)0x00030001)  /* BUSY, MSL and SB flag */

/**
 * @brief  Address Acknowledge
 *
 * After checking on EV5 (start condition correctly released on the bus), the
 * master sends the address of the slave(s) with which it will communicate
 * (I2C_Send7bitAddress() function, it also determines the direction of the communication:
 * Master transmitter or Receiver). Then the master has to wait that a slave acknowledges
 * his address. If an acknowledge is sent on the bus, one of the following events will
 * be set:
 *
 *  1) In case of Master Receiver (7-bit addressing): the I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED
 *     event is set.
 *
 *  2) In case of Master Transmitter (7-bit addressing): the I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED
 *     is set
 *
 *  3) In case of 10-Bit addressing mode, the master (just after generating the START
 *  and checking on EV5) has to send the header of 10-bit addressing mode (I2C_SendData()
 *  function). Then master should wait on EV9. It means that the 10-bit addressing
 *  header has been correctly sent on the bus. Then master should send the second part of
 *  the 10-bit address (LSB) using the function I2C_Send7bitAddress(). Then master
 *  should wait for event EV6.
 *
 */

/* --EV6 */
#define  I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED        ((u32)0x00070082)  /* BUSY, MSL, ADDR, TXE and TRA flags */
#define  I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED           ((u32)0x00030002)  /* BUSY, MSL and ADDR flags */
/* --EV9 */
#define  I2C_EVENT_MASTER_MODE_ADDRESS10                   ((u32)0x00030008)  /* BUSY, MSL and ADD10 flags */

/**
 * @brief Communication events
 *
 * If a communication is established (START condition generated and slave address
 * acknowledged) then the master has to check on one of the following events for
 * communication procedures:
 *
 * 1) Master Receiver mode: The master has to wait on the event EV7 then to read
 *    the data received from the slave (I2C_ReceiveData() function).
 *
 * 2) Master Transmitter mode: The master has to send data (I2C_SendData()
 *    function) then to wait on event EV8 or EV8_2.
 *    These two events are similar:
 *     - EV8 means that the data has been written in the data register and is
 *       being shifted out.
 *     - EV8_2 means that the data has been physically shifted out and output
 *       on the bus.
 *     In most cases, using EV8 is sufficient for the application.
 *     Using EV8_2 leads to a slower communication but ensure more reliable test.
 *     EV8_2 is also more suitable than EV8 for testing on the last data transmission
 *     (before Stop condition generation).
 *
 *  @note In case the  user software does not guarantee that this event EV7 is
 *  managed before the current byte end of transfer, then user may check on EV7
 *  and BTF flag at the same time (ie. (I2C_EVENT_MASTER_BYTE_RECEIVED | I2C_FLAG_BTF)).
 *  In this case the communication may be slower.
 *
 */

/* Master RECEIVER mode -----------------------------*/
/* --EV7 */
#define  I2C_EVENT_MASTER_BYTE_RECEIVED                    ((u32)0x00030040)  /* BUSY, MSL and RXNE flags */

/* Master TRANSMITTER mode --------------------------*/
/* --EV8 */
#define I2C_EVENT_MASTER_BYTE_TRANSMITTING                 ((u32)0x00070080) /* TRA, BUSY, MSL, TXE flags */
/* --EV8_2 */
#define  I2C_EVENT_MASTER_BYTE_TRANSMITTED                 ((u32)0x00070084)  /* TRA, BUSY, MSL, TXE and BTF flags */

/*========================================

 I2C Slave Events (Events grouped in order of communication)
 ==========================================*/

/**
 * @brief  Communication start events
 *
 * Wait on one of these events at the start of the communication. It means that
 * the I2C peripheral detected a Start condition on the bus (generated by master
 * device) followed by the peripheral address. The peripheral generates an ACK
 * condition on the bus (if the acknowledge feature is enabled through function
 * I2C_AcknowledgeConfig()) and the events listed above are set :
 *
 * 1) In normal case (only one address managed by the slave), when the address
 *   sent by the master matches the own address of the peripheral (configured by
 *   I2C_OwnAddress1 field) the I2C_EVENT_SLAVE_XXX_ADDRESS_MATCHED event is set
 *   (where XXX could be TRANSMITTER or RECEIVER).
 *
 * 2) In case the address sent by the master matches the second address of the
 *   peripheral (configured by the function I2C_OwnAddress2Config() and enabled
 *   by the function I2C_DualAddressCmd()) the events I2C_EVENT_SLAVE_XXX_SECONDADDRESS_MATCHED
 *   (where XXX could be TRANSMITTER or RECEIVER) are set.
 *
 * 3) In case the address sent by the master is General Call (address 0x00) and
 *   if the General Call is enabled for the peripheral (using function I2C_GeneralCallCmd())
 *   the following event is set I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED.
 *
 */

/* --EV1  (all the events below are variants of EV1) */
/* 1) Case of One Single Address managed by the slave */
#define  I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED          ((u32)0x00020002) /* BUSY and ADDR flags */
#define  I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED       ((u32)0x00060082) /* TRA, BUSY, TXE and ADDR flags */

/* 2) Case of Dual address managed by the slave */
#define  I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED    ((u32)0x00820000)  /* DUALF and BUSY flags */
#define  I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED ((u32)0x00860080)  /* DUALF, TRA, BUSY and TXE flags */

/* 3) Case of General Call enabled for the slave */
#define  I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED        ((u32)0x00120000)  /* GENCALL and BUSY flags */

/**
 * @brief  Communication events
 *
 * Wait on one of these events when EV1 has already been checked and:
 *
 * - Slave RECEIVER mode:
 *     - EV2: When the application is expecting a data byte to be received.
 *     - EV4: When the application is expecting the end of the communication: master
 *       sends a stop condition and data transmission is stopped.
 *
 * - Slave Transmitter mode:
 *    - EV3: When a byte has been transmitted by the slave and the application is expecting
 *      the end of the byte transmission. The two events I2C_EVENT_SLAVE_BYTE_TRANSMITTED and
 *      I2C_EVENT_SLAVE_BYTE_TRANSMITTING are similar. The second one can optionally be
 *      used when the user software doesn't guarantee the EV3 is managed before the
 *      current byte end of transfer.
 *    - EV3_2: When the master sends a NACK in order to tell slave that data transmission
 *      shall end (before sending the STOP condition). In this case slave has to stop sending
 *      data bytes and expect a Stop condition on the bus.
 *
 *  @note In case the  user software does not guarantee that the event EV2 is
 *  managed before the current byte end of transfer, then user may check on EV2
 *  and BTF flag at the same time (ie. (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_BTF)).
 * In this case the communication may be slower.
 *
 */

/* Slave RECEIVER mode --------------------------*/
/* --EV2 */
#define  I2C_EVENT_SLAVE_BYTE_RECEIVED                     ((u32)0x00020040)  /* BUSY and RXNE flags */
/* --EV4  */
#define  I2C_EVENT_SLAVE_STOP_DETECTED                     ((u32)0x00000010)  /* STOPF flag */

/* Slave TRANSMITTER mode -----------------------*/
/* --EV3 */
#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTED                  ((u32)0x00060084)  /* TRA, BUSY, TXE and BTF flags */
#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTING                 ((u32)0x00060080)  /* TRA, BUSY and TXE flags */
/* --EV3_2 */
#define  I2C_EVENT_SLAVE_ACK_FAILURE                       ((u32)0x00000400)  /* AF flag */

/*===========================      End of Events Description           ==========================================*/

#define IS_I2C_EVENT(EVENT) (((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_RECEIVED) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_DUALF)) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_GENCALL)) || \
                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_TRANSMITTED) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_DUALF)) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_GENCALL)) || \
                             ((EVENT) == I2C_EVENT_SLAVE_STOP_DETECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_MODE_SELECT) || \
                             ((EVENT) == I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_RECEIVED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTING) || \
                             ((EVENT) == I2C_EVENT_MASTER_MODE_ADDRESS10) || \
                             ((EVENT) == I2C_EVENT_SLAVE_ACK_FAILURE))

/******************************************************/
//#define I2CSTART_DONE I2C1_u8CheckStart()
#define IS_I2C1TX_READY     I2C1_u8CheckTXBuffer()
#define IS_I2C1ADD_MATCH    I2C1_u8CheckAdressMatching()

#define IS_I2C1TX_COMP      I2C1_u8CheckTransferFinished()
#define IS_I2C1RX_COMP      I2C1_u8CheckTransferFinished()

#define IS_I2C1RX_READY     I2C1_u8CheckRXBuffer()
Error_t I2C1_u8Init(void);

Error_t I2C1_u8SetAddress(u16 Copy_u16_I2CAddress);
Error_t I2C1_u8SendByte(u8 Copy_u8SlaveAddress, u8 Copy_u8Data);
Error_t I2C1_u8StartCondition(void);
Error_t I2C1_u8StopCondition(void);

Error_t I2C1_u8ReadStatus(u8 *ptrI2C_CurStatus1, u8 *ptrI2C_CurStatus2);

Error_t I2C1_u8SendData(u8 Copy_u8Data_tx);
Error_t I2C1_u8SendArray(u8 Copy_u8SlaveAddress, u8 *Copy_u8Data,
		u8 Copy_ArraySize);
Error_t I2C1_u8SendStr(u8 Copy_u8SlaveAddress, char *Copy_u8string);

Error_t I2C1_u8ReciveData(u8 *Copy_u8Data_RX);
Error_t I2C1_u8ReceiveByte(u8 Copy_u8SlaveAddress, u8 *Copy_u8Data);

Error_t I2C1_CheckEvent( u32 I2C_EVENT);

u8 I2C1_u8CheckRXBuffer(void);
u8 I2C1_u8CheckTransferFinished(void);
u8 I2C1_u8CheckAdressMatching(void);
u8 I2C1_u8CheckStart(void);
u8 I2C1_u8CheckTXBuffer(void);

#endif //I2C_INTERFACE_H_

