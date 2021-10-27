#include "stm32f103x6.h"
#include "stm32_f103c6_GPIO_driver.h"
/*
(*config_register) |= ((PinConfig->GPIO_MODE << 2) << pin_offset);

			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}*/


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
		case GPIO_PIN_0:
			return 0;
			break;
		case GPIO_PIN_1:
			return 4;
			break;
		case GPIO_PIN_2:
			return 8;
			break;
		case GPIO_PIN_3:
			return 12;
			break;
		case GPIO_PIN_4:
			return 16;
			break;
		case GPIO_PIN_5:
			return 20;
			break;
		case GPIO_PIN_6:
			return 24;
			break;
		case GPIO_PIN_7:
			return 28;
			break;
		case GPIO_PIN_8:
			return 0;
			break;
		case GPIO_PIN_9:
			return 4;
			break;
		case GPIO_PIN_10:
			return 8;
			break;
		case GPIO_PIN_11:
			return 12;
			break;
		case GPIO_PIN_12:
			return 16;
			break;
		case GPIO_PIN_13:
			return 20;
			break;
		case GPIO_PIN_14:
			return 24;
			break;
		case GPIO_PIN_15:
			return 28;
			break;
		default:
			return 0;
			break;
	}
}

/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief			-Initializes the GPIOx PINy according to the specific parameters in the PinConfig
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param2 [in]		-PinConfig pointer to the GPIO_PinConfig_t structure that contains the configuration information for the specific GPIO PIN
 * @retval			-none
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
void MCAL_GPIO_Init(volatile GPIO_t* GPIOx, GPIO_pinConfig_t* PinConfig)
{
	//check CRH-CRL
	volatile uint32_t* config_register = (PinConfig->GPIO_PinNumber < 8) ? (&GPIOx->CRL):(&GPIOx->CRH);
	uint32_t pin_offset = Get_CRLH_Position(PinConfig->GPIO_PinNumber);

	//reset pin configuration
	(*config_register) &= ~(0xff << pin_offset);

	//inputs
	//MODEy[1:0] reset value 0b00
	if (PinConfig->GPIO_MODE == GPIO_MODE_Analog || PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)
	{
		*config_register |= (PinConfig->GPIO_MODE <<2) << pin_offset;
	}
	else if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PD ||PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
	{
		*config_register |= (GPIO_MODE_INPUT_PU <<2) << pin_offset;

		if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
		{
			GPIOx->ODR |= PinConfig->GPIO_PinNumber;
		}
		else
		{
			GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
		}
	}
	else if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF)
	{
		*config_register |= (GPIO_MODE_Analog <<2) << pin_offset;
	}
	// end of inputs

	//outputs
	else
	{
		*config_register |= (((PinConfig->GPIO_MODE - 4) <<2) | PinConfig->GPIO_Output_speed) << pin_offset;
	}
}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief			-Reset the GPIOx module
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-none
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
void MCAL_GPIO_DeInit(volatile GPIO_t* GPIOx)
{
	switch((uint32_t)GPIOx)
		{
		case((uint32_t)GPIOA):
			RCC->APB2RSTR |= (1<<2);
			RCC->APB2RSTR &= ~(1<<2);
			break;

		case((uint32_t)GPIOB):

			RCC->APB2RSTR |= (1<<3);
			RCC->APB2RSTR &= ~(1<<3);
			break;
		case((uint32_t)GPIOC):

			RCC->APB2RSTR |= (1<<4);
			RCC->APB2RSTR &= ~(1<<4);
			break;
		case((uint32_t)GPIOD):

			RCC->APB2RSTR |= (1<<5);
			RCC->APB2RSTR &= ~(1<<5);
			break;
		case((uint32_t)GPIOE):
			RCC->APB2RSTR |= (1<<6);
			RCC->APB2RSTR &= ~(1<<6);
			break;
		}

}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief			-Read specific input pin in GPIOx
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param2 [in]		-PinNumbe: set Pin Number according to @ref GPIO_PINS_define
 * @retval			-the input pin value (two values based one @ref GPIO_PIN_state)
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
uint8_t MCAL_GPIO_ReadPin(volatile GPIO_t* GPIOx, uint16_t PinNumber)
{
	switch (GPIOx->IDR & PinNumber)
	{
	case(GPIO_PIN_reset):
		return GPIO_PIN_reset;
		break;

	default:
		return GPIO_PIN_set;
		break;
	}
}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief			-Read specific input port value
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-the input PORT value
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
uint16_t MCAL_GPIO_ReadPort	(volatile GPIO_t* GPIOx)
{
	return (GPIOx->IDR & GPIO_PIN_ALL);
}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief			-Write on specific output pin in GPIOx
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param2 [in]		-PinNumbe: set Pin Number according to @ref GPIO_PINS_define
 * @param2 [in]		-Value: pin value (two values based one @ref GPIO_PIN_state)
 * @retval			-none
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
void MCAL_GPIO_WritePin (volatile GPIO_t* GPIOx, uint16_t PinNumber,uint8_t value)
{
	switch(value)
	{
	case(GPIO_PIN_set):
		GPIOx->ODR |= PinNumber;
		break;
	case(GPIO_PIN_reset):
		GPIOx->ODR &= ~ (PinNumber);
		break;
	}
}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief			-Write on specific output port
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			-none
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
void MCAL_GPIO_WritePort (volatile GPIO_t* GPIOx, uint16_t value)
{
	GPIOx->ODR = value;
}
/*****************************************************************************************************************************/
/*
 * ==========================================================
 * @Fn				-MCAL_GPIO_TooglePin
 * @brief			-toggle the logic on PIN y PORTx
 * @param1 [in]		-GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param2 [in]		-PinNumber: Pin number to be toggle (according to @ref GPIO_PINS_define)
 * @retval			-OK if pin config is locked OR ERROR if pin not locked (according to @ref GPIO_LOCK_define)
 * NOTE				-stm32f103c6 MCU has GPIO A, B, C, D, E Modules
 * 					 But LQFP48 Package has only GPIO A, B, PART of C, D exported as external pins from the MCU
 */
void MCAL_GPIO_TogglePin (volatile GPIO_t* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}






















