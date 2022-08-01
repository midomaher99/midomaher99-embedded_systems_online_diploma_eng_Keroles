/*
 * init.c
 *
 *  Created on: Jul 13, 2022
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 */
//___________________________________________________________
//preprocessor
//___________________________________________________________

#include "init.h"
#include "memory_map.h"

#define NVIC_ISER0 	*(volatile uint32_t*)(0xE000E100)

//___________________________________________________________
//sub-routines
//___________________________________________________________

void CLOCK_INIT()
{
	//I/O port A clock enabled
	RCC->APB2ENR |= 1u<<2;
	//I/O port A clock enabled
	RCC->APB2ENR |= 1u<<0;
}
//_________________________________

void GPIO_INIT()
{
	//set PORTA pin13 Mode to output PUSH-PULL with max CLK 2MHZ
	GPIOA->CRH &= ~ (0xfu << 20);
	GPIOA->CRH |= 0x2u<<20;

	//set PORTA pin0 Mode to input floating
	GPIOA->CRL &= ~ (0xfu << 0);
	GPIOA->CRL |= 0b1u << 3;
}
//_________________________________

void AFIO_INIT()
{
	//map PORTA pin 0 to EXTI alternative function
	AFIO->EXTICR1 &= ~(0xfu << 0);
}
//_________________________________

void EXTI_INIT()
{
	//Rising trigger enabled for Line 1
	EXTI->RSTR|= 0b1u<<0;
	//Interrupt request from Line 1 is not masked
	EXTI->IMR |= 0b1u<<0;

}
//_________________________________

void NVIC_INIT()
{
	//enable IRQ6 EXTI0
	NVIC_ISER0 |= 1u<<6;	//this line violating advisory rule 11.4 (MISRA 2012)
}
