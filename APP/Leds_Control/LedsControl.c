/*
 * LedsControl.c
 *
 *  Created on: Aug 30, 2022
 *      Author: omark
 */

#include "LedsControl.h"
#include "Conditioning_Operation.h"

static void A_LedsControl_Void_Static_LedsDisplayAvailableLeds(void);
static void A_LedsControl_Void_Static_LedsTurnChosenLed(u8);

void A_LedsControl_Void_LedsDisplayOPtions(void)
{
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0 ,0);
	H_Lcd_void_LcdSendString((u8*)"1-Leds ON");
	H_Lcd_void_LcdGoTo(1 ,0);
	H_Lcd_void_LcdSendString((u8*)"2-Leds OFF");
}
void A_LedsControl_Void_LedsTakeUserChoice(void)
{
	u8 Local_u8_KeypadRead=0;
	while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
	{
		//A_Conditioning_Void_CheckTemperature();
	}
	if(Local_u8_KeypadRead == '1')
	{
		A_LedsControl_Void_Static_LedsDisplayAvailableLeds();
		A_LedsControl_Void_Static_LedsTurnChosenLed(ON);
	}
	else if(Local_u8_KeypadRead == '2')
	{
		A_LedsControl_Void_Static_LedsDisplayAvailableLeds();
		A_LedsControl_Void_Static_LedsTurnChosenLed(OFF);
	}
}

void A_LedsControl_Void_Static_LedsDisplayAvailableLeds(void)
{
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0 ,0);
	H_Lcd_void_LcdSendString((u8*)"1-Blue  2-Red");
	H_Lcd_void_LcdGoTo(1 ,0);
	H_Lcd_void_LcdSendString((u8*)"3-Green 4-ALL");
}

void A_LedsControl_Void_Static_LedsTurnChosenLed(u8 Copy_u8_LedState)
{
	u8 Local_u8_KeypadRead=0;
	while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0)
	{
		//A_Conditioning_Void_CheckTemperature();
	}
	Local_u8_KeypadRead-=48;
	switch(Local_u8_KeypadRead)
	{
	case BLU_LED:
		if(Copy_u8_LedState == ON)
		{
			H_Led_void_LedOn(BLU_LED);
		}
		else if(Copy_u8_LedState == OFF)
		{
			H_Led_void_LedOff(BLU_LED);
		}
		break;

	case RED_LED:
		if(Copy_u8_LedState == ON)
		{
			H_Led_void_LedOn(RED_LED);
		}
		else if(Copy_u8_LedState == OFF)
		{
			H_Led_void_LedOff(RED_LED);
		}
		break;

	case GRN_LED:
		if(Copy_u8_LedState == ON)
		{
			H_Led_void_LedOn(GRN_LED);
		}
		else if(Copy_u8_LedState == OFF)
		{
			H_Led_void_LedOff(GRN_LED);
		}
		break;

	case ALL_LEDS:
		if(Copy_u8_LedState == ON)
		{
			H_Led_void_LedOn(GRN_LED);
			H_Led_void_LedOn(BLU_LED);
			H_Led_void_LedOn(RED_LED);
		}
		else if(Copy_u8_LedState == OFF)
		{
			H_Led_void_LedOff(GRN_LED);
			H_Led_void_LedOff(BLU_LED);
			H_Led_void_LedOff(RED_LED);
		}
		break;
	default:
		break;
	}
}
