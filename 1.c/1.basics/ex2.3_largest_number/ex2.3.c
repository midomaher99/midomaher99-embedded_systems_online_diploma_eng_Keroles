#include "stdio.h"

void main()
{
	float x, y, z;
	printf("Enter three numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f %f", &x, &y, &z);
	fflush(stdout);
	if (x >= y)
	{
		if(x >= z)
			printf("largest number= %.2f", x);
		else
			printf("largest number= %.2f", z);
	}
	else
	{
	    if(y >= z)
    		printf("largest number= %.2f", y);
		else
			printf("largest number= %.2f", z);
	}
	    
}