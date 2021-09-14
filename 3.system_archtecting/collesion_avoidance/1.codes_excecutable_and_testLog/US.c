#include "stdio.h"
#include "CA.h"

typedef enum {
	_US_busy
}US_status_ID_t;

int distance;
US_status_ID_t US_ID;
void(* P_US_state)();

int random_value(int min, int max)
{
	return (rand() % (max-min+1)) + 1;
}

void US_busy()
{
	US_ID = _US_busy;

	distance = random_value(0,10);
	printf("US busy state, distance =%d.\n",distance);
	US_set_dist(distance);
	P_US_state = US_busy;
}

void US_init()
{
	printf("---------------US sensor is initialized---------------\n");
	 P_US_state = US_busy;
}
