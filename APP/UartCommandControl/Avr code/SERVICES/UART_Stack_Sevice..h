/*
 * UART_Stack_Sevice.h
 *
 * Created: 6/12/2023 1:27:13 PM
 *  Author: Amm
 */ 


#ifndef UART_STACK_SEVICE_H_
#define UART_STACK_SEVICE_H_
typedef enum {
	STACK_EMPTY ,
	STACK_FUll,
	STACK_FINE
}Stack_error_t;
#define UART_BUFFER_SIZE 10
void UART_Stack_Service_Init();
Stack_error_t UART_Stack_Push(u8 data);
Stack_error_t UART_Stack_Pop(u8* data);
void UART_Service_Interrupt();
Stack_error_t Get_Status() ;
void set_Status(Stack_error_t flag);
#endif /* UART_STACK_SEVICE._H_ */