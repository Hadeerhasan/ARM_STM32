#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MRCC_Interface.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Config.h"
#include "MNVIC_Interface.h"
#include "MSTK_Interface.h"
#include "MEXTI_Interface.h"
#include "MGPIO_Private.h"

#include "file.h"

u32 i =0  ;

void App_voidPlay()
{
	MGPIOA->ODR = Amaren_raw[i];
	i++ ;
	if(i == 121635)
	{
		i=0 ;
	}

}


void main(void)
{
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step3 : Output pins  PA0 , PA7 */
	for(u8 i = 0 ; i<8 ; i++)
	{
		/*Set Pin Direction ->> Output*/
		MGPIO_voidSetPinMode(MGPIOA_PORT,i,MGPIO_MODE_OUTPUT) ;
		/*Set Pin Speed*/
		MGPIO_voidSetOutputSpeed(MGPIOA_PORT,i,MGPIO_OUTPUT_SPEED_MEDUIM) ;
		/*Pull Output Type*/
		MGPIO_voidSetOutputType(MGPIOA_PORT,i,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;
	}


	/*Step4 : Init For Systick*/
	MSTK_voidInit() ;

	/*Step5: Enable Interrupt*/
	MSTK_voidCtrlIntState(MSTK_INT_ENABLE) ;

	/*Step 6 : Set Callback*/
	 MSTK_voidCallBack(App_voidPlay) ;

	 /*Step 7: Start timer every 125 MicroSecond*/
	 MSTK_voidStart(250) ;

	/* Loop forever */
	while(1)
	{

	}

}

