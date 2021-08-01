/*
 * last_occurance.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */


/*
 * reversing_array.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */
#include <stdio.h>

void take_array(int arr[],int* size);
int last_accurance_index(int arr[], int size, int num_to_check);
int main()
{
	int arr[100], size, num_to_check;
/************************************************************************/
			/*taking inputs from user*/
	printf("Enter first array:\n");
	fflush(stdout);
	take_array(arr, &size);

	printf("Enter number:\n");
	fflush(stdout); fflush(stdin);
	scanf("%d", &num_to_check);
/************************************************************************/
	printf("result ==> %d",last_accurance_index(arr, size, num_to_check));
	return 0;
}
void take_array(int arr[], int* size)
{
	int i;

	printf("Enter size of the array: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", size);

	for(i = 0; i < *size; i++)
	{
		printf("Enter element arr[%d]: ",i);
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}
}

int last_accurance_index(int arr[], int size, int num_to_check)
{
	int i, index = -1;
	for(i = 0; i < size; i++)
	{
		if(arr[i] == num_to_check)
			index = i;
	}
	return index;
}
