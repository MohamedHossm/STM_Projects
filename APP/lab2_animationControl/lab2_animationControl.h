/*
 * lab2_animationControl.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Amm
 */

#ifndef LAB2_ANIMATIONCONTROL_LAB2_ANIMATIONCONTROL_H_
#define LAB2_ANIMATIONCONTROL_LAB2_ANIMATIONCONTROL_H_

#define BCON Pin_B7
#define LEDNUM 8
#define FUNSNUM 3
void Flash(u8 num);
void Fta7y_Ya_wrda(u8 num);
void Ping_Pong(u8 num);
void lab2_animationControl_Runnable();
void lab2_animationControl_Init();
void BCONFun() ; // should be Private
#endif /* LAB2_ANIMATIONCONTROL_LAB2_ANIMATIONCONTROL_H_ */
