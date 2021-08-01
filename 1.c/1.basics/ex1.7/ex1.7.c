#include "stdio.h"

int main()
{
	float a, b;
	//taking inputs
	printf("Enter value of a: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &a);
	printf("Enter value of b: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f", &b);
	/*****************************SWAPING********************************************/
	a = a + b;
	b = a - b;
	a = a - b;
	/*****************************PRINTING********************************************/
	fflush(stdout);
	printf("\nAfter swapping, value of a = %f\n", a);
	printf("After swapping, value of b = %f", b);
	return 0;
}