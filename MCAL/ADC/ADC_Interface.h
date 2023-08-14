/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 11/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : ADC                                                      */
/*****************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum {
	ADC_ch0,
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
Error_t ADC_u8ReadCH(ADC_Ch_t Copy_8uADC_ChannelSelect , u16 *Copy_8uADC_ReadData );
void ADC_vInterruptEN() ;
void ADC_vEndConversion(void);
void ADC_vInterruptDS(void) ;
void ADC_vEnable(void) ;
void ADC_vDisable(void) ;
void ADC_vStartConversion(void) ;

#endif //ADC_INTERFACE_H_

