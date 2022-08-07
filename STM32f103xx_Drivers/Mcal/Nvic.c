/*
 * Rcc.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: Nvic driver to enable, prioritize or disable global interrupt mask for each handler
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic_Cfg.h"
#include "Nvic_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void NVIC_Init(void)
 * \Description     : initialize the Nvic module by enabling the global interrupt
 *                    mask of the required interrupts in Nvic_Lcfg.c and prioritize them
 *					  From Nvic_Cfg.h and Nvic_Lcfg.c
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void NVIC_Init(void)
{
	vuint8 i;
	vuint8 regOffset;
	vuint8 bitOffset;

	// enable Interrupt
	for (i = 0; i < NUM_INTERRUPTS_ACTIVATED; i++)
	{
		regOffset = (Nvic_Config->Interrupt) / 32u;
		bitOffset = (Nvic_Config->Interrupt) % 32u;

		NVIC->ISER[regOffset] |= 1u << (uint32)bitOffset;
	}

	// set priorities
	for (i = 0; i < NUM_INTERRUPTS_ACTIVATED; i++)
	{
		regOffset = (Nvic_Config->Interrupt) / 4u;
		bitOffset = ((Nvic_Config->Interrupt) % 4u) * 8;

		NVIC->IPR[regOffset] |= Nvic_Config->Priority << bitOffset;
	}
}

/******************************************************************************
 * \Syntax          : void NVIC_EnableIrq(NVIC_InterruptsType interrupt, Nvic_Priority priority)
 * \Description     : Enable the global interrupt mask of an interrupt and prioritize it
 *					  In runime
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : NVIC_InterruptsType	the name of the required interrupt to be enabled
 * 											from Nvic_Types.h
 * 					  NVIC_InterruptsType	the required priority of the interrupt
 * 											from Nvic_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void NVIC_EnableIrq(Nvic_InterruptsType interrupt, Nvic_Priority priority)
{
	vuint8 regOffset;
	vuint8 bitOffset;
	// Enable interrpt
	regOffset = (interrupt) / 32u;
	bitOffset = (interrupt) % 32u;

	NVIC->ISER[regOffset] |= 1u << bitOffset;

	// Priotitize the interrupt
	regOffset = (interrupt) / 4u;
	bitOffset = ((interrupt) % 4u) * 8;

	NVIC->IPR[regOffset] |= priority << bitOffset;
}

/******************************************************************************
 * \Syntax          : void NVIC_DisableIrq(NVIC_InterruptsType interrupt)
 * \Description     : Disable the global interrupt mask of an interrupt
 *					  In runime
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : NVIC_InterruptsType	the name of the required interrupt to be Disabled
 * 											from Nvic_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void NVIC_DisableIrq(Nvic_InterruptsType interrupt)
{
	vuint8 regOffset;
	vuint8 bitOffset;
	regOffset = (interrupt) / 32u;
	bitOffset = (interrupt) % 32u;

	NVIC->ICER[regOffset] |= 1u << bitOffset;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
