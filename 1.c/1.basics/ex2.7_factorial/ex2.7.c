#include "stdio.h"

void  main()
{
	int n, i, factorial = 1;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf ("%d", &n);
	if(n<0)
		printf("Error!!! factorial of nigative number is not exist.");
	else
	{
		for (i = 1; i <= n; i++)
			factorial*= i;
		fflush(stdout);
		printf("factorial = %d",factorial);
	}
}