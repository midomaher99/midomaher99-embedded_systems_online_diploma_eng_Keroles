#include "stdio.h"

void  main()
{
	int n, i, sum = 0;
	printf("Enter an integer: ");
	fflush(stdin);
	fflush(stdout);
	scanf ("%d", &n);
	for (i = 0; i <= n; i++)
		sum+= i;
	fflush(stdout);
	printf("sum = %d",sum);
}