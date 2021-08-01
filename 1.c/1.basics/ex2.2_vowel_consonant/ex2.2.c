#include "stdio.h"

void main()
{
	char x;
	printf("Enter an alphabet :");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&x);
	
	switch (x)
	{
		case 'a':
		case 'A':
		case 'E':
		case 'e':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			printf("%c is a vowel",x);
			break;
		default:
		printf("%c is a consonant",x);
			break;
	}
	
}