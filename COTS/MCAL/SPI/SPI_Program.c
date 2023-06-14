
#include "BIT_MATH.h"
#include "STD_TYPE.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"



void SPI_voidMasterInit(void)
{
	//select master mode
	SET_BIT(SPI_u8_SPCR_REG , 4);
	//select MSB to be sent first
	CLR_BIT(SPI_u8_SPCR_REG, 5);
	//select Rising edge
	CLR_BIT(SPI_u8_SPCR_REG , 3);
	//sampling at leading edge
	CLR_BIT(SPI_u8_SPCR_REG ,2);
	//select prescaller
	SET_BIT(SPI_u8_SPCR_REG,0);
	CLR_BIT(SPI_u8_SPCR_REG,1);
	CLR_BIT(SPI_u8_SPSR_REG,0);
	//enable spi
	SET_BIT(SPI_u8_SPCR_REG ,6);
}


void SPI_voidSlaveInit(void)
{
	//select Slave mode
	CLR_BIT(SPI_u8_SPCR_REG , 4);
	//select MSB to be sent first
	CLR_BIT(SPI_u8_SPCR_REG, 5);
	//select Rising edge
	CLR_BIT(SPI_u8_SPCR_REG , 3);
	//sampling at leading edge
	CLR_BIT(SPI_u8_SPCR_REG ,2);
	//enable spi
	SET_BIT(SPI_u8_SPCR_REG ,6);
}


u8 SPI_u8Tranceive(u8 Copy_u8Data)
{
	//set the data to reg
	SPI_u8_SPDR_REG	 = Copy_u8Data ;
	//polling
	while((GET_BIT(SPI_u8_SPSR_REG,7))==0);
	//clear flag
	SET_BIT(SPI_u8_SPSR_REG ,7);
	//read date

	return SPI_u8_SPDR_REG ;
}








