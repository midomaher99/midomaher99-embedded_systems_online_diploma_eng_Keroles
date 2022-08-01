/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 * @brief          : Simple exercise to enable external interrupts in STM32f103c6
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
//___________________________________________________________
//preprocessor
//___________________________________________________________

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "init.h"
#include "memory_map.h"
//___________________________________________________________
//sub-routines
//___________________________________________________________

void setup()
{
	CLOCK_INIT();
	GPIO_INIT();
	AFIO_INIT();
	EXTI_INIT();
	NVIC_INIT();
}
//_________________________________
int main(void)
{

	setup(); //initializations
    while(1)
    {

    }
}
//_________________________________
void EXTI0_IRQHandler()
{
	GPIOA->ODR ^= 1u<<13;
	EXTI->PR |= 1u<<0;
}
