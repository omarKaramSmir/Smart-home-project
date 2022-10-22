/*
 * DC_MOTOR_Program.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Eng.Hazem
 */

#include "DC_MOTOR_Interface.h"
void H_DC_MOTOR_void_DcMotorInit(void)
{
	/*CONFIGRE INPUT PIN FOR L239D*/
	M_Dio_void_PinMode(DC_MOTOR_INPUT_1,OUTPUT);
	M_Dio_void_PinMode(DC_MOTOR_INPUT_2,OUTPUT);
	/*CONFIGRE PIN OC0 AS OUTPUT */
	M_Dio_void_PinMode(PB3_PIN,OUTPUT);
	/*INTIAILZE TIMER FOR PWM TO CONTROL SPEED OF MOTOR*/
	M_Timer_0_void_Init();
	M_Timer_0_void_Start();
}
void H_DC_MOTOR_void_DcMotorAntiClockWise(void)
{
	/*MAKE MOTOR MOVE ANTICLOCKWISE*/
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,HIGH);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,LOW);
}
void H_DC_MOTOR_void_DcMotorClockWise(void)
{
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,HIGH);
}
void H_DC_MOTOR_void_DcMotorOFF(void)
{
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_1,LOW);
	M_Dio_void_PinWrite(DC_MOTOR_INPUT_2,LOW);
}
void H_DC_MOTOR_void_DcMotorFullSpeed(void)
{
	M_Timer_0_SetFastPWM(100);
}
void H_DC_MOTOR_void_DcMotorNormalSpeed(void)
{
	M_Timer_0_SetFastPWM(50);
}
