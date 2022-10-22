/*
 * LedsControl.h
 *
 *  Created on: Aug 30, 2022
 *      Author: omark
 */

#ifndef LEDSCONTROL_H_
#define LEDSCONTROL_H_

/********************************************_INCLUDES_******************************/
#include "Lcd_interface.h"
#include "Led_interface.h"
#include "KeyPad_interface.h"
#include "util/delay.h"
/*********************************************_MACROS_*******************************/
#define ALL_LEDS   4
#define ON         1
#define OFF        0
/*******************************************_PROTOTYPES_*******************************/
void A_LedsControl_Void_LedsDisplayOPtions(void);
void A_LedsControl_Void_LedsTakeUserChoice(void);


#endif /* LEDSCONTROL_H_ */
