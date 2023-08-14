#include "StdTypes.h"
#include "UART.h"
#include "UART_Stack_Sevice..h"
static u8 UART_STACK [UART_BUFFER_SIZE] ;
static u8 stack_ptr = 0 ;
static Stack_error_t status_flage = STACK_FINE ; 
void UART_Stack_Service_Init(){
	UART_RX_SetCallBack(UART_Service_Interrupt) ;
}
Stack_error_t UART_Stack_Push(u8 data){
	if (stack_ptr==UART_BUFFER_SIZE){
		return STACK_FUll ;
	}
	UART_STACK[stack_ptr++] = data ;
	return STACK_FINE ;
}
Stack_error_t UART_Stack_Pop(u8* data){
	if (stack_ptr == 0 ){
		status_flage = STACK_EMPTY ;
		return STACK_EMPTY ;
	}
	stack_ptr-- ;
	*data =UART_STACK[stack_ptr] ;
	return STACK_FINE ;
}
void UART_Service_Interrupt(){
	
	if (UART_Stack_Push(UART_ReceiveNoBlock()) == STACK_FUll){
		status_flage = STACK_FUll ; 
	}else {
			status_flage = STACK_FINE ;
	}
	
}
Stack_error_t Get_Status(){
	return status_flage ; 
}
void set_Status(Stack_error_t flag){
	 status_flage = flag ; 
}