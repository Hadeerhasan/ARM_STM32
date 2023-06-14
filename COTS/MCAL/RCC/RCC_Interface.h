#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

//select system clk
void RCC_voidInitSysCLK(void);
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);

#define AHP1    0
#define AHP2    1
#define APB1    2
#define APB2    3




#endif