/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 31/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : DMA                                                             */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include "DMA_Conf.h"
#include "DMA_Interface.h"
#include "DMA_Pivate.h"


void DMA_VoidInit(void){
	//contigration for ch1
	DMA_SITTING_t CH0 = { 0 };
	// set configuration struct
		CH0.DMA_MINC = DMA_ENABLE;
		CH0.DMA_PINC = DMA_ENABLE;
		CH0.DMA_PSIZE = DMA_32_BIT;
		CH0.DMA_MSIZE = DMA_32_BIT;
		CH0.DMA_MEM2MEM = DMA_ENABLE;
		CH0.DMA_TCIE = DMA_ENABLE ;
		DMA_u8ChannelConfig(DMA_CH1, CH0);
}


Error_t DMA_u8ChannelConfig(DMA_Channels Copy_DMAChannel,
		DMA_SITTING_t Copy_u32conf) {

	Error_t local_u8State = OK;
//enable bit
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_EN = Copy_u32conf.DMA_EN;
// set interrupt
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_TCIE = Copy_u32conf.DMA_TCIE;
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_TEIE = Copy_u32conf.DMA_TEIE;
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_HTIE = Copy_u32conf.DMA_HTIE;
// set circular
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_CIRC = Copy_u32conf.DMA_CIRC;
//set DIR
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_DIR = Copy_u32conf.DMA_DIR;
// set memory 2 memory
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_MEM2MEM = Copy_u32conf.DMA_MEM2MEM;
// set priority
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_PL = Copy_u32conf.DMA_PL;
//memory increment  (source)
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_MINC = Copy_u32conf.DMA_MINC;
//Peripheral increment (destination)
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_PINC = Copy_u32conf.DMA_PINC;
////memory size  (source)
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_MSIZE = Copy_u32conf.DMA_MSIZE;
//Peripheral size (destination)
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_PSIZE = Copy_u32conf.DMA_PSIZE;

	return local_u8State;

}

Error_t DMA_u8ChannelEN(DMA_Channels Copy_DMAChannel) {
	Error_t local_u8State = OK;
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_EN = DMA_ENABLE;
	return local_u8State;
}
Error_t DMA_u8ChannelDS(DMA_Channels Copy_DMAChannel) {
	Error_t local_u8State = OK;
	DMA->DMA_CH[Copy_DMAChannel].DMA_CCR.DMA_EN = DMA_DISABLE;
	return local_u8State;
}

Error_t DMA_u8ChannelSource_Distination(DMA_Channels Copy_DMAChannel,
		u32 *PTR_DMASource, u32 *PTR_DMADistination, u16 Copy_u16DMA_size) {
	Error_t local_u8State = OK;
	// check if ptr != null pointers
	if (PTR_DMASource != NULLPTR && PTR_DMADistination != NULLPTR) {
		//disable DMA channel
		DMA_u8ChannelDS(Copy_DMAChannel);
		// copy source and dis addresses
		DMA->DMA_CH[Copy_DMAChannel].DMA_CMAR = (u32) PTR_DMADistination;
		DMA->DMA_CH[Copy_DMAChannel].DMA_CPAR = (u32) PTR_DMASource;
		// select size
		DMA->DMA_CH[Copy_DMAChannel].DMA_CNDTR = Copy_u16DMA_size;
		//enable DMA channel
		DMA_u8ChannelEN(Copy_DMAChannel);

	} else {
		local_u8State = NOK;
	}

	return local_u8State;
}
void DMA1_Channel1_IRQHandler(){

}
void DMA1_Channel2_IRQHandler(){

}
void DMA1_Channel3_IRQHandler(){

}
void DMA1_Channel4_IRQHandler(){

}
void DMA1_Channel5_IRQHandler(){

}
void DMA1_Channel6_IRQHandler(){

}
void DMA1_Channel7_IRQHandler(){

}
