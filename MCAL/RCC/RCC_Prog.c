/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include "RCC_Private.h"
#include "RCC_CONF.h"
#include "RCC_Interface.h"

void RCC_voidInitSystemClock(void)
{
#if RCC_u8CLK_TYPE==RCC_u8HSE_CRYSTAL
	RCC->RCC_CR=0x00010080;
#elif RCC_u8CLK_TYPE==RCC_u8HSE_RC
	RCC->RCC_CR=0x00050080;
#elif RCC_u8CLK_TYPE==RCC_u8HSI
	RCC->RCC_CR=0x00000081;
	RCC->RCC_CFGR = 0x00000000;
#elif RCC_u8CLK_TYPE==RCC_u8PLL
		#if RCC_u8PLL_INPUT == RCC_u8PLL_HSI_DIV_2
			#elif RCC_u8PLL_INPUT == RCC_u8PLL_HSE_DIV_2
			#elif RCC_u8PLL_INPUT == RCC_u8PLL_HSE
		#endif
	RCC->RCC_CR = 0x00010080;
#else
	#error("You choosed wrong Clock Type")
#endif

}

Error_t RCC_voidEnablePeriphralCLK(PeriphralBusId_t Copy_enPeriphralId)
{	
	u8 Local_u8BusID =Copy_enPeriphralId/100;
	u8 Local_u8PeriphralID =Copy_enPeriphralId % 100;

	Error_t Local_enErrorState=OK;

	if(Local_u8PeriphralID  <= 31) //unsigned
	{
		switch(Local_u8BusID)
		{
		case RCC_u8AHB: SET_BIT(RCC->RCC_AHBENR,Local_u8PeriphralID) ;    	
			break;

		case RCC_u8APB2:SET_BIT(RCC->RCC_APB2ENR,Local_u8PeriphralID) ;	
			break;

		case RCC_u8APB1: SET_BIT(RCC->RCC_APB1ENR,Local_u8PeriphralID) ;	
			break;
			
			
			
		default:
			Local_enErrorState=NOK;
			break;

		}

	}
	else
	{
		Local_enErrorState=NOK;

	}

	return Local_enErrorState;
}

Error_t RCC_voidDisablePeriphralCLK(PeriphralBusId_t Copy_enPeriphralId)
{

	u8 Local_u8BusID =Copy_enPeriphralId/100;
	u8 Local_u8PeriphralID =Copy_enPeriphralId % 100;
	Error_t Local_enErrorState=OK;
	if(Local_u8PeriphralID <= 31) //unsigned
	{
		switch(Local_u8BusID)
		{
		case RCC_u8AHB: CLR_BIT(RCC->RCC_AHBENR,Local_u8PeriphralID) ;    	
			break;

	case RCC_u8APB1:CLR_BIT(RCC->RCC_APB1ENR,Local_u8PeriphralID) ;	
		break;
		
	case RCC_u8APB2:CLR_BIT(RCC->RCC_APB2ENR,Local_u8PeriphralID) ;	
		break;
		
	default:
		Local_enErrorState=NOK;
		break;

	}

}
else
{
	Local_enErrorState=NOK;

}

return Local_enErrorState;
}




