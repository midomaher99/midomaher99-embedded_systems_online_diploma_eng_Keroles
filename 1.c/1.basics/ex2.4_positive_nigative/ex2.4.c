#include "stdio.h"

void main()
{
	float x;
	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&x);

	fflush(stdout);
	if(x > 0)
		printf("%.2f is positive",x);
	else if(x < 0)
		printf("%.2f is nigative",x);
	else
		printf("you entered zero");
}