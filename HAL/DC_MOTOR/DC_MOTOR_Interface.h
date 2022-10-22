/*
 * DC_MOTOR_Interface.h
 *
 *  Created on: Aug 28, 2022
 *      Author: Eng.Hazem
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#define HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_
#include "Dio_Interface.h"
#include "Timer_0_interface.h"
#include "StandardTypes.h"
#include "DC_MOTOR_Configration.h"
#include "DC_MOTOR_Private.h"
#include "BitMath.h"
void H_DC_MOTOR_void_DcMotorInit(void);
void H_DC_MOTOR_void_DcMotorAntiClockWise(void);
void H_DC_MOTOR_void_DcMotorClockWise(void);

void H_DC_MOTOR_void_DcMotorOFF(void);
void H_DC_MOTOR_void_DcMotorFullSpeed(void);
void H_DC_MOTOR_void_DcMotorNormalSpeed(void);
#endif /* HAL_DC_MOTOR_DC_MOTOR_INTERFACE_H_ */
