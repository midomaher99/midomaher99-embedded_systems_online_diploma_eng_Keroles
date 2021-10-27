#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_
//--------------------------------------
//includes
//--------------------------------------

#include "stdlib.h"
#include "stdint.h"

//--------------------------------------
//base_addresses of memory
//--------------------------------------
#define Flash_memory_BASE 				0x08000000UL
#define System_memory_BASE 				0x1FFFF000UL
#define SRAM_memory_BASE	 			0x20000000UL

#define Peripherals_BASE				0x40000000UL

#define Cortex_m3_Peripherals_BASE		0xE0000000UL
//--------------------------------------
//base addresses of AHB peripherals
//--------------------------------------
//RCC

#define RCC_BASE 						0x40021000UL







//--------------------------------------
//base addresses of APB2 peripherals
//--------------------------------------


//GPIO
//A,B fully included in LQFP84
#define GPIOA_BASE 						0x40010800UL
#define GPIOB_BASE 						0x40010C00UL
//C,D partial included in LQFP84
#define GPIOC_BASE 						0x40011000UL
#define GPIOD_BASE 						0x40021000UL
//E not included in LQFP84
#define GPIOE_BASE 						0x40011800UL

//EXITI

#define EXITI_BASE						0x40010400UL


//AFIO
#define AFIO_BASE 						0x40021000UL

//====================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR;
}GPIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR ;
	volatile uint32_t CFGR ;
	volatile uint32_t CIR ;
	volatile uint32_t APB2RSTR ;
	volatile uint32_t APB1RSTR ;
	volatile uint32_t AHBENR ;
	volatile uint32_t APB2ENR ;
	volatile uint32_t APB1ENR ;
	volatile uint32_t BDCR ;
	volatile uint32_t CSR ;
}RCC_t;


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//peripheral register: EXITI
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR ;
	volatile uint32_t EMR ;
	volatile uint32_t RSTR ;
	volatile uint32_t FTSR ;
	volatile uint32_t SWIER ;
	volatile uint32_t PR ;
}EXITI_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR ;
	volatile uint32_t MAPR ;
	volatile uint32_t EXITICR1 ;
	volatile uint32_t EXITICR2 ;
	volatile uint32_t EXITICR3 ;
	volatile uint32_t EXITICR4 ;
	volatile uint32_t Reserved0 ;
	volatile uint32_t MAPR2 ;
}AFIO_t;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//peripheral instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA 	((volatile GPIO_t*)GPIOA_BASE)
#define GPIOB 	((volatile GPIO_t*)GPIOB_BASE)
#define GPIOC 	((volatile GPIO_t*)GPIOC_BASE)
#define GPIOD 	((volatile GPIO_t*)GPIOD_BASE)
#define GPIOE 	((volatile GPIO_t*)GPIOE_BASE)

#define RCC 	((volatile RCC_t*)RCC_BASE)

#define EXITI 	((volatile EXITI_t*)EXITI_BASE)

#define AFIO 	((volatile AFIO_t*)AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//clock enable macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define RCC_GPIOA_clk_en() (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_clk_en() (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_clk_en() (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_clk_en() (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_clk_en() (RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_clk_en() (RCC->APB2ENR |= 1<<0)



#endif /* INC_STM32F103X6_H_ */
