/*
 * Conditioning_Operation.c
 *
 *  Created on: Aug 30, 2022
 *      Author: omark
 */

#include "Conditioning_Operation.h"

void A_Conditioning_Void_CheckTemperature()
{
	u16 Local_u8_tempRead;
	if((Local_u8_tempRead=H_TempSensor_u16_Read()) <=25)
	{
		H_DC_MOTOR_void_DcMotorOFF();
	}
	else if((Local_u8_tempRead=H_TempSensor_u16_Read()) >=30)
	{
		H_DC_MOTOR_void_DcMotorFullSpeed();
		H_DC_MOTOR_void_DcMotorClockWise();
	}
	else
	{
		H_DC_MOTOR_void_DcMotorNormalSpeed();
		H_DC_MOTOR_void_DcMotorClockWise();
	}

}

