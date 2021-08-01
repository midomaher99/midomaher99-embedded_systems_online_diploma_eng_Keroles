/*
 * power_of.c
 *
 *  Created on: Aug 1, 2021
 *      Author: Mohamed Mostafa
 */
#include<stdio.h>
long int power_of(int number, int power);
int main()
{
	int number,power;
	printf("Enter number and power: ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d", &number, &power);
	printf("%d power %d = %li",number, power, power_of(number,power));
	return 0;
}
long int power_of(int number, int power)
{
	if(power == 0)
		return 1;
	number*=power_of(number, --power);
	return number;
}
