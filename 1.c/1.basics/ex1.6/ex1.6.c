#include"stdio.h"

int main()
{
	float a, b, temp;
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
	temp = a;
	a = b;
	b = temp;
	/*****************************PRINTING********************************************/
	fflush(stdout);
	printf("\nAfter swapping, value of a = %f\n", a);
	printf("After swapping, value of b = %f", b);
	return 0;
}