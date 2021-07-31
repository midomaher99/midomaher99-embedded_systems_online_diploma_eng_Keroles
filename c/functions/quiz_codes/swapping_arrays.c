/*
 * swaping arrays.c
 *
 *  Created on: Jul 26, 2021
 *      Author: Mohamed Mostafa
 */
#include <stdio.h>

void swap_array(int arr1[],int* size1 ,int arr2[], int* size2);
void print_array(int arr[], int size);
void take_array(int arr[],int* size);

int main()
{
	int arr1[100], size1 ;
	int arr2[100], size2 ;
/************************************************************************/
			/*taking arrays from user*/
	printf("Enter first array:\n");
	fflush(stdout);
	take_array(arr1, &size1);

	printf("enter second array:\n");
	fflush(stdout);
	take_array(arr2, &size2);
/************************************************************************/
		/*printing before swaping*/
	printf("array 1 before swaping:\n");
	fflush(stdout);
	print_array(arr1, size1);

	printf("array 2 before swaping:\n");
	fflush(stdout);
	print_array(arr2, size2);
/************************************************************************/
	swap_array(arr1, &size1,arr2, &size2);
/************************************************************************/
		/*printing after swaping*/
	printf("array 1 after swaping:\n");
	fflush(stdout);
	print_array(arr1, size1);

	printf("array 2 after swaping:\n");
	fflush(stdout);
	print_array(arr2, size2);

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

void swap_array(int arr1[], int* size1,int arr2[], int* size2)
{
	int i;
	int temp;
	for (i = 0; i < ((*size1 > *size2) ? *size1 : *size2); i++)
	{
		temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	temp = *size1;
	*size1 = *size2;
	*size2 = temp;
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
