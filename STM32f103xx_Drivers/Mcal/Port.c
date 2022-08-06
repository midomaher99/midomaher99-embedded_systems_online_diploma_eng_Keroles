/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

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

#define IS_LOW_Pin(PinID) ((PinID & 0xF00) < LOW_Pin) // pins 0 -> 8 is the Low pins
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

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
			GPIO(portBase)->CRL &= ~(0xf << bitShift);
			GPIO(portBase)->CRL |= (value << bitShift);

			// for pull up and pull down
			bitShift = bitShift / 4;
			GPIO(portBase)->ODR &= ~(1u << bitShift);
			GPIO(portBase)->ODR |= ((Port_Config[i].Configuration >> 8u) << bitShift);
		}
		else
		{
			GPIO(portBase)->CRH &= ~(0xf << bitShift);
			GPIO(portBase)->CRH |= (value << bitShift);

			// for pull up and pull down
			bitShift = (bitShift / 4) + 8;
			GPIO(portBase)->ODR &= ~(1u << bitShift);
			GPIO(portBase)->ODR |= ((Port_Config[i].Configuration >> 8u) << bitShift);
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
	portBase = APB2_BASE | (pinId >> 12u);
	bitShift = pinId & 0xFF;
	value = configuration & 0xf;

	if (IS_LOW_Pin(pinId))
	{
		GPIO(portBase)->CRL &= ~(0xf << bitShift);
		GPIO(portBase)->CRL |= (value << bitShift);
		// for pull up and pull down
		bitShift = bitShift / 4;
		GPIO(portBase)->ODR &= ~(1u << bitShift);
		GPIO(portBase)->ODR |= ((configuration >> 8u) << bitShift);
	}
	else
	{
		GPIO(portBase)->CRH &= ~(0xf << bitShift);
		GPIO(portBase)->CRH |= (value << bitShift);
		// for pull up and pull down
		bitShift = (bitShift / 4) + 8;
		GPIO(portBase)->ODR &= ~(1u << bitShift);
		GPIO(portBase)->ODR |= ((configuration >> 8u) << bitShift);
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
