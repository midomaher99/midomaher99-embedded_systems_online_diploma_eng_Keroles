#include"fifo.h"
#include"platform_types.h"

fifo_status_t fifo_init(fifo_t *buff,item_type *target,uint32 length)
{
	if(!buff || !target || !length)
		return fifo_null;
	else
	{
		buff->base = buff->head = buff->tail = target;
		buff->length = length;
		buff->count =0;
		return fifo_succeded;
	}
}

fifo_status_t fifo_push(fifo_t* buff, item_type item)
{
	if(!buff || !buff->base || !buff->head || !buff->tail)
		return fifo_null;
	else if (buff->count == buff->length)
		return fifo_full;
	else
	{
		*(buff->head) = item;
		buff->count++;
		buff->head ++;
		if(buff->head == (buff->base + buff->length))
			buff->head = buff->base;
		return fifo_succeded;
	}
}

fifo_status_t fifo_pop(fifo_t* buff, item_type* item)
{
	if(!buff || !buff->base || !buff->head || !buff->tail)
			return fifo_null;
		else if (buff->count == 0)
			return fifo_empty;
		else
		{
			*item = *(buff->tail);
			buff->count--;
			buff->tail ++;
			if(buff->tail == (buff->base + buff->length))
				buff->tail = buff->base;
			return fifo_succeded;
		}
}
fifo_status_t fifo_clear(fifo_t* buff)
{
	if(!buff || !buff->base || !buff->head || !buff->tail)
		return fifo_null;
	else
	{
		buff->head = buff->tail = buff->base ;
		buff->count =0;
		return fifo_succeded;
	}
}
