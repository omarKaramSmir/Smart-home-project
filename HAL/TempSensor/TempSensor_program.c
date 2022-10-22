


#include "TempSensor_interface.h"

void H_TempSensor_void_Init(void)
{
	M_Dio_void_PinMode(PA0_PIN,INPUT);
	M_ADC_void_Init();
}
u16  H_TempSensor_u16_Read(void)
{
	u16 Local_u16_Temp = (M_ADC_void_Read() * (u32)500 ) / 1023;
	return Local_u16_Temp;
}

