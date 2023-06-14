
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Interface.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "SYSTICK_Interface.h"
#include "NVIC_Interface.h"

//void APP_voidDelayMs(u32 Copy_u32Delay);

#define ZERO  0x3F
#define ONE   0x06
#define TWO   0x5B
#define THREE 0x4F
#define FOUR  0x66
#define FIVE  0x6D
#define SIX   0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE  0x6F
u32 arr[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
int main()
{
	//step1 : system clk is 25MHZ from HSE
	MRCC_voidInitSystemClk();

	STK_voidInt();

	//step2 : Enable GPIO peripheral clk from PORTA
	MRCC_voidEnablePeripheralClock(AHB1,0);
	MRCC_voidEnablePeripheralClock(AHB1,1);
	MRCC_voidEnablePeripheralClock(AHB1,2);

	GPIO_voidSetPinMode(GPIOA,PIN1, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN2, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN3, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN4, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN5, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN6, OUTPUT);
		GPIO_voidSetPinMode(GPIOA,PIN7, OUTPUT);

		GPIO_voidSetPinOutputType(GPIOA,PIN1,OUTPUT_PP);
	    GPIO_voidSetPinOutputType(GPIOA,PIN2,OUTPUT_PP);
	    GPIO_voidSetPinOutputType(GPIOA,PIN3,OUTPUT_PP);
	    GPIO_voidSetPinOutputType(GPIOA,PIN4,OUTPUT_PP);
		 GPIO_voidSetPinOutputType(GPIOA,PIN5,OUTPUT_PP);
		 GPIO_voidSetPinOutputType(GPIOA,PIN6,OUTPUT_PP);
		 GPIO_voidSetPinOutputType(GPIOA,PIN7,OUTPUT_PP);

		GPIO_voidSetPinOutputSpeed(GPIOA,PIN1,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN2,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN3,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN4,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN5,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN6,OUTPUT_LS);
		GPIO_voidSetPinOutputSpeed(GPIOA,PIN7,OUTPUT_LS);



	NVIC_voidSetPriorityConfig(GROUP2BITS_SUBGROUP2BITS);
	NVIC_voidSetInterruptPriority(35,2,0);//SPI1
	NVIC_voidSetInterruptPriority(37,1,0);//USART1


	NVIC_voidEnablePeripheralInterrupt(37);
	NVIC_voidEnablePeripheralInterrupt(35);

	while (1)
    {
		NVIC_voidSetPendingFlag(37);
		NVIC_voidSetPendingFlag(36);
    }
}

USART1_IRQHandler()
{

	for(int i=0;i<10;i++)
	{
		GPIO_u32SetPortValueManual(GPIOA,arr[i]);
		STK_voidSetBadyWait(1000000);
	}

}

SPI1_IRQHandler()
{

	for(int i=9;i>=0;i--)
		{
			GPIO_u32SetPortValueManual(GPIOA,arr[i]);
			STK_voidSetBadyWait(1000000);
		}
}





