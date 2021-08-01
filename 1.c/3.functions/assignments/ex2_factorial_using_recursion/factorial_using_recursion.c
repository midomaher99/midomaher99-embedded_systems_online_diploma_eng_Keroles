/*
 * factorial_using_recursion.c
 *
 *  Created on: Aug 1, 2021
 *      Author: Mohamed Mostafa
 */

#include<stdio.h>
long int factorial(long int number);
int main()
{
	int number;

	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);

	printf("factorial of %d is: %li",number,factorial(number));
	return 0;
}

long int factorial(long int number)
{
	if(number == 0)
		return 1;

	number *= factorial(number-1);
	return number;
}
