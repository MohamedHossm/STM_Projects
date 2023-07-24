/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 24/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : EXTI                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include"EXTI_Conf.h"
#include"EXTI_Pivate.h"
#include"EXTI_Interface.h"

Error_t EXTI_u8Iint(void) {
	#if LINE_0 
	SET_BIT(EXTI->EXTI_IMR,LINE_0) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_0) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_0) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_0) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_0) ;
	#endif // LINE_0
#endif // if LINE_0

#if LINE_1 
	SET_BIT(EXTI->EXTI_IMR,LINE_1) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_1) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_1) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_1) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_1) ;
	#endif // LINE_1
#endif // if LINE_1

#if LINE_2 
	SET_BIT(EXTI->EXTI_IMR,LINE_2) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_2) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_2) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_2) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_2) ;
	#endif // LINE_2
#endif // if LINE_2

#if LINE_3 
	SET_BIT(EXTI->EXTI_IMR,LINE_3) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_3) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_3) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_3) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_3) ;
	#endif // LINE_3
#endif // if LINE_3

#if LINE_4 
	SET_BIT(EXTI->EXTI_IMR,LINE_4) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_4) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_4) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_4) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_4) ;
	#endif // LINE_4
#endif // if LINE_4

#if LINE_5 
	SET_BIT(EXTI->EXTI_IMR,LINE_5) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_5) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_5) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_5) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_5) ;
	#endif // LINE_5
#endif // if LINE_5

#if LINE_6 
	SET_BIT(EXTI->EXTI_IMR,LINE_6) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_6) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_6) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_6) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_6) ;
	#endif // LINE_6
#endif // if LINE_6

#if LINE_7 
	SET_BIT(EXTI->EXTI_IMR,LINE_7) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_7) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_7) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_7) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_7) ;
	#endif // LINE_7
#endif // if LINE_7

#if LINE_8 
	SET_BIT(EXTI->EXTI_IMR,LINE_8) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_8) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_8) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_8) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_8) ;
	#endif // LINE_8
#endif // if LINE_8

#if LINE_9 
	SET_BIT(EXTI->EXTI_IMR,LINE_9) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_9) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_9) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_9) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_9) ;
	#endif // LINE_9
#endif // if LINE_9

#if LINE_10 
	SET_BIT(EXTI->EXTI_IMR,LINE_10) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_10) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_10) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_10) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_10) ;
	#endif // LINE_10
#endif // if LINE_10

#if LINE_11 
	SET_BIT(EXTI->EXTI_IMR,LINE_11) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_11) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_11) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_11) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_11) ;
	#endif // LINE_11
#endif // if LINE_11

#if LINE_12 
	SET_BIT(EXTI->EXTI_IMR,LINE_12) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_12) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_12) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_12) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_12) ;
	#endif // LINE_12
#endif // if LINE_12

#if LINE_13 
	SET_BIT(EXTI->EXTI_IMR,LINE_13) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_13) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_13) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_13) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_13) ;
	#endif // LINE_13
#endif // if LINE_13

#if LINE_14 
	SET_BIT(EXTI->EXTI_IMR,LINE_14) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_14) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_14) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_14) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_14) ;
	#endif // LINE_14
#endif // if LINE_14

#if LINE_15 
	SET_BIT(EXTI->EXTI_IMR,LINE_15) ;
	#if STATE == PRE_FAILING
	SET_BIT(EXTI->EXTI_FTSR,LINE_15) ;
	#elif STATE == PRE_RISING
	SET_BIT(EXTI->EXTI_RTSR,LINE_15) ;
	#elif STATE == PRE_FAILING_RISING
	SET_BIT(EXTI->EXTI_FTSR,LINE_15) ;
    SET_BIT(EXTI->EXTI_RTSR,LINE_15) ;
	#endif // LINE_15
#endif // if LINE_15
}

Error_t EXTI_u8En(EXTI_Line_t copy_u8Line) {
	Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		SET_BIT(EXTI->EXTI_IMR,copy_u8Line) ;
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 
}

Error_t EXTI_u8Ds(EXTI_Line_t copy_u8Line) {
	
	Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		CLR_BIT(EXTI->EXTI_IMR,copy_u8Line) ;
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 
}
Error_t EXTI_u8SW_interrupt(EXTI_Line_t copy_u8Line) 
{
Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		SET_BIT(EXTI->EXTI_SWIER,copy_u8Line) ;
		EXTI_u8CLR_pend(copy_u8Line);
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 
}
Error_t EXTI_u8Set_pend(EXTI_Line_t copy_u8Line) {
	Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		SET_BIT(EXTI->EXTI_PR,copy_u8Line) ;
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 
}

Error_t EXTI_u8CLR_pend(EXTI_Line_t copy_u8Line) {
	Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		CLR_BIT(EXTI->EXTI_PR,copy_u8Line) ;
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 
}


Error_t EXTI_u8Set_Inturrupt_latch(EXTI_Line_t copy_u8Line ,
	EXTI_MODE_t copy_u8Mode)
{
	Error_t Copy_u8State = OK ; 
	if (copy_u8Line < EXTI_TOTAL){
		switch(copy_u8Mode){
		case : EXTI_FAILING
			SET_BIT(EXTI->EXTI_FTSR,copy_u8Line) ;
			break ; 
		case : EXTI_RISING
			SET_BIT(EXTI->EXTI_RTSR,copy_u8Line) ;
			break ; 
		case : EXTI_FAILING_RISING
			SET_BIT(EXTI->EXTI_RTSR,copy_u8Line) ;
			SET_BIT(EXTI->EXTI_FTSR,copy_u8Line) ;
			break ; 
		default : 
			Copy_u8State = NOK ; 
			break ; 
		}
	}else {
		Copy_u8State = NOK ; 
	}
	return Copy_u8State ; 								
}