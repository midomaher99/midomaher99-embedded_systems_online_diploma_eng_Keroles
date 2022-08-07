/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  MemoryMap.h
 *
 *  Description:  STM32F103xx header file
 *
 *********************************************************************************************************************/
#ifndef MEMORYMAP_H
#define MEMORYMAP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	vuint32 EVCR;
	vuint32 MAPR;
	vuint32 EXTICR1;
	vuint32 EXTICR2;
	vuint32 EXTICR3;
	vuint32 EXTICR4;
	vuint32 MAPR2;
} AFIO_type;

typedef struct
{
	vuint32 IMR;
	vuint32 EMR;
	vuint32 RSTR;
	vuint32 FSTR;
	vuint32 SWIER;
	vuint32 PR;
} EXTI_type;

typedef struct
{
	vuint32 CRL;
	vuint32 CRH;
	vuint32 IDR;
	vuint32 ODR;
	vuint32 BSRR;
	vuint32 BRR;
	vuint32 LCKR;
} GPIO_type;

typedef struct
{
	vuint32 CR;
	vuint32 CFGR;
	vuint32 CIR;
	vuint32 APB2BRSTR;
	vuint32 APB1BRSTR;
	vuint32 AHBENR;
	vuint32 APB2ENR;
	vuint32 APB1ENR;
	vuint32 BDCR;
	vuint32 CSR;
} RCC_type;

typedef struct
{
	vuint32 ICTR;
	vuint32 reserved1[62];
	vuint32 ISER[8];
	vuint32 reserved2[24];
	vuint32 ICER[8];
	vuint32 reserved3[24];
	vuint32 ISPR[8];
	vuint32 reserved4[24];
	vuint32 ICPR[8];
	vuint32 reserved5[24];
	vuint32 IABR[8];
	vuint32 reserved6[56];
	vuint32 IPR[60];
} NVIC_Type;

typedef struct
{
	vuint32 SR;
	vuint32 DR;
	vuint32 BRR;
	vuint32 CR1;
	vuint32 CR2;
	vuint32 CR3;
	vuint32 GPTPR;
} USART_Type;

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
// Base addresses

//Busses
#define APB1_BASE 0x40000000u
#define APB2_BASE 0x40010000u
//AFIO
#define AFIO_BASE 0x40010000u
//EXTI
#define EXTI_BASE 0x40010400u
//GPIO
#define GPIOA_BASE 0x40010800u
//RCC
#define RCC_BASE 0x40021000u
//NVIC
#define NVIC_BASE 0xE000E004u
//USART
#define USART1_BASE 0x40013800u
#define USART2_BASE 0x40004400u
#define USART3_BASE 0x40004800u
#define UART4_BASE 0x40004C00u
#define UART5_BASE 0x40005000u


// Peripherals instances

//AFIO
#define AFIO ((AFIO_type *)AFIO_BASE)
//EXTI
#define EXTI ((EXTI_type *)EXTI_BASE)
//GPIO
#define GPIOA ((GPIO_type *)GPIOA_BASE)

#define GPIO(BASE) ((GPIO_type *)BASE)
//RCC
#define RCC ((RCC_type *)RCC_BASE)
//USART
#define USART1 ((USART_Type *)USART1_BASE)
#define USART2 ((USART_Type *)USART2_BASE)
#define USART3 ((USART_Type *)USART3_BASE)
#define UART4 ((USART_Type *)UART4_BASE)
#define UART5 ((USART_Type *)UART5_BASE)

#define USART(BASE) ((USART_Type *)BASE)
#define UART(BASE) ((USART_Type *)BASE)
//NVIC
#define NVIC ((NVIC_Type *)NVIC_BASE)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* MEMORYMAP_H */

/**********************************************************************************************************************
 *  END OF FILE: MemoryMap.h
 *********************************************************************************************************************/