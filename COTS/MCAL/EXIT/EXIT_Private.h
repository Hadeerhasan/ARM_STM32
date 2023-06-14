#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

//EXTI BASEADDRESS --> 0x40013C00
typedef struct 
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI        ((volatile EXTI_t*)0x40013C00)

typedef struct 
{
    volatile u32 MEMRMP;
    volatile u32 PMC;
    volatile u32 EXTICR1;
    volatile u32 EXTICR2;
    volatile u32 EXTICR3;
    volatile u32 EXTICR4;
    volatile u32 CMPCR;
}SYSCFG_t;

#define SYSCFG      ((volatile SYSCFG_t*)0x40013800)


#define FALLING_EDGE            0
#define RISING_EDGE             1
#define ON_CHANGE               2

#define EXTI_LINE0             0
#define EXTI_LINE1             1
#define EXTI_LINE2             2
#define EXTI_LINE3             3
#define EXTI_LINE4             4
#define EXTI_LINE5             5
#define EXTI_LINE6             6
#define EXTI_LINE7             7
#define EXTI_LINE8             8
#define EXTI_LINE9             9
#define EXTI_LINE10            10
#define EXTI_LINE11            11
#define EXTI_LINE12            12
#define EXTI_LINE13            13
#define EXTI_LINE14            14
#define EXTI_LINE15            15


#define EXTI_PA                 0
#define EXTI_PB                 1
#define EXTI_PC                 2

#endif
