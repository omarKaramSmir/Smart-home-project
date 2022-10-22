/*
 * password.c
 *
 *  Created on: Aug 30, 2022
 *      Author: omark
 */
#include "password.h"

static void A_Password_Void_Static_loginIN(void);
static void A_Password_Void_Static_FirstLoginIN(u8 Copy_u8_Resetflag);

u8 PassWord_u8_PassFlag=0;
u8 PassWord_u8_PassSize=0;
u8 PassWord_u8_LoginFlag=0;

void A_Password_Void_PassFunction(void)
{
	H_EEPROM_u8_ReadByte(FLAG_ADDRESS,&PassWord_u8_LoginFlag);
	_delay_ms(EEPROM_RELAX_TIME);
	if(PassWord_u8_LoginFlag == NO_LOGIN_BEFORE)//first time
	{
		while(1)
		{
			A_Password_Void_Static_FirstLoginIN(!RESET);
			if(PassWord_u8_LoginFlag ==SUCCESS_LOGIN )
			{
				H_EEPROM_u8_WriteByte(FLAG_ADDRESS,LOGIN_BEFORE);
				_delay_ms(EEPROM_RELAX_TIME);
				PassWord_u8_PassFlag=LOGIN_BEFORE;
				break;
			}
		}
	}
	else if(PassWord_u8_LoginFlag == LOGIN_BEFORE && PassWord_u8_PassFlag == AFTER_RESET)//not first time
	{
		H_Lcd_void_LcdGoTo(0 ,0);
		H_Lcd_void_LcdSendString((u8*)"PLZ,Enter pass:");
		while(1)
		{
			A_Password_Void_Static_loginIN();
			if(PassWord_u8_PassFlag == PASSWORD_ENTERED_SUCCESSFULLY)
			{
				break;
			}
		}
	}
}


void A_Password_Void_Static_FirstLoginIN(u8 Copy_u8_ResetFlag)
{
	u8 Local_u8_NewPassword[18];
	u8 Local_u8_ReEnteredPass[18] ;
	u8 Local_u8_Counter=0;
	u8 Local_u8_KeypadRead=0;
	// *****************************************************************************
	if(Copy_u8_ResetFlag != RESET)
	{
		H_Lcd_void_LcdGoTo(0 ,0);
		H_Lcd_void_LcdSendString((u8*)"it is your first");
		H_Lcd_void_LcdGoTo(1 ,0);
		H_Lcd_void_LcdSendString((u8*)"login");
		_delay_ms(2000);
	}
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0 ,0);
	H_Lcd_void_LcdSendString((u8*)"EN new password");
	H_Lcd_void_LcdGoTo(1 ,0);
	for(Local_u8_Counter=0; Local_u8_Counter<18 ;Local_u8_Counter++)
	{
		while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
		if(Local_u8_KeypadRead == '#')
		{
			Local_u8_NewPassword[Local_u8_Counter]= '\0';
			break;
		}
		else
		{
			Local_u8_NewPassword[Local_u8_Counter]=Local_u8_KeypadRead;
			H_EEPROM_u8_WriteByte((ARR_ADDRESS+PassWord_u8_PassSize),Local_u8_KeypadRead );
			_delay_ms(EEPROM_RELAX_TIME);
			PassWord_u8_PassSize+=2;
		}
		H_Lcd_void_LcdSendCharacter('*');
	}
	// *****************************************************************************
	H_Lcd_void_LcdClear();
	H_Lcd_void_LcdGoTo(0 ,0);
	H_Lcd_void_LcdSendString((u8*)"Re EN the pass");
	H_Lcd_void_LcdGoTo(1 ,0);
	for(Local_u8_Counter=0; Local_u8_Counter<18 ;Local_u8_Counter++)
	{
		while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
		if(Local_u8_KeypadRead == '#')
		{
			Local_u8_ReEnteredPass[Local_u8_Counter]= '\0';
			break;
		}
		else
		{
			Local_u8_ReEnteredPass[Local_u8_Counter]=Local_u8_KeypadRead;
		}
		H_Lcd_void_LcdSendCharacter('*');
	}
	// *****************************************************************************
	if( strcmp( Local_u8_NewPassword , Local_u8_ReEnteredPass) == 0)
	{
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString((u8*)"Success Login");
		PassWord_u8_LoginFlag=SUCCESS_LOGIN;
		_delay_ms(1000);
		H_Lcd_void_LcdClear();
	}
	else
	{
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString((u8*)"Failure Login");
		PassWord_u8_PassSize=0;
		_delay_ms(1000);
		H_Lcd_void_LcdClear();
	}
	// *****************************************************************************
}


void A_Password_Void_Static_loginIN(void)
{
	u8 Local_u8_Password[18] ;
	u8 Local_u8_EnteredPass[18] ;
	u8 Local_u8_Counter=0;
	u8 Local_u8_KeypadRead=0;
	// ****************************************************************************
	H_Lcd_void_LcdGoTo(1,0);
	for(Local_u8_Counter=0; Local_u8_Counter<18 ;Local_u8_Counter++)
	{
		while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
		if(Local_u8_KeypadRead == '#')
		{
			Local_u8_EnteredPass[Local_u8_Counter]= '\0';
			break;
		}
		else
		{
			Local_u8_EnteredPass[Local_u8_Counter]=Local_u8_KeypadRead;
		}
		H_Lcd_void_LcdSendCharacter('*');
	}
	H_Lcd_void_LcdClear();
	// ****************************************************************************
	u8 Local_u8_Counter2 = 0 ;
	for(Local_u8_Counter=0; Local_u8_Counter<(PassWord_u8_PassSize/2) ;Local_u8_Counter+=2)
	{
		Local_u8_Counter2 = 0 ;
		H_EEPROM_u8_ReadByte( (ARR_ADDRESS+Local_u8_Counter) ,&Local_u8_Password[Local_u8_Counter2 ]);
		_delay_ms(EEPROM_RELAX_TIME);
		Local_u8_Counter2 ++;
	}
	Local_u8_Password[PassWord_u8_PassSize/2]= '\0';
	// ****************************************************************************
	// in case of correct password
	if( strcmp(Local_u8_Password ,Local_u8_EnteredPass) == 0)
	{
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString((u8*)"Welcome Ahmed");
		PassWord_u8_PassFlag=PASSWORD_ENTERED_SUCCESSFULLY;
		_delay_ms(1000);
		H_Lcd_void_LcdClear();
	}
	// ****************************************************************************
	// in case of incorrect password
	else
	{
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString((u8*)"wrong password");
		PassWord_u8_PassFlag++;
		_delay_ms(1000);
		if(PassWord_u8_PassFlag == 3)
		{
			H_Lcd_void_LcdGoTo(0,0);
			H_Lcd_void_LcdSendString((u8*)"System will lock");
			H_Lcd_void_LcdGoTo(1,0);
			H_Lcd_void_LcdSendString((u8*)"for 30 seconds");
			_delay_ms(10000); //or SSD function
			PassWord_u8_PassFlag=0;

			H_Lcd_void_LcdClear();
			H_Lcd_void_LcdGoTo(0,0);
			H_Lcd_void_LcdSendString((u8*)"1-Try again?");
			H_Lcd_void_LcdGoTo(1,0);
			H_Lcd_void_LcdSendString((u8*)"or 2-Reset pass?");
			u8 Local_u8_KeypadRead=0;
			while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
			Local_u8_KeypadRead-=48;
			if(Local_u8_KeypadRead==2)
			{
				A_Password_Void_Static_FirstLoginIN(RESET);
				 PassWord_u8_PassSize=0;
			}
		}
		H_Lcd_void_LcdClear();
		H_Lcd_void_LcdGoTo(0,0);
		H_Lcd_void_LcdSendString((u8*)"Try again");
		_delay_ms(1000);
	}
}



/*
void A_Password_Void_Static_loginIN(void)
{
  u8 Local_u8_Password[4]="123";
  u8 Local_u8_EnteredPass[18] ;
  u8 Local_u8_Counter=0;
  u8 Local_u8_KeypadRead=0;

  H_Lcd_void_LcdGoTo(1,0);
  for(Local_u8_Counter=0; Local_u8_Counter<18 ;Local_u8_Counter++)
  {
    while((Local_u8_KeypadRead=H_KeyPad_void_KeyPadRead()) == 0);
    if(Local_u8_KeypadRead == '#')
    {
      Local_u8_EnteredPass[Local_u8_Counter]= '\0';
      break;
    }
    else
    {
      Local_u8_EnteredPass[Local_u8_Counter]=Local_u8_KeypadRead;
    }
    H_Lcd_void_LcdSendCharacter('*');
  }
  H_Lcd_void_LcdClear();

  //in case of correct password
  if( strcmp( Local_u8_Password , Local_u8_EnteredPass) == 0)
  {
    H_Lcd_void_LcdGoTo(0,0);
    H_Lcd_void_LcdSendString((u8*)"Welcome Ahmed");
    PassWord_u8_PassFlag=4;
    _delay_ms(1000);
    H_Lcd_void_LcdClear();
  }

  //in case of incorrect password
  else
  {
    H_Lcd_void_LcdGoTo(0,0);
    H_Lcd_void_LcdSendString((u8*)"wrong password");
    PassWord_u8_PassFlag++;
    _delay_ms(1000);
    if(PassWord_u8_PassFlag == 3)
    {
      H_Lcd_void_LcdGoTo(0,0);
      H_Lcd_void_LcdSendString((u8*)"System will lock");
      H_Lcd_void_LcdGoTo(1,0);
      H_Lcd_void_LcdSendString((u8*)"for 30 seconds");
      _delay_ms(3000);
      PassWord_u8_PassFlag=0;
    }
    H_Lcd_void_LcdClear();
    H_Lcd_void_LcdGoTo(0,0);
    H_Lcd_void_LcdSendString((u8*)"Try again");
    _delay_ms(1000);
  }
}
*/
