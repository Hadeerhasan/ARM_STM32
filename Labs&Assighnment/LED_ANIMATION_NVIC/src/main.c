
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
	GPIO_voidSetPinMode(GPIOA,PIN1,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN2,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN3,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN4,OUTPUT);

	GPIO_voidSetPinOutputType(GPIOA,PIN0,OUTPUT_PP);
	GPIO_voidSetPinOutputType(GPIOA,PIN1,OUTPUT_PP);
	GPIO_voidSetPinOutputType(GPIOA,PIN2,OUTPUT_PP);
	GPIO_voidSetPinOutputType(GPIOA,PIN3,OUTPUT_PP);
	GPIO_voidSetPinOutputType(GPIOA,PIN4,OUTPUT_PP);

	GPIO_voidSetPinOutputSpeed(GPIOA,PIN0,OUTPUT_LS );
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN1,OUTPUT_LS );
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN2,OUTPUT_LS );
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN3,OUTPUT_LS );
	GPIO_voidSetPinOutputSpeed(GPIOA,PIN4,OUTPUT_LS );

	NVIC_voidEnablePeripheralInterrupt(7);
	while (1)
    {
		NVIC_voidSetPendingFlag(7);
    }
}


EXTI1_IRQHandler()
{

	GPIO_voidSetPinValue(GPIOA,PIN1,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN2,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN3,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN4,HIGH);

	STK_voidSetBadyWait(10000);
	GPIO_voidSetPinValue(GPIOA,PIN1,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN2,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN3,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN4,HIGH);

	STK_voidSetBadyWait(10000);
	GPIO_voidSetPinValue(GPIOA,PIN1,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN2,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN3,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN4,LOW);

	STK_voidSetBadyWait(10000);
	GPIO_voidSetPinValue(GPIOA,PIN1,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN2,HIGH);
	GPIO_voidSetPinValue(GPIOA,PIN3,LOW);
	GPIO_voidSetPinValue(GPIOA,PIN4,HIGH);
	STK_voidSetBadyWait(10000);
}



