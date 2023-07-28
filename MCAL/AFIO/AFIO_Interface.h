/*****************************************************************************/
/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 24/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : AFIO                                                            */
/*****************************************************************************/
#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_
typedef enum {
	AFIO_Cont_ISQ_Line0, /*AFIO Line 0 */
	AFIO_Cont_ISQ_Line1, /*AFIO Line 1 */
	AFIO_Cont_ISQ_Line2, /*AFIO Line 2 */
	AFIO_Cont_ISQ_Line3, /*AFIO Line 3 */
	AFIO_Cont_ISQ_Line4, /*AFIO Line 4 */
	AFIO_Cont_ISQ_Line5, /*AFIO Line 5 */
	AFIO_Cont_ISQ_Line6, /*AFIO Line 6 */
	AFIO_Cont_ISQ_Line7, /*AFIO Line 7 */
	AFIO_Cont_ISQ_Line8, /*AFIO Line 8 */
	AFIO_Cont_ISQ_Line9, /*AFIO Line 9 */
	AFIO_Cont_ISQ_Line10, /*AFIO Line 10 */
	AFIO_Cont_ISQ_Line11, /*AFIO Line 11 */
	AFIO_Cont_ISQ_Line12, /*AFIO Line 12 */
	AFIO_Cont_ISQ_Line13, /*AFIO Line 13 */
	AFIO_Cont_ISQ_Line14, /*AFIO Line 14 */
	AFIO_Cont_ISQ_Line15, /*AFIO Line 15 */
	AFIO_Cont_ISQ_TOTAL
} AFIO_Cont_ISQ_Line_t;
typedef enum {
	AFIO_SEL_PA = 0,
	AFIO_SEL_PB,
	AFIO_SEL_PC
} AFIO_Cont_ISQ_PORT_t;

#define AFIO_u8SIZE_PIN 4
Error_t AFIO_u8setInterrupt(AFIO_Cont_ISQ_Line_t Copy_u8Line,
		AFIO_Cont_ISQ_PORT_t Copy_u8Port);

#endif //AFIO_INTERFACE_H_

