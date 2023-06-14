#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void NVIC_voidEnablePeripheralInterrupt(u8 Copy_u8INTID);
void NVIC_voidDisablePeripheralInterrupt(u8 Copy_u8INTID);
void NVIC_voidSetPendingFlag(u8 Copy_u8INTID);
void NVIC_voidClearPendingFlag(u8 Copy_u8INTID);
void NVIC_voidSetPriorityConfig(u8 Copy_u8PriorityOption);
void NVIC_voidSetInterruptPriority(u8 Copy_u8INTID, u8 Copy_u8GroupID, u8 Copy_u8SubGroupID);


#define GROUP4BITS_SUBGROUP0BITS        0B011
#define GROUP3BITS_SUBGROUP1BITS        0B100
#define GROUP2BITS_SUBGROUP2BITS        0B101
#define GROUP1BITS_SUBGROUP3BITS        0B110
#define GROUP0BITS_SUBGROUP4BITS        0B111

#endif
