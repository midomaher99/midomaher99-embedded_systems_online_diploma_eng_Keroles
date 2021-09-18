#include "driver.h"
#include "alarm_manager.h"

void setup()
{
	GPIO_init();
	alarm_init();
}
void main ()
{
	setup();
	while (1)
	{
		pressure_state(); 
	}
}
