/*
 * power_of_three.c
 *	checks is a given number is a power of three
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */
#include <stdio.h>
#include<stdbool.h>

int check_power(int number, int power);
int main()
{
	int number;
	printf("Enter a number");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);



	printf("%d ==> %d", number, check_power(number, 3));
	return 0;
}
int check_power(int number, int power)
{
	bool flag = 0;
	switch (number)
	{
		case 1:
			flag = 0;
			break;
		default:
			while(number != 1)
			{
				if(number % power != 0)
				{
					flag =1;
					break;
				}
				number /= power;
			}
			break;
	}

	return flag;
}
