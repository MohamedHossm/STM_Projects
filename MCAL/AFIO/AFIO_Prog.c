/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 24/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : AFIO                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include"AFIO_Conf.h"
#include"AFIO_Pivate.h"
#include"AFIO_Interface.h"

Error_t AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line_t Copy_u8Line,
		AFIO_Cont_ISQ_PORT_t Copy_u8Port)
{
	Error_t local_u8Status = OK ;
	u8 local_u8index = 0 ;
	if (Copy_u8Line< AFIO_Cont_ISQ_TOTAL){
		local_u8index = Copy_u8Line / AFIO_u8SIZE_PIN ;
		Copy_u8Line  = Copy_u8Line % AFIO_u8SIZE_PIN ;
		//clr 4bits for configuration
		AFIO->AFIO_EXTICR[local_u8index] &=~ ((0b1111)<< Copy_u8Line*AFIO_u8SIZE_PIN) ;
		AFIO->AFIO_EXTICR[local_u8index] |= (( Copy_u8Line&0x0f)*AFIO_u8SIZE_PIN) ;

	}else {
		local_u8Status = NOK ;
	}
return local_u8Status ;
}
