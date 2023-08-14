

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_Read_Block(u16 ADD , u8 size , u8*dataBuffer)  ;
void EEPROM_Write_Block(u16 ADD , u8 size , u8*dataBuffer)  ;

void EEPROM_Read_NOBlock(u16 ADD , u8 size , u8*dataBuffer)  ;
void EEPROM_Write_NOBlock(u16 ADD , u8 size , u8*dataBuffer)  ;

u8 EEPROM_Check() ; 

void EEPROM_EN_Interrupt();
void EEPROM_DS_Interrupt();
void EEPROM_CallBack();
#endif /* EEPROM_H_ */