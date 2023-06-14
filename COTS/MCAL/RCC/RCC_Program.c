#include "..\..\LIB\STD_TYPES.h"
#include "..\..\LIB\BIT_MATH.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

#define HSE_ON 16

void RCC_voidInitSysCLK(void)
{
    #if   RCC_SYSCLKSRC == HSE_CRYSTAL

    /** Enable HSE **/
    SET_BIT(RCC_CR,HSE_ON);

    /** disable Bypass **/
    CLR_BIT(RCC_CR,18);

    /** system clk source = HSE **/
    SET_BIT(RCC_CFGR,0);
    CLR_BIT(RCC_CFGR,1);

    #elif RCC_SYSCLKSRC == HSE_RC

    /** Enable HSE **/
    SET_BIT(RCC_CR,HSE_ON);

    /** Enable Bypass **/
    SET_BIT(RCC_CR,18);

    /** system clk source = HSE **/
    SET_BIT(RCC_CFGR,0);
    CLR_BIT(RCC_CFGR,1);

    #elif RCC_SYSCLKSRC == HSI
    
    /** Enable HSI **/
    SET_BIT(RCC_CR,0);

    /** system clk source = HSI **/
    CLR_BIT(RCC_CFGR,0);
    CLR_BIT(RCC_CFGR,1);

    #elif RCC_SYSCLKSRC == PLL
    /****/
    #else
        #error "Invalid Option selected for CLK"
    #endif 
    SET_BIT(RCC_CFGR, 7);   
}

void RCC_voidEnablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
    //validation
    if(Copy_u8PeripheralID > 31)
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHP1:  SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);     break;
            case AHP2:  SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);     break;
            case APB1:  SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);     break;
            case APB2:  SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);     break;
            default:                                                  break;
        }
    }


}

void RCC_voidDisablePeripheralClk(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
if(Copy_u8PeripheralID > 31)
    {
        /*Do nothing*/
    }
    else
    {
        switch(Copy_u8BusID)
        {
            case AHP1:  CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralID);     break;
            case AHP2:  CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralID);     break;
            case APB1:  CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID);     break;
            case APB2:  CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID);     break;
            default:                                                  break;
        }
    }
}
