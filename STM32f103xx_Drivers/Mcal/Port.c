/*
 * Port.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: GPIO/ Port driver  
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"
#include "Port_Cfg.h"
#include "MemoryMap.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define LOW_Pin (0x100u) // this value depends on the pinType
						 //  in Port_Types.h

#define IS_LOW_Pin(PinID) ((uint32)((PinID) & 0xF00) < LOW_Pin) // pins 0 -> 8 is the Low pins

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Port_Init(void)

 * \Description     : Initialize the GPIO pins configuraions from port_Cfg.h and Port_Lcfg.c
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Port_Init(void)
{
	uint8 i;
	uint32 portBase;
	uint8 bitShift;
	uint8 value;
	for (i = 0; i < NUM_PINS_ACTIVATED; i++)
	{
		portBase = APB2_BASE | (Port_Config[i].pinID >> 12u);
		bitShift = Port_Config[i].pinID & 0xFF;
		value = Port_Config[i].Configuration & 0xf;
		if (IS_LOW_Pin(Port_Config[i].pinID))
		{
			GPIO(portBase)->CRL &= ~(0xfu << (uint32)bitShift);
			GPIO(portBase)->CRL |= ((uint32)value << (uint32)bitShift);

			// for pull up and pull down
			bitShift = bitShift / 4;
			GPIO(portBase)->ODR &= ~(1u << (uint32)bitShift);
			GPIO(portBase)->ODR |= ((uint32)(Port_Config[i].Configuration >> 8u) << (uint32)bitShift);
		}
		else
		{
			GPIO(portBase)->CRH &= ~(0xfu << (uint32)bitShift);
			GPIO(portBase)->CRH |= ((uint32)value << (uint32)bitShift);

			// for pull up and pull down
			bitShift = (bitShift / 4) + 8;
			GPIO(portBase)->ODR &= ~(1u << (uint32)bitShift);
			GPIO(portBase)->ODR |= ((uint32)(Port_Config[i].Configuration >> 8u) << (uint32)bitShift);
		}
	}
}
/******************************************************************************
 * \Syntax          : void Port_SetMode(Port_PinType pinId, Port_PinConfigurationType configuration)
 * \Description     : set GPIO pin configuration in run time
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Port_PinType   				the required pin to set its
 * 													configuration from Port_Types.h
 *
 * 					  Port_PinConfigurationType		the required pin configuratoin
 * 													from Port_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Port_SetConfigration(Port_PinType pinId, Port_PinConfigurationType configuration)
{

	uint32 portBase;
	uint8 bitShift;
	uint8 value;
	portBase = APB2_BASE | ((uint32)pinId >> 12u);
	bitShift = pinId & 0xFFu;
	value = configuration & 0xFu;

	if (IS_LOW_Pin(pinId))
	{
		GPIO(portBase)->CRL &= ~(0xfu << (uint32)bitShift);
		GPIO(portBase)->CRL |= ((uint32)value << (uint32)bitShift);
		// for pull up and pull down
		bitShift = bitShift / 4;
		GPIO(portBase)->ODR &= ~(1u << (uint32)bitShift);
		GPIO(portBase)->ODR |= ((uint32)(configuration >> 8u) << (uint32)bitShift);
	}
	else
	{
		GPIO(portBase)->CRH &= ~(0xFu << (uint32)bitShift);
		GPIO(portBase)->CRH |= ((uint32)value << (uint32)bitShift);
		// for pull up and pull down
		bitShift = (bitShift / 4) + 8;
		GPIO(portBase)->ODR &= ~(1u << (uint32)bitShift);
		GPIO(portBase)->ODR |= ((uint32)(configuration >> 8u) << (uint32)bitShift);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
