#include "driver.h"
void start_alarm();
void stop_alarm();
void init_alarm();
void (*alarm_state)() = init_alarm;
void init_alarm()
{
	stop_alarm();
}
void start_alarm()
{
	RESET_BIT(GPIOA_ODR,13);
	alarm_state = stop_alarm;
}

void stop_alarm()
{
	SET_BIT(GPIOA_ODR,13);
	alarm_state = start_alarm;
}
