/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 17/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : I2C                                                      */
/*****************************************************************************/

#ifndef I2C_CONF_H_
#define I2C_CONF_H_

/**
 *
 0b000000: Not allowed
 0b000001: Not allowed
 0b000010: 2 MHz
 ...
 0b110010: 50 MHz
 */
#define I2C_Priphral_CLK  0x8                          //8MZ
#define I2C_CCR_CLK       0x28                        // 8MZ
#define I2C_TRISE_CLK     9                          // 8MZ
#define I2C_SlAVE_ADD     0x05
#endif //I2C_CONF_H_
