/*
 * convert_ASCII_to_number.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */

#include <stdio.h>
#include <string.h>

unsigned int ASCII_to_int(char arr[]);
int main()
{
	char number[100];
	printf("Enter the number: ");
	fflush(stdin);  fflush(stdout);
	scanf("%s",number);

	printf("The number is: %u", ASCII_to_int(number));
	return 0;
}

unsigned int ASCII_to_int(char arr[])
{
	unsigned int number = 0;
	int i, length = strlen (arr);

	for (i = 0; i< length ;i++)
		number = number * 10 + (arr[i]-0x30);

	return number;
}
