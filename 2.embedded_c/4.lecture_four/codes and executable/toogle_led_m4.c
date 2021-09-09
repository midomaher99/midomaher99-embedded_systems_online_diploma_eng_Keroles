#define SYSCTL_RCGC2_R *(volatile unsigned long *)(0x400fe108)
#define GPIO_PORTF_DIR_R *(volatile unsigned long *)(0x40025400)
#define GPIO_PORTF_DIN_R *(volatile unsigned long *)(0x4002551c)
#define GPIO_PORTF_DATA_R *(volatile unsigned long *)(0x400253fc)

int main()
{
	volatile short delay;
	SYSCTL_RCGC2_R = 0x20;
	for (delay = 0 ; delay <200; delay++);
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DIN_R |= 1<<3;

	while (1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for (delay = 0 ; delay <50000; delay++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for (delay = 0 ; delay <50000; delay++);
	}

	return 0; 
}