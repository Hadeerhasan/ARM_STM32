

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MGPIO_Interface.h"
#include "MSTK_Interface.h"


#include "TFT_Interface.h"
#include "TFT_Config.h"
#include "TFT_Private.h"


void TFT_voidInit(void) 
{
	u8 Data;
	//REST PULSE
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidDelayMs(10);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_voidDelayMs(1);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidDelayMs(10);
	GPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	STK_voidDelayMs(10);
	GPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	STK_voidDelayMs(12);

	//send command sleep out
	TFT_voidWriteCommand(0x11);
	STK_voidDelayMs(150);

	//Color mode command
	TFT_voidWriteCommand(0x3A);
	//RGB565
	TFT_voidWriteData(0x05);

	//display command
	TFT_voidWriteCommand(0x29);


}

void TFT_voidDisplayImage(const u16 *Copy_u16ptrImage) ;
//set x address
TFT_voidWriteCommand(0x2A);
//start
TFT_voidWriteData(0);
TFT_voidWriteData(0);
//end
TFT_voidWriteData(0);
TFT_voidWriteData(127);

//set y adress
TFT_voidWriteCommand(0x2B);
//start
TFT_voidWriteData(0);
TFT_voidWriteData(0);
//end
TFT_voidWriteData(0);
TFT_voidWriteData(159);

//RAN write command(save data in ram)
TFT_voidWriteCommand(0x2C);

//display  Image
for(u16 count=0;count<=20480;count++)
{
	Data=Copy_u16ptrImage[count]>>8;
	TFT_voidWriteData(Data);
	Data=(u8)Copy_u16ptrImage[count];
	TFT_voidWriteData(Data);

}


}

void TFT_voidWriteCommand(u8 copy_u8Command)
{
	GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	(void)SPI_u8SendRecive(Copy_u8Comand);
}
void TFT_voidWriteData(u8 copy_u8Data)
{
	GPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	(void)SPI_u8SendRecive(copy_u8Data);
}