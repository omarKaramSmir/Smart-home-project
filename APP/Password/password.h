/*
 * password.h
 *
 *  Created on: Aug 30, 2022
 *      Author: omark
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_
/********************************************_INCLUDES_******************************/
#include "Lcd_interface.h"
#include "Led_interface.h"
#include "Buzzer_interface.h"
#include "KeyPad_interface.h"
#include "EEPROM_int.h"
#include "util/delay.h"
#include "string.h"
/*********************************************_MACROS_*******************************/
#define FLAG_ADDRESS                     1
#define ARR_ADDRESS                      10
#define EEPROM_RELAX_TIME                100
#define NO_LOGIN_BEFORE                  5
#define AFTER_RESET                      0
#define LOGIN_BEFORE                     3
#define RESET                            1
#define SUCCESS_LOGIN                    1
#define WRONG_THREE_TRIES                3
#define PASSWORD_ENTERED_SUCCESSFULLY    4
/*******************************************_PROTOTYPES_*******************************/
void A_Password_Void_PassFunction(void);


#endif /* PASSWORD_H_ */
