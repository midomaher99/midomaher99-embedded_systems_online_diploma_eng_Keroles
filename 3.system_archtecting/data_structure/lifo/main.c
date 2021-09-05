#include "stdio.h"
#include "lifo.h"
#include "platform_types.h"
int main()
{
	uint8 i; // generic counter to loops
	uint32 item;
	uint32 arr[5];
	lifo_t buffer;
	lifo_init(&buffer, 5,arr);
/*********************************************************************/
/*push items*/
	printf("********************push items********************\n");
	for(i = 0 ; i<6; i++)
	{
		if(lifo_push(&buffer, i+1) == lifo_succeded)
		{
			printf("item: %d pushed successfully.\n",i+1);
		}
		else
		{
			printf("failed to push item: %d.\n",i+1);
		}
	}
/*********************************************************************/
/*pop items*/
	printf("\n********************pup items********************\n");
	for(i = 0 ; i<6; i++)
	{
		if(lifo_pop(&buffer, &item) == lifo_succeded)
		{
			printf("item: %d poped successfully.\n",item);
		}
		else
		{
			printf("failed to pop item.\n");
		}
	}
/*********************************************************************/
/*push items*/
	printf("\n********************push items********************\n");
	for(i = 0 ; i<6; i++)
	{
		if(lifo_push(&buffer, i+1) == lifo_succeded)
		{
			printf("item: %d pushed successfully.\n",i+1);
		}
		else
		{
			printf("failed to push item: %d.\n",i+1);
		}
	}
/*********************************************************************/
/*clear items*/
	printf("\n********************clear all items********************\n");
	if(lifo_clear(&buffer) == lifo_empty)
		printf("buffer cleared successfully.");
	else
		printf("failed to clear buffer");

	return 0;
}
