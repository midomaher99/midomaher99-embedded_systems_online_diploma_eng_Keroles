/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Nvic_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void NVIC_Init(void)
 * \Description     : initialize the Nvic module by enabling the global interrupt
 *                    mask of the required interrupts in Nvic_Lcfg.c and prioritize them
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void NVIC_Init(void);

/******************************************************************************
 * \Syntax          : void NVIC_EnableIrq(NVIC_InterruptsType interrupt, Nvic_Priority priority)
 * \Description     : Enable the global interrupt mask of an interrupt and prioritize it
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
extern void NVIC_EnableIrq(Nvic_InterruptsType interrupt, Nvic_Priority priority);

/******************************************************************************
 * \Syntax          : void NVIC_DisableIrq(NVIC_InterruptsType interrupt)
 * \Description     : Disable the global interrupt mask of an interrupt
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : NVIC_InterruptsType	the name of the required interrupt to be Disabled
 * 											from Nvic_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void NVIC_DisableIrq(Nvic_InterruptsType interrupt);
#endif /* NVIC_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
