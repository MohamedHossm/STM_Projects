/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 11/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : ADC                                                      */
/*****************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STMF103C8_MMAP.h"

#include "ADC_Conf.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

Error_t ADC_u8Init(void) {
	Error_t local_u8Status = OK;
//*********  volt reference  *********

//*********  pre scaler *************
// APB / 8
	//main
//*********  data allining   *********
	//right adjusting
	//ALIGN 11    ADC_CR2
	CLR_BIT(ADC1->ADC_CR[1], 11);
//*********  enable Adc  *************
	ADC_vEnable();
//**********     mode    *************
// single convention no scan
	// CONT 1  ADC_CR2

	CLR_BIT(ADC1->ADC_CR[1] ,1);

	return local_u8Status;
}
/*
 * In Single conversion mode the ADC does one conversion. This mode is started either by
 setting the ADON bit in the ADC_CR2 register (for a regular channel only) or by external
 trigger (for a regular or injected channel), while the CONT bit is 0.
 Once the conversion of the selected channel is complete:
 • If a regular channel was converted:
 – The converted data is stored in the 16-bit ADC_DR register
 – The EOC (End Of Conversion) flag is set
 – and an interrupt is generated if the EOCIE is set.
 */

Error_t ADC_u8ReadCH(ADC_Ch_t Copy_8uADC_ChannelSelect,
		u16 *Copy_8uADC_ReadData) {
	Error_t local_u8Status = OK;
	//ADC_SQR[2]
	//select ch
	ADC1->ADC_SQR[0] = 0; // one ch

	ADC1->ADC_SQR[2] = Copy_8uADC_ChannelSelect;
	//start Conversion
	ADC_vEnable();
	ADC_vStartConversion();
	//wait end
	// EOC   1
	while (!READ_BIT(ADC1->ADC_SR, 1))
		;
	// read data
	*Copy_8uADC_ReadData = ADC1->ADC_DR;

	CLR_BIT(ADC1->ADC_SR, 1);
	ADC_vEndConversion();
	return local_u8Status;

}
void ADC_vInterruptEN() {

}
void ADC_vInterruptDS() {

}
void ADC_vEnable(void) {
	// ADON  0 ADC_CR2
	SET_BIT(ADC1->ADC_CR[1], 0);

}
void ADC_vDisable(void) {
	// ADON  0 ADC_CR2
	CLR_BIT(ADC1->ADC_CR[1], 0);

}
void ADC_vStartConversion(void) {
	// SWSTART:  22 ADC_CR2
	SET_BIT(ADC1->ADC_CR[1], 22);
}
void ADC_vEndConversion(void) {
	// SWSTART:  22 ADC_CR2
	CLR_BIT(ADC1->ADC_CR[1], 22);
}
