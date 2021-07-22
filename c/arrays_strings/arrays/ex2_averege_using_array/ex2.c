#include"stdio.h"

int main()
{
	float mat[100], sum = 0;
	unsigned char n;
	unsigned char i;	/*counter for loop*/
/************************************************************************/
	printf("Enter the number of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);
/************************************************************************/
	/*taking numbers from user and calculating sum of all numbers*/
	for (i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &mat[i]);
		sum += mat[i];
	}
/************************************************************************/
	/*printing averege*/
	printf("Averege = %.2f", sum/n);
	
	return 0;
}