#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
void APP_voidDelayMs(u32 Copy_u32Delay);

int main()
{
	MRCC_voidInitSystemClk();

	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	GPIO_voidSetPinMode(GPIOA,PIN5,OUTPUT);
	GPIO_voidSetPinOutputType(GPIOA,PIN5,OUTPUT_PP);
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN5,OUTPUT_MS);

	while(1)
    {
	   GPIO_voidSetPinValue(GPIOA,PIN5,HIGH);
	   APP_voidDelayMs(10000);
	   GPIO_voidSetPinValue(GPIOA,PIN5,LOW);
	   APP_voidDelayMs(10000);
    }
}

void APP_voidDelayMs(u32 Copy_u32Delay)
{

   for(u32 i = 0 ; i <Copy_u32Delay * 300; i++ )
   {
	   asm("NOP") ;
   }
}
