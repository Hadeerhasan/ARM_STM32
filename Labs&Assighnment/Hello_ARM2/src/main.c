

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"


void APP_voidDelayMs(u32 Copy_u32Delay);


#define GPIOA_MODER	   (*((volatile u32*)(0x40020000)))//input or output

#define GPIOA_ODR	   (*((volatile u32*)(0x40020014)))// high or low

void main(void)
{

	/*Step 1 : System Clock is 25 MHz From HSE*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1 , 0);

	/*Step 3 : Configur pin A0 as output pin*/
	SET_BIT(GPIOA_MODER	,0);

	/*Step 4 : Configur pin A0 as  pin High*/
	SET_BIT(GPIOA_ODR , 0);

	while(1)
	{

		/*Step 5 : Toggle LED */
		CLR_BIT(GPIOA_ODR , 0);
		APP_voidDelayMs(10000);
		SET_BIT(GPIOA_ODR , 0);
		APP_voidDelayMs(10000);


	}

}

/******************************************Function Implementation *******************************/
void APP_voidDelayMs(u32 Copy_u32Delay)
{

   for(u32 i = 0 ; i <Copy_u32Delay * 300; i++ )
   {
	   asm("NOP") ;
   }
}
