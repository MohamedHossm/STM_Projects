/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 17/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : I2C                                                      */
/*****************************************************************************/

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

//I2C Control register 1 (I2C_CR1)
#define I2C_SWRST           15
#define I2C_ALERT 			13
#define I2C_PEC   			12
#define I2C_POS   			11
#define I2C_ACK   			10
#define I2C_STOP  			9
#define I2C_START 			8
#define I2C_NO_STRETCH      7
#define I2C_ENGC            6
#define I2C_ENPEC           5
#define I2C_ENARP           4
#define I2C_SMBTYPE         3
#define I2C_SMBU            1
#define I2C_PE              0
/*************************************************************/


/************************************************************/
//I2C Clock control register (I2C_CCR)
#define I2C_F_S  15
/**************************************************************/
//I2C Own address register 1 (I2C_OAR1)
#define I2C_ADD_MODE 15
#define I2C_ADD0      0
/**************************************************************/
//I2C Status register 1 (I2C_SR1)
#define I2C_SMB_ALERT     15
#define I2C_TIME_OUT      14
#define I2C_PECERR   	  13
#define I2C_ERR   		  12
#define I2C_OVR   		  11
#define I2C_AF    		  10
#define I2C_ARLO  		  9
#define I2C_BERR  		  8
#define I2C_TxE   		  7
#define I2C_RxNE  		  6
#define I2C_STOPF		  4
#define I2C_ADD10		  3
#define I2C_BTF  		  2
#define I2C_ADDR 		  1
#define I2C_SB   		  0
/**************************************************************/


#endif //I2C_PRIVATE_H_
