#include "stdio.h"
#include "DC.h"

#define threshold_distance 5

typedef enum {
	_CA_waiting,
	_CA_driving
}CA_status_ID_t;

void(* P_CA_state)() ;
int CA_distance = 0, CA_speed =0;
CA_status_ID_t CA_ID;

void CA_waiting()
{
	CA_ID = _CA_waiting;
	DC_set_speed(0);
	printf("waiting\n");
}

void CA_driving()
{
	CA_ID = _CA_driving;
	DC_set_speed(30);
	printf("driving\n");
}

void US_set_dist(int distance)
{
	CA_distance = distance;
	(CA_distance <= threshold_distance)?(P_CA_state = CA_waiting):(P_CA_state = CA_driving);
}
