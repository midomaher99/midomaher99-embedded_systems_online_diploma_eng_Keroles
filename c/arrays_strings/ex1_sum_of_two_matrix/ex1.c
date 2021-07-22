#include "stdio.h"

int main()
{
	float a[2][2], b[2][2];
	unsigned char rows,columns;	/*counters for loops (used for both matrix)*/
/************************************************************************/
    	/*get 1st array elements from user*/
	printf("Enter the elements of 1st matrix: \n");
	fflush(stdin); fflush(stdout);
	
	
	for (rows = 0; rows < 2; rows++)
	{
		for (columns = 0; columns < 2; columns++)
		{
			printf("Enter a%d%d: ", rows+1, columns+1);
			scanf("%f", &a[rows][columns]);
		}
	}
/************************************************************************/
    	/*get 2nd array elements from user*/
	printf("Enter the elements of 2nd matrix: \n");
	fflush(stdin); fflush(stdout);
	
	for (rows = 0; rows < 2; rows++)
	{
		for (columns = 0; columns < 2; columns++)
		{
			printf("Enter b%d%d: ", rows+1, columns+1);
			scanf("%f", &b[rows][columns]);
		}
	}
/************************************************************************/
    	/*print sum*/
	fflush(stdout);
	printf("sum of matrix\n");
	for (rows = 0; rows < 2; rows++)
	{
		for (columns = 0; columns < 2; columns++)
		{
			fflush(stdout);
			printf("%.1f\t", a[rows][columns]+b[rows][columns]);
		}
		printf("\n");
	}
	
	return 0;
}