#include "stdio.h"
#include "CA.h"
#include "DC.h"
#include "US.h"
void setup()
{
	DC_init();
	US_init();
	printf("\n");
}

int main()
{
	setup();
	while (1)
	{
		P_US_state();

		P_CA_state();

		P_DC_state();
	}
	return 0;
}