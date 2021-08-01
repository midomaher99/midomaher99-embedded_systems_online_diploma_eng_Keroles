#include "stdio.h"

void main ()
{
	char x;
	printf("Enter a chatachter: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &x);
	if ((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z'))
		printf("%c is an alphabit", x);
	else
		printf("%c is not an alphabit", x);
	
}