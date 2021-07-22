#include "stdio.h"
void main()
{
	int matrix[20], inserted_element;
	unsigned char no_of_elements, i, insertion_location ;
	
/************************************************************************/
        /*taking the number of elements and the array elements*/
	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &no_of_elements);
	
	printf("Enter the elements: ");
	for (i = 0; i < no_of_elements; i++)
		scanf("%d", &matrix[i]);
/************************************************************************/	
	    /*taking the inserted element and its location*/
	printf("Enter the element to be insert: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &inserted_element);
	
	printf("Enter the location: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &insertion_location);  /*here inserted_element is seted to 0*/
	
/************************************************************************/
		/*inserting the new element*/
	for (i = no_of_elements-1; i >= insertion_location-1; i--)
	{
		matrix[i+1] = matrix[i];
	}
	no_of_elements += 1;
    matrix[insertion_location-1]=inserted_element;
/************************************************************************/	
		/*printing the new matrix*/
	for(i=0; i<no_of_elements; i++)
	{
		printf("%d ", matrix[i]);
		fflush(stdin); fflush(stdout);
	}		
}