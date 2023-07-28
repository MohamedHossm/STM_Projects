/*****************************************************************************/
/* Author         : Mohamed Hoasm                                                    */
/* Date           : 16/7/2023                                                        */
/* Version        : 1.0                                                              */
/*sw              : Button                                                            */
/*****************************************************************************/
#ifndef HBUTTON_H_
#define HBUTTON_H_

#define _u8BUTTON_PIN_ Pin_B0

Error_t HBUTTON_u8Init() ;

Error_t HBUTTON_u8GetRead(u8* ptr_ReturnValue) ;

#endif /* HBUTTON_H_ */
