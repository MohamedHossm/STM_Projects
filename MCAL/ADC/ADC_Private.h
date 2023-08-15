/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                            */
/* Date            : 11/8/2023                                                */
/* Version         : 1.0                                                      */
/* SW              : ADC                                                      */
/*****************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

// ----------- adjust options ---------------
#define ADC_RIGHTADJAST  0x22
#define ADC_LEFTADJAST   0x55
//-------------------------------------------

// ----------- temp options -----------------
#define ADC_TEMP_ON   0x22
#define ADC_TEMP_OFF  0x55
//-------------------------------------------

// ----------- Scan options -----------------
#define ADC_SCAN_ON   0x22
#define ADC_SCAN_OFF  0x55
//-------------------------------------------

//-------------------------------------------
#define ADC_SIZESEQPOS 20
#define DUAL_MODE_BITS_LOCATION 16
//-------------------------------------------



#define SQR1  0
#define SQR2  1
#define SQR3  2

#define SMPR1 0
#define SMPR2 1

#define CR1   0
#define CR2   1
//ADC
#define  ADC_EOC   1
//ADC_CR1
#define  ADC_JDISCEN   12                            //Discontinuous mode on injected channels
#define  ADC_DISCEN    11                            //Discontinuous mode on regular channels
#define  ADC_JAUTO     10                            //Automatic Injected Group conversion
#define  ADC_SCAN      8                             //Scan mode
#define  ADC_EOCIE     5                             // Interrupt enable for EOC
#define  ADC_JEOCIE    7                             //Interrupt enable for injected channels
#define  ADC_AWDSGL    9                             // Enable the watchdog on a single channel in scan mode
//ADC_CR2
#define  ADC_TSVREFE     23                          //Temperature sensor and VREFINT enable
#define  ADC_SWSTART     22                          //Start conversion of regular channels
#define  ADC_JSWSTART    21                          //Start conversion of injected channels
#define  ADC_JEXTTRIG    15                          //External trigger conversion mode for injected channels
#define  ADC_ALIGN       11                          //Data alignment
#define  ADC_RSTCAL      3                           //Reset calibration
#define  ADC_CAL         2                           //A/D Calibration
#define  ADC_CONT        1                           //Continuous conversion
#define  ADC_ADON        0                           //A/D converter ON / OFF

// -------------    sampling  -------------------------------
/*
000: 1.5 cycles
001: 7.5 cycles
010: 13.5 cycles
011: 28.5 cycles
100: 41.5 cycles
101: 55.5 cycles
110: 71.5 cycles
111: 239.5 cycles
*/
// ---------------------------------------------------------------------------

// -------------Dual mode selection (ADC MODE) -------------------------------
#define ADC_MODE_INDEPENDENT                         0b0000
#define ADC_MODE_REGULAR_SIMU_INJECTED_SIMU          0b0001
#define ADC_MODE_REGULAR_SIMU_ALTERNATE_TRIGG        0b0010
#define ADC_MODE_INJECTED_SIMU_FAST_INTERLEAVED      0b0011
#define ADC_MODE_INJECTED_SIMU_SLOW_INTERLEAVED      0b0100
#define ADC_MODE_INJECTED_SIMU                       0b0101
#define ADC_MODE_REGULAR_SIMU                        0b0110
#define ADC_MODE_FAST_INTERLEAVED                    0b0111
#define ADC_MODE_SLOW_INTERLEAVED                    0b1000
#define ADC_MODE_ALTERNATE_TRIGG                     0b1001

/*
 These bits are written by software to select the operating mode.
 0000: Independent mode.
 0001: Combined regular simultaneous + injected simultaneous mode
 0010: Combined regular simultaneous + alternate trigger mode
 0011: Combined injected simultaneous + fast interleaved mode
 0100: Combined injected simultaneous + slow Interleaved mode
 0101: Injected simultaneous mode only
 0110: Regular simultaneous mode only
 0111: Fast interleaved mode only
 1000: Slow interleaved mode only
 1001: Alternate trigger mode only
 */
//--------------------------------------------------------------------------//
//------------------------Discontinuous mode channel count-----------------//

#define ADC_DISCONTINNUOUS_MODE_1_CHANNEL            0b0000
#define ADC_DISCONTINNUOUS_MODE_2_CHANNELS           0b0001
#define ADC_DISCONTINNUOUS_MODE_3_CHANNELS           0b0010
#define ADC_DISCONTINNUOUS_MODE_4_CHANNELS           0b0011
#define ADC_DISCONTINNUOUS_MODE_5_CHANNELS           0b0100
#define ADC_DISCONTINNUOUS_MODE_6_CHANNELS           0b0101
#define ADC_DISCONTINNUOUS_MODE_7_CHANNELS           0b0110
#define ADC_DISCONTINNUOUS_MODE_8_CHANNELS           0b0111
//--------------------------------------------------------------------------//
/*
These bits are written by software to define the number of regular channels to be converted
in discontinuous mode, after receiving an external trigger.
000: 1 channel
001: 2 channels
.......
111: 8 channels
*/

//---------------------conversion mode-------------------------------------//
#define ADC_SINGLE_CON_MODE        1     // Single conversion mode
#define ADC_CONTINUOUS_CON_MODE    2     // Continuous conversion mode
//--------------------------------------------------------------------------//
#endif //ADC_PRIVATE_H_
