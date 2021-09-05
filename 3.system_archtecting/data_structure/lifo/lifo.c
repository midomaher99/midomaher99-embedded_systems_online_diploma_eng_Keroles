#include "lifo.h"
lifo_status_t lifo_init(lifo_t* buff, uint32 length, item_type* target)
{
	if(!buff||!target)
		return lifo_null;
	else if (length == 0)
		return lifo_empty;
	else
	{
		buff->base	 	= target;
		buff->head		= target;
		buff->length 	= length;
		buff->count		= 0		;
		return lifo_succeded;
	}
}
/*********************************************************************/
lifo_status_t lifo_push(lifo_t* buff,item_type item)
{
	if (!buff || !buff->base || !buff->head)
		return lifo_null;
	
	else if (buff->count == buff->length)
		return lifo_full;

	else
	{
		*(buff->head) = item;
		buff->count ++;
		buff->head ++;
		return lifo_succeded;
	}

}
/*********************************************************************/
lifo_status_t lifo_pop(lifo_t* buff,item_type* item)
{
	if (!buff || !buff->base || !buff->head)
		return lifo_null;
	
	else if (buff->count == 0)
		return lifo_empty;

	else
	{
		buff->head --;
		*item = *(buff->head) ;
		buff->count --;

		return lifo_succeded;
	}
}
/*********************************************************************/
lifo_status_t lifo_clear(lifo_t* buff)
{
	if (!buff || !buff->base || !buff->head)
		return lifo_null;
	else
	{
		buff->head = buff->base;
		buff->count = 0;
		return lifo_empty;
	}
}
