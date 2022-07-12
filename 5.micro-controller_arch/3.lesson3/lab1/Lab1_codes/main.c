/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 * @brief          : simple application enables the clock for PORTA and toggles pin 13 periodically in STM32f103c6

 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//___________________________________________________________
//preprocessor
#include "memory_map.h"
#include "init.h"
//___________________________________________________________

int main(void)
{
	GPIO_INIT();
    /* Loop forever */
	volatile int i ;
	while (1)
	{
		GPIOA->ODR ^= 1u<<13;

		for(i=0; i<=5000; i++){};
	}
}
