
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Interface.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "SYSTICK_Interface.h"
#include "NVIC_Interface.h"

//void APP_voidDelayMs(u32 Copy_u32Delay);

int main()
{
	//step1 : system clk is 25MHZ from HSE
	MRCC_voidInitSystemClk();

	STK_voidInt();

	//step2 : Enable GPIO peripheral clk from PORTA
	MRCC_voidEnablePeripheralClock(AHB1,0);

	GPIO_voidSetPinMode(GPIOA,PIN0,OUTPUT);
	GPIO_voidSetPinOutputType(GPIOA,PIN0,OUTPUT_PP);
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN0,OUTPUT_LS );
	NVIC_voidEnablePeripheralInterrupt(6);
	while (1)
    {
		NVIC_voidSetPendingFlag(6);
    }
}

EXTI0_IRQHandler()
{

	GPIO_voidSetPinValue(GPIOA,PIN0,HIGH);
	STK_voidSetBadyWait(10000000);
	GPIO_voidSetPinValue(GPIOA,PIN0,LOW);
	STK_voidSetBadyWait(10000000);
}





