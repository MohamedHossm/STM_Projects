#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "EEPROM.h"

void EEPROM_Write_Block(u16 ADD , u8 size , u8*dataBuffer)  {
	for (u8 i = 0 ; i < size ; i++ ){
		while(READ_BIT(EECR,EEWE)) ;
		EEAR = ADD + i ;
		EEDR = dataBuffer[i] ;
		/* Write logical one to EEMWE */
		SET_BIT(EECR,EEMWE);
		/* Start eeprom write by setting EEWE */
		SET_BIT(EECR,EEWE);
	}

}
void  EEPROM_Read_Block(u16 ADD , u8 size , u8*dataBuffer)  {
	for (u8 i = 0 ; i < size ; i++ ){
	while(READ_BIT(EECR,EEWE)) ;
	EEAR = ADD+i ;
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR,EERE);
	dataBuffer[i] = EEAR;
	}
}