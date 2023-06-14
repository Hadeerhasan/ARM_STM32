#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"

/* Global variable to use it in setting the priority of interrupt */
static u8 StaticGlobal_u8PriorityConfig;

/* this function takes the id of the interrupt then use it to [[ Enable ]] the desired interrupt */
void NVIC_voidEnablePeripheralInterrupt(u8 Copy_u8INTID)
{
    NVIC -> ISER[Copy_u8INTID / 32] = ( 1 << (Copy_u8INTID % 32));
}

/* this function takes the id of the interrupt then use it to [[ Disable ]] the desired interrupt */
void NVIC_voidDisablePeripheralInterrupt(u8 Copy_u8INTID)
{
    NVIC -> ICER[Copy_u8INTID / 32] = ( 1 << (Copy_u8INTID % 32));
}

/* this function takes the id of the interrupt then use it to [[ SET ]] the pending flag */
void NVIC_voidSetPendingFlag(u8 Copy_u8INTID)
{
    NVIC -> ISPR[Copy_u8INTID / 32] = ( 1 << (Copy_u8INTID % 32));
}

/* this function takes the id of the interrupt then use it to [[ CLEAR ]] the pending flag */
void NVIC_voidClearPendingFlag(u8 Copy_u8INTID)
{
    NVIC -> ICPR[Copy_u8INTID / 32] = ( 1 << (Copy_u8INTID % 32));
}

/* by taking the argument from the user which can be :- 
GROUP4BITS_SUBGROUP0BITS which mapps to 3
GROUP3BITS_SUBGROUP1BITS which mapps to 4
GROUP2BITS_SUBGROUP2BITS which mapps to 5
GROUP1BITS_SUBGROUP3BITS which mapps to 6
GROUP0BITS_SUBGROUP4BITS which mapps to 7
-----------------------------------------
we configure it in the [[ SCB ->AIRCR ]] so we know how many groups and subgroups are needed */
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption)
{
    StaticGlobal_u8PriorityConfig = 0x05FA0000 | (Copy_u8PriorityOption << 8);
    SCB ->AIRCR = StaticGlobal_u8PriorityConfig;
}

/* this function is used to finally set each priority group number and subgroup number */
/* and that by using the previous function to configure the number of groups and subgroups */
void NVIC_voidSetInterruptPriority(u8 Copy_u8INTID, u8 Copy_u8GroupID, u8 Copy_u8SubGroupID)
{
    u8 local_u8Priority = Copy_u8SubGroupID | (Copy_u8GroupID << ((StaticGlobal_u8PriorityConfig - 0x05FA0300)/256));
    NVIC -> IPR[Copy_u8INTID] = (local_u8Priority << 4);
}
