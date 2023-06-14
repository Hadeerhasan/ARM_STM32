#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

typedef struct 
{
    volatile u32 ISER[32]; // we only need 8 [[ISER0 - ISER7]] but between each register and the next one there is a reserved 24 address
    volatile u32 ICER[32]; // so instead of using 8 and and res[24] we merge them together to make it easier to read and handle
    volatile u32 ISPR[32]; // *
    volatile u32 ICPR[32]; // *
    volatile u32 IABR[32]; // *
    volatile u32 RES[32]; // reserved section
    volatile u8 IPR[90]; // cuz i only have almost 80 interrupts so i dont need to make space for the whole 240 [[ it will be useless ]]
}NVIC_t;

#define NVIC    ((volatile NVIC_t*)0xE000E100)

typedef struct 
{
    volatile u32 CPUID;  
    volatile u32 ICSR;
    volatile u32 VTOR;
    volatile u32 AIRCR;
    volatile u32 SCR;
    volatile u32 CCR;    
    volatile u32 SHPR[3];
    volatile u32 SHCSR;  
    volatile u32 CFSR;
    volatile u32 HFSR;
    volatile u32 RESERVED;
    volatile u32 MMFAR;
    volatile u32 BFAR;   

}SCB_t;

#define SCB    ((volatile SCB_t*)0xE000ED00)

#endif
