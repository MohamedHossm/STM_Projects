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

void (*ADCIRQ_CALLBACK)(void) = NULLPTR;

Error_t ADC_u8Init(void) {
	Error_t local_u8Status = OK;

//*********  volt reference  *********
#if   ADC_TEMP == ADC_TEMP_ON
SET_BIT(ADC1->ADC_CR[CR2], ADC_TSVREFE);
#elif ADC_TEMP == ADC_TEMP_OFF
	CLR_BIT(ADC1->ADC_CR[CR2], ADC_TSVREFE);
#endif

//*********  pre scaler  *************
// APB / 8
//main
//************************************

//*********  data aligning   *********
#if ADC_ADJUST ==  ADC_RIGHTADJAST
	CLR_BIT(ADC1->ADC_CR[CR2], ADC_ALIGN);
#elif ADC_ADJUST ==  ADC_LEFTADJAST
	SET_BIT(ADC1->ADC_CR[CR2], ADC_ALIGN);
#endif
//************************************

//*************    MODE  ************
#if ADC_MODE ==  ADC_SINGLE_CON_MODE
	CLR_BIT(ADC1->ADC_CR[CR2], ADC_CONT);
#elif ADC_MODE ==  ADC_SINGLE_CON_MODE
	SET_BIT(ADC1->ADC_CR[CR2], ADC_CONT);
#endif
//*************************************

//**********  Scan mode    *************

#if   ADC_SCAN_MODE  ==  ADC_SCAN_OFF
	CLR_BIT(ADC1->ADC_CR[CR2], ADC_CONT);
#elif ADC_SCAN_MODE  ==  ADC_SCAN_ON
	SET_BIT(ADC1->ADC_CR[CR2], ADC_CONT);
#endif
//************************************

//************* DUAL MODE  ************
	ADC1->ADC_CR[CR1] &= (~(0b1111 << DUAL_MODE_BITS_LOCATION));
	ADC1->ADC_CR[CR1] |= ((ADC_DUAL_MODE << DUAL_MODE_BITS_LOCATION));
//************************************

//*********  enable Adc  *************
	ADC_vEnable();
//************************************

//********** Start Calibration *******
	SET_BIT(ADC1->ADC_CR[CR2], ADC_CAL);
//************************************

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

Error_t ADC_u8_IRQSetter(void (*PTR)(void)) {
	Error_t local_u8Status = OK;

	if (PTR != NULLPTR) {
		ADCIRQ_CALLBACK = PTR;
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}
Error_t ADC_u8ReadCH(ADC_Ch_t Copy_8uADC_ChannelSelect,
		u16 *Copy_8uADC_ReadData) {

	Error_t local_u8Status = OK;

	//select ch
	ADC1->ADC_SQR[SQR1] = 0; // one ch
	ADC1->ADC_SQR[SQR3] = Copy_8uADC_ChannelSelect;

	//start Conversion
	ADC_vEnable();
	ADC_vStartConversion();

	//wait end
	while (!READ_BIT(ADC1->ADC_SR, ADC_EOC)) {
	}

	// read data
	*Copy_8uADC_ReadData = ADC1->ADC_DR;

	// rest the flag
	CLR_BIT(ADC1->ADC_SR, ADC_EOC);
	ADC_vEndConversion();

	return local_u8Status;

}

Error_t ADC_u8SetNSequance(u8 Copy_8uADC_NSequance) {
	Error_t local_u8Status = OK;
	if (Copy_8uADC_NSequance < 16) {
		ADC1->ADC_SQR[SQR1] &= (~(0b111 << ADC_SIZESEQPOS));
		ADC1->ADC_SQR[SQR1] |= ((Copy_8uADC_NSequance << ADC_SIZESEQPOS));
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}
Error_t ADC_u8ReadCHSequance(ADC_Ch_t Copy_8uADC_ChannelSelect,
		u16 *Copy_8uADC_ReadData, u8 Copy_8uADCSequance) {

	Error_t local_u8Status = OK;
	if (Copy_8uADC_ChannelSelect < 16 && Copy_8uADCSequance < 16) {
		u8 local_u8ADC_index = Copy_8uADCSequance / 6;
		u8 local_u8ADC_cont = Copy_8uADCSequance % 6;

		// select channel and sequence number
		ADC1->ADC_SQR[SQR3 - local_u8ADC_index] &= (~(0b1111
				<< local_u8ADC_cont * 6));
		ADC1->ADC_SQR[SQR3 - local_u8ADC_index] |= ((Copy_8uADC_ChannelSelect
				<< local_u8ADC_cont * 6));
		//start Conversion
		ADC_vEnable();
		ADC_vStartConversion();

		//wait conversion complete
		while (!READ_BIT(ADC1->ADC_SR, ADC_EOC)) {
		}

		// read data
		*Copy_8uADC_ReadData = ADC1->ADC_DR;

		// rest the flag       //ADC_EOC
		CLR_BIT(ADC1->ADC_SR, ADC_EOC);
		ADC_vEndConversion();
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}
Error_t ADC_u8SetCH_Sampling(ADC_Ch_t Copy_8uADC_ChannelSelect,
		ADC_sampling_t Copy_8uADC_Sampling) {

	Error_t local_u8Status = OK;
	if (Copy_8uADC_ChannelSelect < 16
			&& Copy_8uADC_Sampling < ADC_SAMPLE_total) {
		u8 local_u8ADC_index = Copy_8uADC_Sampling / 10;
		u8 local_u8ADC_cont = Copy_8uADC_Sampling % 10;

		// select channel and sequence number
		ADC1->ADC_SMPR[SMPR1 - local_u8ADC_index] &= (~(0b111
				<< local_u8ADC_cont * 10));
		ADC1->ADC_SMPR[SMPR1 - local_u8ADC_index] |= ((Copy_8uADC_Sampling
				<< local_u8ADC_cont * 10));
	} else {
		local_u8Status = NOK;
	}
	return local_u8Status;
}

void ADC_vInterruptEN() {
	SET_BIT(ADC1->ADC_CR[CR1], ADC_EOCIE);
}

void ADC_vInterruptDS() {
	CLR_BIT(ADC1->ADC_CR[CR1], ADC_EOCIE);
}

void ADC_vEnable(void) {
	// ADON  0 ADC_CR2
	SET_BIT(ADC1->ADC_CR[CR2], ADC_ADON);
}

void ADC_vDisable(void) {
	// ADON  0 ADC_CR2
	CLR_BIT(ADC1->ADC_CR[CR2], ADC_ADON);
}

void ADC_vStartConversion(void) {
	// SWSTART:  22 ADC_CR2
	SET_BIT(ADC1->ADC_CR[1], ADC_SWSTART);
}
void ADC_vEndConversion(void) {
	// SWSTART:  22 ADC_CR2
	CLR_BIT(ADC1->ADC_CR[1], ADC_SWSTART);
}

void ADC1_2_IRQHandler() {
	if (READ_BIT(ADC1->ADC_SR,ADC_EOC) == TRUE) {
		ADCIRQ_CALLBACK();
	}

}
