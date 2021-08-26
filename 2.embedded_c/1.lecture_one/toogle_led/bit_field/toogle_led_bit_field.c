#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)
#define GPIO_CRH *(volatile unsigned int *)(PORTA_BASE + 0x04)
//#define GPIO_ODR *(volatile unsigned int *)(PORTA_BASE + 0x0c)
typedef union {
	unsigned int all_fileds;
	struct
	{
		unsigned int reserved:13;
		unsigned int pin13:1;
	} pin;
}GPIO_ODR_t;
int main(void)
{
	int i;
	RCC_APB2ENR |= 1<<2;
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;

	GPIO_ODR_t * GPIO_ODR = (GPIO_ODR_t *)(PORTA_BASE + 0x0c);

	while (1)
	{
		GPIO_ODR->pin.pin13 = 1;
		for(i = 0 ;i<5000; i++);
		GPIO_ODR->pin.pin13 = 0;
		for(i = 0 ;i<5000; i++);
	}
	return 0;
}
