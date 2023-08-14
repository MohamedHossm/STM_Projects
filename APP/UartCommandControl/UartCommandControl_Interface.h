/*****************************************************************************/
/* Auther          : Mohamed Hoasm                                             */
/* Date            : 8/8/2023                                                  */
/* Version         : 1.0                                                       */
/* SW              : UartCommandControl                                                             */
/*****************************************************************************/
#ifndef UartCommandControl_INTERFACE_H_
#define UartCommandControl_INTERFACE_H_


#define  LEDARRSIZE 8
#define  LEDMXPATTERNSIZE  8
#define  UARTSEARCHSTRING_MSIZE  20
#define  UARTSEARCHFUN_MSIZE     20

#define  LEDMTRIXLOAD Pin_B12

#define  AVRSSPIN  Pin_B8
typedef struct {
	u8 SearchString[UARTSEARCHSTRING_MSIZE];
	Error_t (*Sellected_FUN)(u8);

} UATR_Controlled_t;

Error_t LEDARR_u8DisplayON(u8 Copy_u8LedID);
Error_t LEDARR_u8DisplayOFF(u8 Copy_u8LedID) ;
Error_t UART_u8SearchFunctions_String(u8 *PTR_SearchString,
		u8 *PTR_ReturnElementIndex);
Error_t LedM_u8Display(u8 Copy_u8PatternID);
Error_t SpiFunctionSend(u8 * PTR_String , u32 Copy_number);
void UartCommandControl_vRunnable(void);
void UartCommandControl_vIint();
#endif //UartCommandControl_INTERFACE_H_

