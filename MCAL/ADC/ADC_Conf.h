/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 11/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : ADC                                                      */
/*****************************************************************************/

#ifndef ADC_CONF_H_
#define ADC_CONF_H_
/* ------- options ----------
 *  ADC_RIGHTADJAST
 *  ADC_LEFTADJAST
 * */
#define ADC_ADJUST  ADC_RIGHTADJAST


/* ------- options ----------
 *  ADC_TEMP_ON
 *  ADC_TEMP_OFF
 * *
 * */
#define ADC_TEMP  ADC_TEMP_OFF


/* ------- options ----------
 *  ADC_SCAN_ON
 *  ADC_SCAN_OFF
 * *
 * */
#define ADC_SCAN_MODE  ADC_SCAN_OFF


/*-----options -----------
 *
 * ADC_SINGLE_CON_MODE
 * ADC_CONTINUOUS_CON_MODE
 */
#define ADC_MODE  ADC_SINGLE_CON_MODE


/*-----options -----------
 ADC_MODE_INDEPENDENT
 ADC_MODE_REGULAR_SIMU_INJECTED_SIMU
 ADC_MODE_REGULAR_SIMU_ALTERNATE_TRIGG
 ADC_MODE_INJECTED_SIMU_FAST_INTERLEAVED
 ADC_MODE_INJECTED_SIMU_SLOW_INTERLEAVED
 ADC_MODE_INJECTED_SIMU
 ADC_MODE_REGULAR_SIMU
 ADC_MODE_FAST_INTERLEAVED
 ADC_MODE_SLOW_INTERLEAVED
 ADC_MODE_ALTERNATE_TRIGG
*/
#define ADC_DUAL_MODE   ADC_MODE_INDEPENDENT


#endif //ADC_CONF_H_
