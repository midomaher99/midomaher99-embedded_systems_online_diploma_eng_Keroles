/*
 * q4.c
 *
 *  Created on: Aug 9, 2021
 *      Author: moham
 */

#include<stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int arr[15], no_of_elements, i, *ptr;
	ptr = arr;
	printf("Enter number of elements (max:15):");
	scanf("%d", &no_of_elements);

	printf("Enter elements:\n");
	for (i =0; i < no_of_elements ;i++)
	{
		printf("element %d - : ", i+1);
		scanf("%d", &arr[i]);
	}
	printf("\n\n");
	for (i =no_of_elements -1; i >=0 ;i--)
	{
		printf("element %d - : %d\n", i+1, *ptr+i);

	}

	return 0;
}
