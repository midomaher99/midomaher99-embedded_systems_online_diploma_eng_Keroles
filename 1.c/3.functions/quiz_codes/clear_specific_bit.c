/*
 * clear_specific_bit.c
 *
 *  Created on: Jul 27, 2021
 *      Author: Mohamed Mostafa
 */

#include "stdio.h"

int reset_bit(int number, int bit_to_reset);
int main ()
{
	int number;
	int bit_to_reset;
	printf("Enter a number :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);

	printf("Enter a bit to reset :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &bit_to_reset);

	printf("The number after reset bit %d is %d", bit_to_reset, reset_bit(number, bit_to_reset));
	return 0;
}
int reset_bit(int number, int bit_to_reset)
{
	return (number &= (~(1<<bit_to_reset)));
}
