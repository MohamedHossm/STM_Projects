/* Auther         : Mohamed Hoasm                                                    */
/* Date           : 26/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : LEDMRX                                                             */
/*****************************************************************************/
#ifndef LEDMRX_INTERFACE_H_
#define LEDMRX_INTERFACE_H_
#define LEDMRXCOLSIZE 8
#define LEDMRXROWSIZE 8
#define LEDMRX_CHARSIZE 8

#define LEDMRXEROR 26
#define LEDMRX_lettersSIZE 28
#define LEDMRX_lettersSIZEARA 33

#define RETING 200
typedef struct {
	char search ;
	u8 arr[LEDMRX_CHARSIZE] ;
}LED_MRX_CONTANER_t ;

Error_t LEDMRX_u8Display(u8 arr_MRXvalue[]);
Error_t LEDMRX_u8DisplayArray(u8 arr_MRXvalue[][8],u16 rating, u8 size);
Error_t LEDMRX_u8WriteString(char *string, u16 rating ) ;
Error_t LEDMRX_u8WriteStringMove(char *string , u16 Rating);
Error_t LEDMRX_u8WriteStringMoveArabic(char *string , u16 Rating) ;
Error_t LEDMRX_u8WriteStringMoveEnglish(char *string , u16 Rating) ;
/******************case ****************/
Error_t SearchArabic(char charcter, s16 *index);
Error_t Search(char charcter, s16 *index);
Error_t LEDMRX_u8WriteStringMoveEnglishControlled(char *string, u16 Rating, u16 pos);
void LEDMRX_voidCopyvalueEnglish(const u8 Source[], u8 distination[], s8 index);
void LEDMRX_voidCopyvalueArabic(const u8 Source[], u8 distination[], s8 index);
void LEDMRX_voidCopyvalue(const u8 Source[], u8 distination[], s8 index);
/************************************/

#endif //LEDMRX_INTERFACE_H_

