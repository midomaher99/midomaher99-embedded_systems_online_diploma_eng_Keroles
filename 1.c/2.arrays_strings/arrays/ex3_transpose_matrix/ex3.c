#include "stdio.h"

void main()
{
	int matrix[20][20], transpose[20][20];
	unsigned char rows, columns, i, j;
	
/************************************************************************/
		/*taking number of rows and columns from user*/
	
	printf("Enter Rows and columns of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &rows, &columns);
	printf("\n");
/************************************************************************/
		/*taking matrix elements and transpose them*/
	
	printf("Enter matrix elements\n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &matrix[i][j]);
			transpose[j][i] = matrix[i][j];
		}
	}
	printf("\n");
/************************************************************************/	
		/*printing matrix*/
		
	printf("Entered matrix:\n");
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < columns; j++)
		{
			printf("%d	",matrix[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
/************************************************************************/	
		/*printing transpose*/
	printf("Transpose matrix:\n");
	for(i = 0; i < columns; i++)
	{
		for(j = 0; j < rows; j++)
		{
			printf("%d	",transpose[i][j]);
		}
		printf("\n");
	}
}