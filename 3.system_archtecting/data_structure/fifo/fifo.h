#ifndef _FIFO_H_
#define _FIFO_H_
#include "platform_types.h"
#define item_type uint32

typedef struct
{
	item_type *base;
	item_type *head;
	item_type *tail;
	uint32 length;
	uint32 count;
}fifo_t;

typedef enum
{
	fifo_null,
	fifo_full,
	fifo_empty,
	fifo_succeded
}fifo_status_t;


fifo_status_t fifo_init(fifo_t *buff,item_type *target,uint32 length);
fifo_status_t fifo_push(fifo_t* buff, item_type item);
fifo_status_t fifo_pop(fifo_t* buff, item_type* item);
fifo_status_t fifo_clear(fifo_t* buff);


#endif
