#include "stdio.h"
#include "fifo.h"
#include "platform_types.h"

int main()
{
	uint32 i;		/*generic counter for loops*/
	fifo_t buffer;
	uint32 arr[5];
	uint32 item;
/*********************************************************************/
/*init fifo*/
	fifo_init(&buffer, arr,5);
/*********************************************************************/
/*push items*/
	printf("********************push items********************\n");
	for(i = 0 ; i <6; i++)
	{
		if (fifo_push(&buffer, i+1) == fifo_succeded)
			printf("item: %d pushed successfully.\n",i+1);
		else
			printf("failed to push item %d", i+1);
	}
/*********************************************************************/
/*pop items*/
	printf("\n********************pop items********************\n");
	for(i = 0 ; i <6; i++)
	{
		if (fifo_pop(&buffer, &item) == fifo_succeded)
			printf("item: %d popped successfully.\n",item);
		else
			printf("failed to pop item");
	}
/*********************************************************************/
/*push items*/
	printf("\n********************push items********************\n");
	for(i = 0 ; i <6; i++)
	{
		if (fifo_push(&buffer, i+1) == fifo_succeded)
			printf("item: %d pushed successfully.\n",i+1);
		else
			printf("failed to push item %d", i+1);
	}
/*********************************************************************/
/*clear items*/
	printf("\n********************clear items********************\n");
	if(fifo_clear(&buffer) == fifo_succeded)
		printf("buffer cleared successfully.");
	else
		printf("failed to clear buffer.");

	return 0;
}
