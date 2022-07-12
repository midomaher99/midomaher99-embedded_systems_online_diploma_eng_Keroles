/*
 * memory_map.h
 *
 *  Created on: Jul 12, 2022
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 */

#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_

#include "stdint.h"

#define GPIOA_BASE 	0x40010800
#define RCC_BASE 	0x40021000

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_type;

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2BRSTR;
	volatile uint32_t APB1BRSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_type;



#define RCC 	((RCC_type*)RCC_BASE)
#define GPIOA 	((GPIO_type*)GPIOA_BASE)
#endif /* MEMORY_MAP_H_ */
