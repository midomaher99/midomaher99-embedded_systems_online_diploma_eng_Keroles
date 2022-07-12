/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 * @brief          : This is a simple lab on STM32f103c6 clock interfacing to use HSI as a
 * 					 system clock and to make APB1, APB2 clocks 4 and 2 MHZ respectively
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//___________________________________________________________
//preprocessor
#include "memory_map.h"
int main(void)
{
	//enable HSI oscillator
	RCC->CR |= 1u<<0;
	//set APB1 clock (PCLK1) prescaler to /2
	RCC->CFGR &= ~ (0b111u<<8);
	RCC->CFGR |= 0b100u<<8;
	//set APB2 clock (PCLK2) prescaler to /4
	RCC->CFGR &= ~ (0b111u<<11);
	RCC->CFGR |= 0b101u<<11;
	//select HSI as a system clock
	RCC->CFGR &= ~ (11u<<0);
	/* Loop forever */
	while(1)
	{

	}
}
