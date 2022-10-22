/*
 * main.c

 *
 *  Created on: Aug 29, 2022
 *      Author: zeyad
 */


/********************************************_INCLUDES_***********************/
#include "password.h"
#include "LedsControl.h"
#include "Conditioning_Operation.h"

int main()
{
	/*********************************INITIALIZATION******************************/
	H_Lcd_void_LcdInit();
	H_KeyPad_void_KeyPadInit();
	H_Buzzer_void_BuzzerInit();
	H_TempSensor_void_Init();
	H_Led_void_LedInit(BLU_LED);
	H_Led_void_LedInit(RED_LED);
	H_Led_void_LedInit(GRN_LED);

	extern u8 PassWord_u8_PassFlag ;
	H_EEPROM_void_Init();

	u8 data ;
	H_EEPROM_u8_ReadByte(FLAG_ADDRESS, &data);
	_delay_ms(EEPROM_RELAX_TIME);
	if(data != NO_LOGIN_BEFORE && data != LOGIN_BEFORE  )
	{
		H_EEPROM_u8_WriteByte(FLAG_ADDRESS,NO_LOGIN_BEFORE);
		_delay_ms(EEPROM_RELAX_TIME);
	}



	/***********************************APPLICATION**********************************/
	H_DC_MOTOR_void_DcMotorInit();
	M_Timer_2_void_Init();
	M_Timer_2_void_SetTime(1000);
	/*
	 * Conditioning operation function
	 */
	M_Timer_2_void_SetCallBack(A_Conditioning_Void_CheckTemperature,TIMER2_COMP_MATCH_INT_ID);
	M_Timer_2_void_EnableInt(TIMER2_COMP_MATCH_INT_ID);
    M_Timer_2_void_Start();


	while(1)
	{
		// if the user hasnot entered the password before then let him in.
		if(PassWord_u8_PassFlag != PASSWORD_ENTERED_SUCCESSFULLY) //this flag will be 4 only if user entered the password before
		{
			/*
			 *A_Password_Void_PassFunction :the user will be let out this function
			 *if he enter the correct password only.
			 */
			A_Password_Void_PassFunction();
		}

		/*
		 *A_LedsControl_Void_LedsDisplayOPtions: this funtion display the leds options on lcd
		 */
		A_LedsControl_Void_LedsDisplayOPtions();
		/*
		 *A_LedsControl_Void_LedsTakeUserChoice:after the user choice the led option
		 *this function display to him which led to make changes to it ,take his choice& do it
		 */
		A_LedsControl_Void_LedsTakeUserChoice();
	}
}

