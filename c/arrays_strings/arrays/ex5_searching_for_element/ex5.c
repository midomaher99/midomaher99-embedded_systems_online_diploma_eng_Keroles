#include "stdio.h"
void main()
{
	int matrix[20], searched_element;
	unsigned char no_of_elements, i;
	
/************************************************************************/
        /*taking the number of elements and the array elements*/
	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &no_of_elements);
	
	printf("Enter the elements: ");
	for (i = 0; i < no_of_elements; i++)
		scanf("%d", &matrix[i]);
		
/************************************************************************/
        /*taking the element to be serched for*/
	printf("Enter the element to be serched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &searched_element);
/************************************************************************/
        /*searching*/
	for (i = 0; i < no_of_elements; i++)
	{
		if (matrix[i] == searched_element)
			break;
	}
/************************************************************************/
	if(i != no_of_elements)
		printf("number found at the location = %d", i+1);
	else
		printf("Element not found");
}