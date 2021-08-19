/*
 * add_complex_numbers.c
 *
 *  Created on: Aug 4, 2021
 *      Author: moham
 */
#include<stdio.h>
struct Scomplex
{
	float real;
	float img;
};
struct Scomplex add_complex(struct Scomplex number1,struct Scomplex number2);
int main()
{	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct Scomplex number1, number2, sum;

	printf("Enter 1st complex number:\n");
	printf("Enter real Part: ");
	scanf("%f",&number1.real);
	printf("Enter imaginary part: ");
	scanf("%f",&number1.img);

	printf("Enter 2nd complex number:\n");
	printf("Enter real Part: ");
	scanf("%f",&number2.real);
	printf("Enter imaginary part: ");
	scanf("%f",&number2.img);

	sum = add_complex(number1, number2);

	printf("sum = %.1f%+.1fi", sum.real,sum.img);
}
struct Scomplex add_complex(struct Scomplex number1,struct Scomplex number2)
{
	struct Scomplex sum;
	sum.real = number1.real + number2.real;
	sum.img = number1.img + number2.img;

	return sum;
}
