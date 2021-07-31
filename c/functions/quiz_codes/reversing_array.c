/*
 * reversing_array.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */
#include <stdio.h>

void reverse_array(int arr[], int size);
void print_array(int arr[], int size);
void take_array(int arr[],int* size);
int main()
{
	int arr[100], size;
/************************************************************************/
				/*taking array from user*/
		printf("Enter first array:\n");
		fflush(stdout);
		take_array(arr, &size);
/************************************************************************/
			/*printing before reversing*/
	printf("array  before reversing:\n");
	fflush(stdout);
	print_array(arr , size);
/************************************************************************/
	reverse_array(arr,size);
/************************************************************************/
			/*printing before reversing*/
	printf("array  after reversing:\n");
	fflush(stdout);
	print_array(arr , size);
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

void reverse_array(int arr[],int size)
{
	int i, j, temp;
	for(i = 0, j = size -1; i < j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void print_array(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
		fflush(stdout);
	}
	printf("\n");
}
