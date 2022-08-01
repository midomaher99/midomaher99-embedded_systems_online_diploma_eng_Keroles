/*
 * init.c
 *
 *  Created on: Jul 14, 2022
 *  @author				: ENG/Mohamed Mostafa Maher
 *  @contact			: mohamed.mostafa.maher.999@gmail.com
 */
//___________________________________________________________
//preprocessor
//___________________________________________________________
#include "registers_addresses.h"
//___________________________________________________________
//sub-routines
//___________________________________________________________

void IO_INIT()
{
	//set PD2 & PD3 as input (HI-Z)
	PORTD->DDR &= ~(0b11u<<2);
	PORTD->PORT &= ~(0b11u<<2);
	//set PD5 & PD6 & PD7 as OUTPUT and initially SINK
	PORTD->DDR |= 0b111u<<5;
	PORTD->PORT &= ~(0b111<<5);
	//set PB2 as input (HI-Z)
	PORTB->DDR &= ~(0b1u<<2);
	PORTB->PORT &= ~(0b1u<<2);
}
//____________________________________

void EXTI_INIT()
{
	//configure INT0 sense control for ANY LOGICAL change
	MCUCR &= ~(0b11u<<0);
	MCUCR |= 0b1u<<0;
	//configure INT0 sense control for RISING edge
	MCUCR |= 0b11u<<2;
	//configure INT2 sense control for FALLING edge
	MCUCSR &=~ (0b1u<<6);

	//from TRM recommended to clear INT2 flag from GIFR after
	//changing ISC2 bit in MCUCSR register
	GIFR |= 0b1u<<5;

	//enable EXTI0, EXTI1 and EXTI2
	GICR |= 0b111<<5;

	//enable global interrupts
	SREG |=1<<7;
}
