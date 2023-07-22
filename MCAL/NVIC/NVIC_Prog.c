/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 13/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : NVIC                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include"NVIC_Conf.h"
#include"NVIC_Pivate.h"
#include"NVIC_Interface.h"

Error_t NVIC_u8Set_PR_options() {


#if NVIC_PR_OPTIONS == 1
	SCB_AIRCR =SCB_G_16_SUP_NONE ;
#elif NVIC_PR_OPTIONS == 2
	SCB_AIRCR =SCB_G_8_SUP_4 ;
#elif NVIC_PR_OPTIONS == 3
	SCB_AIRCR =SCB_G_4_SUP_4 ;
#elif NVIC_PR_OPTIONS == 4
	SCB_AIRCR =SCB_G_2_SUP_8 ;
#elif NVIC_PR_OPTIONS == 5
	SCB_AIRCR =SCB_G_NONE_SUP_16 ;
#endif
	return OK ;
}

Error_t NVIC_u8Set_EN_IRQ(NVIC_Prority_t Copy_IRQ_ID) {
	Error_t Copy_status = OK;
	u8 Copy_ID_Index = Copy_IRQ_ID / NVIC_REG_SIZE;
	if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
		Copy_IRQ_ID = Copy_IRQ_ID % NVIC_REG_SIZE;
		NVIC->NVIC_ISER[Copy_ID_Index] = 1 << Copy_IRQ_ID;
	} else {
		Copy_status = NOK;
	}
	return Copy_status;
}
Error_t NVIC_u8Clr_EN_IRQ(NVIC_Prority_t Copy_IRQ_ID) {
	Error_t Copy_status = OK;
	u8 Copy_ID_Index = Copy_IRQ_ID / NVIC_REG_SIZE;
	if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
		Copy_IRQ_ID = Copy_IRQ_ID % NVIC_REG_SIZE;
		NVIC->NVIC_ICER[Copy_ID_Index] = 1 << Copy_IRQ_ID;
	} else {
		Copy_status = NOK;
	}
	return Copy_status;
}
Error_t NVIC_u8Set_Pend_IRQ(NVIC_Prority_t Copy_IRQ_ID) {
	Error_t Copy_status = OK;
	u8 Copy_ID_Index = Copy_IRQ_ID / NVIC_REG_SIZE;
	if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
		Copy_IRQ_ID = Copy_IRQ_ID % NVIC_REG_SIZE;
		NVIC->NVIC_ISPR[Copy_ID_Index] = (1 << Copy_IRQ_ID);
	} else {
		Copy_status = NOK;
	}
	return Copy_status;
}
Error_t NVIC_u8Clr_Pend_IRQ(NVIC_Prority_t Copy_IRQ_ID) {
	Error_t Copy_status = OK;
	u8 Copy_ID_Index = Copy_IRQ_ID / NVIC_REG_SIZE;
	if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
		Copy_IRQ_ID = Copy_IRQ_ID % NVIC_REG_SIZE;
		NVIC->NVIC_ICPR[Copy_ID_Index] = (1 << Copy_IRQ_ID);
	} else {
		Copy_status = NOK;
	}
	return Copy_status;
}
Error_t NVIC_u8Get_Active_IRQ(NVIC_Prority_t Copy_IRQ_ID, u8 *PtrActive_Value) {
	Error_t Copy_status = OK;
	u8 Copy_ID_Index = Copy_IRQ_ID / NVIC_REG_SIZE;
	if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
		Copy_IRQ_ID = Copy_IRQ_ID % NVIC_REG_SIZE;
		*PtrActive_Value = READ_BIT(NVIC->NVIC_IABR[Copy_ID_Index],
				Copy_IRQ_ID);
	} else {
		Copy_status = NOK;
	}
	return Copy_status;
}
