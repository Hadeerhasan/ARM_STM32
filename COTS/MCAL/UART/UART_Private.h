#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/*USART1 Bus: APB2, USART6 Bus: APB2, USART2 Bus: APB1*/
/*USART1 Base Address: 0x40011000, USART6 Base Address: 0x40011400, USART2 Base Address: 0x40004400*/
typedef struct 
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;
}USART_t;

#define USART1         ((volatile USART_t*)0x40011000UL)
//#define USART2       ((USART_t*)0x40004400)
//#define USART6       ((USART_t*)0x40011400)


/*Private Macros*/


#endif
