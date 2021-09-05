#ifndef _lIFO_H
#define _LIFO_H
#include "platform_types.h"
#define item_type uint32
/*********************************************************************/
/*data describes my lifo*/
typedef struct
{
	item_type* base;
	item_type* head;
	uint32 count;
	uint32 length;
}lifo_t;
/*********************************************************************/
/*lifo status*/
typedef enum
{
	lifo_null,
	lifo_succeded,
	lifo_full,
	lifo_empty
}lifo_status_t;
/*********************************************************************/
/*lifo methods*/
lifo_status_t lifo_init(lifo_t* buff, uint32 length, item_type* target);
lifo_status_t lifo_push(lifo_t* buff,item_type item);
lifo_status_t lifo_pop(lifo_t* buff,item_type* item);
lifo_status_t lifo_clear(lifo_t* buff);

#endif
