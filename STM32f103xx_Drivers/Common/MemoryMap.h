/*
 * memory_map.h
 *
 *  Created on: Jul 12, 2022
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "PlatformTypes.h"

#define RW__ volatile
#define RO__ volatile
#define WO__ volatile
#define RWC__ volatile
#define RW1C__ volatile
#define W1C__ volatile

#define APB1_BASE 0x40000000u
#define APB2_BASE 0x40010000u

#define AFIO_BASE 0x40010000u
#define EXTI_BASE 0x40010400u
#define GPIOA_BASE 0x40010800u
#define RCC_BASE 0x40021000u
#define NVIC_BASE 0xE000E004u

#define USART1_BASE 0x40013800u
#define USART2_BASE 0x40004400u
#define USART3_BASE 0x40004800u
#define UART4_BASE 0x40004C00u
#define UART5_BASE 0x40005000u

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
	RO__ uint32 ICTR;
	vuint32 reserved1[62];
	RW__ uint32 ISER[8];
	vuint32 reserved2[24];
	RW__ uint32 ICER[8];
	vuint32 reserved3[24];
	RW__ uint32 ISPR[8];
	vuint32 reserved4[24];
	RW__ uint32 ICPR[8];
	vuint32 reserved5[24];
	RO__ uint32 IABR[8];
	vuint32 reserved6[56];
	RW__ uint32 IPR[60];
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

#define AFIO ((AFIO_type *)AFIO_BASE)
#define EXTI ((EXTI_type *)EXTI_BASE)
#define GPIOA ((GPIO_type *)GPIOA_BASE)
#define GPIO(BASE) ((GPIO_type *)BASE)
#define RCC ((RCC_type *)RCC_BASE)
#define USART1 ((USART_Type *)USART1_BASE)
#define USART2 ((USART_Type *)USART2_BASE)
#define USART3 ((USART_Type *)USART3_BASE)
#define UART4 ((USART_Type *)UART4_BASE)
#define UART5 ((USART_Type *)UART5_BASE)

#define USART(BASE) ((USART_Type *)BASE)
#define UART(BASE) ((USART_Type *)BASE)
#define NVIC ((NVIC_Type *)NVIC_BASE)

#endif /* MEMORY_MAP_H_ */
