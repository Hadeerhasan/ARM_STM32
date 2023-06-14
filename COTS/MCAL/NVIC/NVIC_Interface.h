#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#define NVIC_GroupMode_g16s0  3
#define NVIC_GroupMode_g8s2   4
#define NVIC_GroupMode_g4s4   5
#define NVIC_GroupMode_g2s8   6
#define NVIC_GroupMode_g0s16  7  

void NVIC_voidEnableInterrupt(u32 copy_u32Value);			
void NVIC_voidDisableInterrupt(u32 copy_u32Value);			
void NVIC_voidEnableInterruptPending(u32 copy_u32Value);			
void NVIC_voidDisableInterruptPending(u32 copy_u32Value);
void NVIC_SetPriortiyConfiguration(u8 Copy_PriortiyOption);
void NVIC_SetIntPriortiy(u8 Copy_IntId , u8 Copy_u8GroupId , u8 Copy_u8SubGroupId);


#endif