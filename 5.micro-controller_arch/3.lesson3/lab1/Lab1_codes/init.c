/*
 * init.c
 *
 *  Created on: Jul 12, 2022
 *	@author         : ENG/Mohamed Mostafa Maher
 * 	@contact		: mohamed.mostafa.maher.999@gmail.com
 */
//___________________________________________________________
//preprocessor
#include "init.h"
#include "memory_map.h"

//___________________________________________________________
//sub-routines

void GPIO_INIT()
{
	//I/O port A clock enabled
	RCC->APB2ENR |= 1u<<2;
	//set PORTA pin13 Mode to output PUSH-PULL with max CLK 2MHZ
	GPIOA->CRH &= ~ (0xfu << 20);
	GPIOA->CRH |= 0x2u<<20;

	//set PORTA pin13 direction as output
	GPIOA->ODR |= 1u<<13;


}
