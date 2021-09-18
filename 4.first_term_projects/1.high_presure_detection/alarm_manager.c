#include "alarm_driver.h"
#include "pressure_sensor.h"
#include "driver.h"

#define threshold_pressure 20

void low_pressure();
void high_pressure();
void alarm_init();

void (*pressure_state) () = low_pressure;

void alarm_init()
{
	alarm_state();
}
void low_pressure()
{
	(sensor_state()>=threshold_pressure)?(pressure_state = high_pressure):(pressure_state = low_pressure);
}
void high_pressure()
{
	alarm_state();
	delay(4000000);
	alarm_state();
	
	pressure_state = low_pressure;
}
