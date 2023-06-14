#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"

#include "GPIO_Interface.h"
#include "GPIO_Config.h"
#include "GPIO_Private.h"
void APP_voidDelayMs(u32 Copy_u32Delay);

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

u32 i;
int main()
{

	MRCC_voidInitSystemClk();

	MRCC_voidEnablePeripheralClock(AHB1 , 0);
	u32 arr[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	/*GPIO_voidSetPortMode(GPIOA, OUTPUT);
	GPIO_voidSetPortType(GPIOA,OUTPUT_PP);
	GPIO_voidSetPortSpeed(GPIOA,OUTPUT_LS);*/
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

	/*GPIO_voidSetPinValue(GPIOA , PIN0 ,HIGH);    // a
	GPIO_voidSetPinValue(GPIOA , PIN1 , HIGH);    //b
	GPIO_voidSetPinValue(GPIOA , PIN2 , HIGH);    //c
	GPIO_voidSetPinValue(GPIOA , PIN3 , HIGH);    //d
	GPIO_voidSetPinValue(GPIOA , PIN4 , HIGH);    //e
	GPIO_voidSetPinValue(GPIOA , PIN5 , HIGH);    //f
	GPIO_voidSetPinValue(GPIOA , PIN6 , HIGH);    // g*/

	while(1)
    {
		for (i=0;i<10;i++)
				{
					GPIO_u32SetPortValueManual(GPIOA,arr[i]);
					APP_voidDelayMs(10000);
				}
		/*GPIO_voidSetPinValue(GPIOA , PIN0 ,HIGH);    // a
			GPIO_voidSetPinValue(GPIOA , PIN1 , HIGH);    //b
			GPIO_voidSetPinValue(GPIOA , PIN2 , HIGH);    //c
			GPIO_voidSetPinValue(GPIOA , PIN3 , HIGH);    //d
			GPIO_voidSetPinValue(GPIOA , PIN4 , HIGH);    //e
			GPIO_voidSetPinValue(GPIOA , PIN5 , HIGH);    //f
			GPIO_voidSetPinValue(GPIOA , PIN6 , LOW);    // g
			APP_voidDelayMs(5000);

			GPIO_voidSetPinValue(GPIOA , PIN0 ,LOW);    // a
				GPIO_voidSetPinValue(GPIOA , PIN1 , HIGH);    //b
				GPIO_voidSetPinValue(GPIOA , PIN2 , HIGH);    //c
				GPIO_voidSetPinValue(GPIOA , PIN3 , LOW);    //d
				GPIO_voidSetPinValue(GPIOA , PIN4 ,LOW);    //e
				GPIO_voidSetPinValue(GPIOA , PIN5 , LOW);    //f
				GPIO_voidSetPinValue(GPIOA , PIN6 , LOW);    // g
				APP_voidDelayMs(5000);

			GPIO_voidSetPinValue(GPIOA , PIN0 ,HIGH);    // a
			GPIO_voidSetPinValue(GPIOA , PIN1 , HIGH);    //b
			GPIO_voidSetPinValue(GPIOA , PIN2 , LOW);    //c
			GPIO_voidSetPinValue(GPIOA , PIN3 , HIGH);    //d
			GPIO_voidSetPinValue(GPIOA , PIN4 , HIGH);    //e
			GPIO_voidSetPinValue(GPIOA , PIN5 , LOW);    //f
			GPIO_voidSetPinValue(GPIOA , PIN6 , HIGH);    // g
			APP_voidDelayMs(5000);*/

    }
}

void APP_voidDelayMs(u32 Copy_u32Delay)
{

   for(u32 i = 0 ; i <Copy_u32Delay * 300; i++ )
   {
	   asm("NOP") ;
   }
}



