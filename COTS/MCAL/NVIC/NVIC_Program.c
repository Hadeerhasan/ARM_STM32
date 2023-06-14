#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

#define     VECTKEY     0x05FA0000

void NVIC_voidEnableInterrupt(u32 copy_u32Value)
{
    NVIC_REG->ISER[copy_u32Value/32]=(1<<(copy_u32Value%32));
}			
void NVIC_voidDisableInterrupt(u32 copy_u32Value)
{
    NVIC_REG->ICER[copy_u32Value/32]=(1<<(copy_u32Value%32));
}		
void NVIC_voidEnableInterruptPending(u32 copy_u32Value)   // set pending
{
    NVIC_REG->ISPR[copy_u32Value/32]=(1<<(copy_u32Value%32));
}			
void NVIC_voidDisableInterruptPending(u32 copy_u32Value)   //clear pending
{
    NVIC_REG->ICPR[copy_u32Value/32]=(1<<(copy_u32Value%32));
}
void NVIC_SetPriortiyConfiguration(u8 Copy_PriortiyOption)
{
    staticglobal_u8PeriodityConf= VECT_KEY | (Copy_PriortiyOption<<8);
	SCB -> AIRCR = staticglobal_u8PeriodityConf;

}
void NVIC_SetIntPriortiy(u8 Copy_IntId , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId)
{
   u8 Local_u8Priority = Copy_u8SubGroupId |(Copy_u8GroupId<<(staticglobal_u8PeriodityConf-0x05FA0300)/256);
	NVIC_REG -> IPR [Copy_IntId] = (Local_u8Priority<<4);
}
