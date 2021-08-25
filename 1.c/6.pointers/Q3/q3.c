/*
 * q3.c
 *
 *  Created on: Aug 9, 2021
 *      Author: moham
 */

#include<stdio.h>
#include<string.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char string[50], *ptr;
	ptr = string;
	int i;
	
	printf("Enter a string: ");
	gets(string);
	
	for(i=strlen(string)-1;i>=0;i--)
	{
		printf("%c",*(ptr+i));
	}
	
	return 0;
}

