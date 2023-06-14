
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"

#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"

int main()
{
	MRCC_voidInitSystemClk();
	STK_voidInt();

	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	GPIO_voidSetPinMode(GPIOA,PIN6,OUTPUT);
	GPIO_voidSetPinOutType(GPIOA,PIN6,OUTPUT_PP);
	GPIO_voidSetPinOutSpeed(GPIOA,PIN6,OUTPUT_MS);

	while(1)
    {
	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,HIGH);
	   STK_voidSetBadyWait(1000000UL);
	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,LOW);
	   STK_voidSetBadyWait(1000000UL);
    }
}





