#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800

#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE + 0x18)
#define GPIO_CRH *(volatile unsigned int *)(PORTA_BASE + 0x04)
#define GPIO_ODR *(volatile unsigned int *)(PORTA_BASE + 0x0c)

int main(void)
{
	int i;
	RCC_APB2ENR |= 1<<2;
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;
	while (1)
	{
		GPIO_ODR |= 1<<13;
		for(i = 0 ;i<50000; i++);
		GPIO_ODR &=~(1<<13);
		for(i = 0 ;i<50000; i++);
	}
	return 0;
}
