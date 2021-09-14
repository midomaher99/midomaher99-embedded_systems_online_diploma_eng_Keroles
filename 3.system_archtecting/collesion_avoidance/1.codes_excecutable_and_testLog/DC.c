#include "stdio.h"

typedef enum {
	_DC_idle,
	_DC_busy
}DC_status_ID;

DC_status_ID DC_ID;
int speed;
void(* P_DC_state)();

void DC_idle()
{
	DC_ID = _DC_idle;

	printf("DC idle state, speed= %d.\n\n",speed);

	P_DC_state = DC_idle;
}

void DC_busy()
{
	DC_ID = _DC_busy;

	printf("DC busy state, speed= %d.\n\n",speed);

	P_DC_state = DC_idle;
}
void DC_set_speed(int s)
{
	speed =s;
	P_DC_state = DC_busy;
}

void DC_init()
{
	printf("---------------DC motor is initialized---------------\n");
	P_DC_state = DC_idle;
}
