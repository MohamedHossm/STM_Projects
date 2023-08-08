/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                                    */
/* Date            : 8/8/2023                                                        */
/* Version         : 1.0                                                              */
/* SW              : SPI                                                             */
/*****************************************************************************/

#ifndef SPI_CONF_H_
#define SPI_CONF_H_


/* -----options-------
 * SPI_u8MASTER
 * SPI_u8SLAVE
 * */
#define SPI_MODE      SPI_u8MASTER


/* -----options-------
 * SPI_u8CK_PR_HIGH
 * SPI_u8CK_PR_LOW
 * */
#define SPI_CK_PR      SPI_u8CK_PR_LOW

/* -----options-------
 * SPI_u8CK_PH_LOW
 * SPI_u8CK_PH_HIGH
 * */

#define SPI_CK_PH     SPI_u8CK_PH_LOW

/* -----options-------
 * SPI_u8_8_BITMODE
 * SPI_u8_16_BITMODE
*/
#define SPI_BITMODE     SPI_u8_8_BITMODE

/* -----options-------
 * SPI_u8_lSB_MODE
 * SPI_u8_MSB_MODE
 */

#define SPI_MODE_SEND   SPI_u8_MSB_MODE

/* -----options-------
 *  SPI_F_2  = 000 ,
	SPI_F_4 ,
	SPI_F_8 ,
	SPI_F_16 ,
	SPI_F_32 ,
	SPI_F_64 ,
	SPI_F_128 ,
	SPI_F_256 ,
 * */
#define BAUDRATE  SPI_F_16

#endif //SPI_CONF_H_
