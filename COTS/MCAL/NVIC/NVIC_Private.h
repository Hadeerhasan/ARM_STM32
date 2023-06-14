#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

 
//base address 0xE000E100
#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct 
{
  volatile u32 ISER[32],        //32-> (8->register)&(24->reserved)
  volatile u32 ICER[32],
  volatile u32 ISPR[32],
  volatile u32 ICPR[32],
  volatile u32 IAPR[32],
  volatile u32 RESERVED[32],
  volatile u32 IPR[32],

}NVIC_t;
#define NVIC_REG ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

SCB Base Address --> 0xE000ED00
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

#define SCB		((volatile SCB_t*)0xE000ED00)


#endif