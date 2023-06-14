
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_Interface.h"

#include "USART_Private.h"
#include "USART_Interface.h"
#include "USART_Config.h"


void USART_voidInit()
{
	/*Configure Tx (PA9), Rx (PA10) as AF Pins*/
	GPIO_voidSetPinMode(GPIOA, PIN9,  AF);
	GPIO_voidSetPinMode(GPIOA, PIN10, AF);
	/*Configure Them as UART AF Pins ==> AF7*/
	GPIO_voidSetPinAlternativeFunNo(GPIOA, PIN9, AF7);
	GPIO_voidSetPinAlternativeFunNo(GPIOA, PIN10, AF7);
	/*Enable Tx*/
	SET_BIT(USART1 -> CR1,3);
	/*Enable Rx*/
	SET_BIT(USART1 -> CR1,2);
	/*Enable USART*/
	SET_BIT(USART1 -> CR1,13);
	/*Set BaudRate*/
	USART1 -> BRR = BAUDRATE;
}

void USART_voidTransmit(u8* Copy_u8DataToBeTransmitted)
{
	u8 i = 0;
	while(Copy_u8DataToBeTransmitted[i] != '\0')
	{
		USART1 -> DR = Copy_u8DataToBeTransmitted[i];
		i++;
		/*Wait until Transmission is complete*/
		while(GET_BIT(USART1 -> SR, 6) == 0);
	}
	CLR_BIT(USART1 -> SR, 6);
}

void USART_voidRecieve(u8* Copy_u8DataToBeRecieved)
{
	/*Check if there's something received or not*/
	while(GET_BIT(USART1 -> SR, 5) == 0);
	*Copy_u8DataToBeRecieved = USART1 -> DR;
	CLR_BIT(USART1 -> SR, 5);
}

 