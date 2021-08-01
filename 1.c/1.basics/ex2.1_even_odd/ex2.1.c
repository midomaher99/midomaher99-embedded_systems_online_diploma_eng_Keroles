#include "stdio.h"

void main()
{
	int x;
	printf("Enter an integer you want to check: ");
	fflush (stdin);
	fflush (stdout);
	scanf("%d", &x);
	switch (x%2)
	{
		case 1:
			printf("%d is odd", x);
			break;
		case 0:
			printf("%d is even", x);
			break;
	}
}