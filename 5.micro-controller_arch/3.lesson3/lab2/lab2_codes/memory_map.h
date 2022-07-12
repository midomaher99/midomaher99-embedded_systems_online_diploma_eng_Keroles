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

#define RCC_BASE 	0x40021000



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

#endif /* MEMORY_MAP_H_ */
