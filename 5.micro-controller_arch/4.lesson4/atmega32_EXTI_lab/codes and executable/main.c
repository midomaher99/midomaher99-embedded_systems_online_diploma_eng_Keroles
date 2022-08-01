/*
 * main.c
 *
 *  Created on: Jul 14, 2022
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 * @brief          : Simple exercise to enable external interrupts in ATMEGA32
 */
//___________________________________________________________
//preprocessor
//___________________________________________________________
//#include <avr/interrupt.h>
#include "registers_addresses.h"
#include "init.h"
#include <stdint.h>
//___________________________________________________________
//sub-routines definition
//___________________________________________________________
void delay ();
//___________________________________________________________
//sub-routines
//___________________________________________________________

int main()
{
	IO_INIT();
	EXTI_INIT();
	while(1)
	{
		PORTD->PORT &= ~ (0b1111u<<5);
	}
}
//__________________________
//ISR's
//__________________________
void __vector_1(void) __attribute__((signal));
void __vector_1()//INT0
// ISR (INT0_vect)
{
	PORTD->PORT |= (0b1u<<5);
	delay();
}

void __vector_2(void) __attribute__((signal));
void __vector_2()	//INT1
//ISR (INT1_vect)
{
	PORTD->PORT |= (0b1u<<6);
	delay();
}

void __vector_3(void) __attribute__((signal));
void __vector_3()  //INT2
{
	PORTD->PORT |= (0b1u<<7);
	delay();
}

//__________________________
void delay()
{
	volatile int i ;
	for (i=0; i<=20000; i++)
		{

		}
}
