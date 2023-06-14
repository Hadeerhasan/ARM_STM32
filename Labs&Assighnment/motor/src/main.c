
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

#include "SYSTICK_Interface.h"
#include "SYSTICK_Config.h"
#include "SYSTICK_Private.h"

void forward(void);
void back(void);
void right(void);
void left(void);
void stop(void);

int main()
{
	MRCC_voidInitSystemClk();
	STK_voidInt();

	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	GPIO_voidSetPinMode(GPIOA,PIN3,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN4,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN5,OUTPUT);
	GPIO_voidSetPinMode(GPIOA,PIN6,OUTPUT);

	GPIO_voidSetPinOutType(GPIOA,PIN3,OUTPUT_PP);
	GPIO_voidSetPinOutType(GPIOA,PIN4,OUTPUT_PP);
	GPIO_voidSetPinOutType(GPIOA,PIN6,OUTPUT_PP);
	GPIO_voidSetPinOutType(GPIOA,PIN5,OUTPUT_PP);

	GPIO_voidSetPinOutSpeed(GPIOA,PIN3,OUTPUT_MS);
	GPIO_voidSetPinOutSpeed(GPIOA,PIN4,OUTPUT_MS);
	GPIO_voidSetPinOutSpeed(GPIOA,PIN6,OUTPUT_MS);
	GPIO_voidSetPinOutSpeed(GPIOA,PIN5,OUTPUT_MS);


	while(1)
    {
		stop();
		STK_voidSetBadyWait(1000000UL);
		forward();
		STK_voidSetBadyWait(1000000UL);
		back();
		STK_voidSetBadyWait(1000000UL);
		right();
		STK_voidSetBadyWait(1000000UL);
		left();
		STK_voidSetBadyWait(1000000UL);
    }
}

void forward(void)
{

	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN3,HIGH);
	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN4,LOW);
	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN5,HIGH);
	   GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,LOW);

}

void back(void)
{
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN3,LOW);
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN4,HIGH);
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN5,LOW);
	GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,HIGH);
}

void right(void)
{
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN3,HIGH);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN4,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN5,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,LOW);

}
void left(void)
{
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN3,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN4,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN5,HIGH);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,LOW);

}
void stop(void)
{
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN3,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN4,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN5,LOW);
	 GPIO_voidSetPinValueNonAtumic(GPIOA,PIN6,LOW);

}


