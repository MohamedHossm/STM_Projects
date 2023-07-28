/*
 * Lap1_LedMatixControl.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Amm
 */

#ifndef LAP1_LEDMATIXCONTROL_H_
#define LAP1_LEDMATIXCONTROL_H_

#define B1 Pin_B0
#define B2 Pin_B1
#define B3 Pin_B4
#define B4 Pin_B5

#define NORMALSPEED 144
#define LIMITSPEAD_HIGH 12
#define LIMITSPEAD_LOW 3

void B1Fun();
void B2Fun();
void B3Fun();
void B4Fun();

void ledmatrex(char name[]);
Error_t APPLEDMRX_u8WriteStringMove(char *string, u16 Rating);

#endif /* LAP1_LEDMATIXCONTROL_H_ */
