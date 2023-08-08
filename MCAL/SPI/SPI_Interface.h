/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                                    */
/* Date            : 8/8/2023                                                        */
/* Version         : 1.0                                                              */
/* SW              : SPI                                                             */
/*****************************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

typedef enum {
	SPI_F_2  = 0 ,
	SPI_F_4 ,
	SPI_F_8 ,
	SPI_F_16 ,
	SPI_F_32 ,
	SPI_F_64 ,
	SPI_F_128 ,
	SPI_F_256 ,

}SPI_Prescaler_t;


void SPI2_vInit(void) ;
Error_t SPI2_u8Send (u8 copy_u8SendData  );
Error_t SPI2_u8SendRecive (u8 copy_u8SendData ,u8* Ptr_u8ReciveData );
#endif //SPI_INTERFACE_H_

