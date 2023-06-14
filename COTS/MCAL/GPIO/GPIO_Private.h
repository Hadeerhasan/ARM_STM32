


/***********************************************************************/
/*             guard of file will call one time in .c file             */
/***********************************************************************/

             
#ifndef GPIO_PRIVAITE_H_
#define GPIO_PRIVAITE_H_


//Registers of GPIO
#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

 /*Registers Description for GPIOA*/
#define GPIOA_MODER          *((volatile u32*)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_OTYPER         *((volatile u32*)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_OSPEEDR        *((volatile u32*)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_PUPDR          *((volatile u32*)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_IDR            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_ODR            *((volatile u32*)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_BSRR           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x18))
#define GPIOA_LCKR           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x1C))
#define GPIOA_AFRL           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x20))
#define GPIOA_AFRH           *((volatile u32*)(GPIOA_BASE_ADDRESS+0x24))
#define GPIOA_AFR            *((volatile f64*)(GPIOA_BASE_ADDRESS+0x20))

/*Registers Description for GPIOB*/
#define GPIOB_MODER          *((volatile u32*)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_OTYPER         *((volatile u32*)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_OSPEEDR        *((volatile u32*)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_PUPDR          *((volatile u32*)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_IDR            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_ODR            *((volatile u32*)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_BSRR           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x18))
#define GPIOB_LCKR           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x1C))
#define GPIOB_AFRL           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x20))
#define GPIOB_AFRH           *((volatile u32*)(GPIOB_BASE_ADDRESS+0x24))
#define GPIOB_AFR            *((volatile f64*)(GPIOB_BASE_ADDRESS+0x20))

/*Registers Description for GPIOC*/
#define GPIOC_MODER          *((volatile u32*)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_OTYPER         *((volatile u32*)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_OSPEEDR        *((volatile u32*)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_PUPDR          *((volatile u32*)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_IDR            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_ODR            *((volatile u32*)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_BSRR           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x18))
#define GPIOC_LCKR           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x1C))
#define GPIOC_AFRL           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x20))
#define GPIOC_AFRH           *((volatile u32*)(GPIOC_BASE_ADDRESS+0x24))
#define GPIOC_AFR            *((volatile f64*)(GPIOC_BASE_ADDRESS+0x20))


#define GPIOA                     0
#define GPIOB                     1
#define GPIOC                     2

#define PIN0                      0
#define PIN1                      1
#define PIN2                      2
#define PIN3                      3
#define PIN4                      4
#define PIN5                      5
#define PIN6                      6
#define PIN7                      7
#define PIN8                      8
#define PIN9                      9
#define PIN10                     10
#define PIN11                     11
#define PIN12                     12
#define PIN13                     13
#define PIN14                     14
#define PIN15                     15
//pin mode
#define INPUT					  0     //00
#define OUTPUT					  1     //01
#define ALTERNATIVE               2     //10
#define ANALOG                    3     //11
//output type
#define OUTPUT_PP                 0    //PUSH PULL
#define OUTPUT_OD                 1    //OPEN DRAIN
//output speed
#define OUTPUT_LS                 1  //00
#define OUTPUT_MS                 2  //01
#define OUTPUT_HS                 3  //10
#define OUTPUT_VHS                4  //11
//input type
#define INPUT_NOPUNOPD            0   //00
#define INPUT_PU                  1   //01
#define INPUT_PD                  2   //10

#define SET                       0
#define RST                       1

#define LOW                       0
#define HIGH                      1

#define AF0            0b0000
#define AF1            0b0001
#define AF2            0b0010
#define AF3            0b0011
#define AF4            0b0100
#define AF5            0b0101
#define AF6            0b0110
#define AF7            0b0111
#define AF8            0b1000
#define AF9            0b1001
#define AF10           0b1010
#define AF11           0b1011
#define AF12           0b1100
#define AF13           0b1101
#define AF14           0b1110
#define AF15           0b1111

#endif /*MRCC_PRIVAITE_H_*/

