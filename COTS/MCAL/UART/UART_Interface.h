#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit();
void USART_voidTransmit(u8* Copy_u8DataToBeTransmitted);
void USART_voidRecieve(u8* Copy_u8DataToBeRecieved);

#endif
