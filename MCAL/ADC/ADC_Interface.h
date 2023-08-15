/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 11/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : ADC                                                      */
/*****************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*
 * These bits are written by software to select the sample time individually for each channel.
During sample cycles channel selection bits must remain unchanged.
000: 1.5 cycles
001: 7.5 cycles
010: 13.5 cycles
011: 28.5 cycles
100: 41.5 cycles
101: 55.5 cycles
110: 71.5 cycles
111: 239.5 cycles
*/
typedef enum {
	ADC_SAMPLE_CYCLES_15=0,
	ADC_SAMPLE_CYCLES_75,
	ADC_SAMPLE_CYCLES_135,
	ADC_SAMPLE_CYCLES_285,
	ADC_SAMPLE_CYCLES_415,
	ADC_SAMPLE_CYCLES_555,
	ADC_SAMPLE_CYCLES_715,
	ADC_SAMPLE_CYCLES_2395,
	ADC_SAMPLE_total
}ADC_sampling_t;

typedef enum {
	ADC_ch0 = 0,
	ADC_ch1,
	ADC_ch2,
	ADC_ch3,
	ADC_ch4,
	ADC_ch5,
	ADC_ch6,
	ADC_ch7,
	ADC_ch8,
	ADC_ch9,
	ADC_ch10,
	ADC_ch11,
	ADC_ch12,
	ADC_ch13,
	ADC_ch14,
	ADC_ch15

} ADC_Ch_t;
Error_t ADC_u8Init(void);
Error_t ADC_u8ReadCH(ADC_Ch_t Copy_8uADC_ChannelSelect,
		u16 *Copy_8uADC_ReadData);
Error_t ADC_u8ReadCHSequance(ADC_Ch_t Copy_8uADC_ChannelSelect,
		u16 *Copy_8uADC_ReadData, u8 Copy_8uADCSequance);
Error_t ADC_u8SetNSequance(u8 Copy_8uADC_NSequance);
Error_t ADC_u8SetCH_Sampling(ADC_Ch_t Copy_8uADC_ChannelSelect, ADC_sampling_t Copy_8uADC_Sampling);

Error_t ADC_u8_IRQSetter(void (*PTR)(void));
void ADC_vInterruptEN();
void ADC_vEndConversion(void);
void ADC_vInterruptDS(void);
void ADC_vEnable(void);
void ADC_vDisable(void);
void ADC_vStartConversion(void);

#endif //ADC_INTERFACE_H_

