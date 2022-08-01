/*
 * registers_addresses.h
 *
 *  Created on: Jul 14, 2022
 *  @author				: ENG/Mohamed Mostafa Maher
 *  @contact			: mohamed.mostafa.maher.999@gmail.com
 */

#ifndef REGISTERS_ADDRESSES_H_
#define REGISTERS_ADDRESSES_H_

#include "stdint.h"

#define PORTA_BASE 0x39
#define PORTB_BASE 0x36
#define PORTC_BASE 0x33
#define PORTD_BASE 0x30


#define SREG	*(volatile uint8_t*)(0x5F)
#define GICR	*(volatile uint8_t*)(0x5B)
#define GIFR	*(volatile uint8_t*)(0x5A)
#define MCUCR	*(volatile uint8_t*)(0x55)
#define MCUCSR	*(volatile uint8_t*)(0x54)

typedef struct
{
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
}IO_type;

#define PORTA ((IO_type*)PORTA_BASE)
#define PORTB ((IO_type*)PORTB_BASE)
#define PORTC ((IO_type*)PORTC_BASE)
#define PORTD ((IO_type*)PORTD_BASE)


#endif /* REGISTERS_ADDRESSES_H_ */
