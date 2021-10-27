#include "stm32f103x6.h"
#include "stm32_f103c6_GPIO_driver.h"
void GPIO_init()
{
	GPIO_pinConfig_t pin;

	//GPIO PORTA pin 1 input floating
	pin.GPIO_PinNumber=GPIO_PIN_1;
	pin.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pin);

	//GPIO PORTB pin 1 output push-pull with 2MHz speed
	pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pin.GPIO_Output_speed= GPIO_SPEED_2M;
	MCAL_GPIO_Init(GPIOB, &pin);

	//GPIO PORTA pin 13 input floating
	pin.GPIO_PinNumber=GPIO_PIN_13;
	pin.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &pin);

	//GPIO PORTB pin 13 output push-pull with 2MHz speed
	pin.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	pin.GPIO_Output_speed= GPIO_SPEED_2M;
	MCAL_GPIO_Init(GPIOB, &pin);
}
void clock_init()
{
	RCC_GPIOA_clk_en();
	RCC_GPIOB_clk_en();
}
void setup()
{
	clock_init();
	GPIO_init();
}

int main(void)
{
    setup();
    //turn off all LEDs initially
    MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_set);
    MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_set);
	int i;
    while(1)
	{
		//single pressing button
		if(!MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1))
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(!MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1));
		}
		//multi pressing button
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13))
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);

		}
	}
}
