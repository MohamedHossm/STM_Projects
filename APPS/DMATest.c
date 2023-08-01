/*****************************************************************************/
/* Author         : Mohamed Hoasm                                             */
/* Date           : 16/7/2023                                                 */
/* Version        : 1.0                                                       */
/*SW              : mian                                                         */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "DMA_Interface.h"

u32 source [1000]= {1,2,3,4,5,7,8,9,10};
u32 destination [1000]= {0};


int main(void) {


	//enable RCC 8-MHz
	RCC_voidInitSystemClock();
//enable DMA1 clk
	RCC_voidEnablePeriphralCLK(AHB_DMA1EN);
	//enable DMA1 channel1 interrupt
	NVIC_u8Set_EN_IRQ(INTERRUPT_DMA1_CHANNEL1);
	// channel conf
	DMA_VoidInit();
	DMA_u8ChannelSource_Distination(DMA_CH1, source, destination, 1000);
	while (1) {

	}

	return 0;
}
void DMA1_Channel1_IRQHandler(){
	static u8 i = 0 ;
	i++ ;
}
