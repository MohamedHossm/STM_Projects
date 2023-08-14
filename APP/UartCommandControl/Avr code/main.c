#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#define  F_CPU 8000000
#include <util/delay.h>
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Timers.h"
#include "SPI.h"
#include "SpiStrings.h"

#define  SPISEARCHFUN_MSIZE 20
#define  SPISEARCHSTRING_MSIZE 20
Error_t SPI_u8SearchFunctions_String(u8 *PTR_SearchString,
u8 *PTR_ReturnElementIndex);
Error_t Servo_u8controleAngle(u16 local_u8Angle );
u8 DataIncome =0 ;
u8 checkState = 0 ;
u32 incexx=0 ;
u8 datarec =0 ;

u8 SPIStringReturn[30] = { 0 };
u16 SPINUMReturn = 0;
u8 SPI_SellectedFunction = 0;

typedef struct {
	u8 SearchString[SPISEARCHSTRING_MSIZE];
	Error_t (*Sellected_FUN)(u16);

} SPI_Controlled_t;
SPI_Controlled_t FunDataBase[ SPISEARCHFUN_MSIZE] = {
	{"servo"  , Servo_u8controleAngle}
};
//u8 UART_SellectedFunction = 0;

int main(void)
{
	DIO_Init();
	LCD_Init();
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	ICR1 = 20000 ;
	Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	SPI_Init(SLAVE,F_8);
	SPI_StringsS_Init();
	SPI_Interrupt_Enable();
	sei();
	LCD_SetCursor(0,0);
	LCD_WriteString(" line  ");
	while (1){
		SPI_StringsS_Runnable();
		LCD_SetCursor(1,0);
		if (SPI_StringsS_IsDataReady()){
			SPI_StringsS_GETdata(SPIStringReturn,&SPINUMReturn);
			
			if (SPI_u8SearchFunctions_String(SPIStringReturn,
			&SPI_SellectedFunction) == OK) {

				FunDataBase[SPI_SellectedFunction].Sellected_FUN(SPINUMReturn);
			} else{
				
			}
			//LCD_WriteString("                   ");
			LCD_WriteString((char*)SPIStringReturn);
			LCD_WriteString("          ");
			LCD_SetCursor(0,7);
			LCD_WriteNumber(SPINUMReturn);
			}else {
			LCD_SetCursor(1,10);
			LCD_WriteNumber(incexx++);
		}
	}
}
Error_t Servo_u8controleAngle(u16 local_u8Angle ){
	Error_t Local_u8Status = OK;
if (local_u8Angle >= 0 && local_u8Angle<=180){
	LCD_SetCursor(1 , 0 );
	Timer1OCRA1_setter(MAPING(0,180,999,1999,local_u8Angle));
}else {
	Local_u8Status =NOK ;
}


	return Local_u8Status;
}

Error_t Srting_COMP(u8 *string1, u8 *string2) {
	Error_t Local_u8Status = OK;
	for (u8 index = 0; string1[index] || string2[index]; index++) {
		if (string1[index] != string2[index]) {
			Local_u8Status = NOK;
			break;
			} else {
			//do nothing
		}
	}
	return Local_u8Status;
}
Error_t SPI_u8SearchFunctions_String(u8 *PTR_SearchString,
u8 *PTR_ReturnElementIndex) {
	Error_t Local_u8Status = NOK;
	u8 local_u8elementsIndex;
	for (local_u8elementsIndex = 0; local_u8elementsIndex < SPISEARCHFUN_MSIZE;
	local_u8elementsIndex++) {
		if (Srting_COMP(PTR_SearchString,
		FunDataBase[local_u8elementsIndex].SearchString) == OK) {
			*PTR_ReturnElementIndex = local_u8elementsIndex;
			Local_u8Status = OK;
			break;
			} else {
			//do nothing
		}
	}
	return Local_u8Status;
}
