/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Rcc
 *       Module:  Reset and Clock Control
 *
 *  Description:  Header file for RCC driver
 *
 *********************************************************************************************************************/
#ifndef RCC_H
#define RCC_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"
#include "Rcc_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void RCC_Init(void)

* \Description     : Initialize RCC module
*                    Only clock enalble feature is implemented
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
extern void RCC_Init(void);

/******************************************************************************
* \Syntax          : void RCC_ClockEnable(RCC_PeriphiralsType peripheral)

* \Description     : Enable clock for a specific peripheral
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
extern void RCC_ClockEnable(Rcc_PeripheralsType peripheral);

/******************************************************************************
* \Syntax          : void RCC_DisableClock(RCC_PeriphiralsType peripheral)

* \Description     : Disable clock for a specific peripheral
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
extern void RCC_ClockDisable(Rcc_PeripheralsType peripheral);

/******************************************************************************
* \Syntax          : void RCC_PeripheralReset(RCC_PeriphiralsType peripheral)

* \Description     : Reset a specific peripheral
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
extern void RCC_PeripheralReset(Rcc_PeripheralsType peripheral);

/******************************************************************************
* \Syntax          : uint32 RCC_GetPClk1_Freq();

* \Description     : Get the PClk 1 frequency (APB1 peripherals driving clock)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of pclk1
*******************************************************************************/
extern uint32 RCC_GetPClk1_Freq(void);

/******************************************************************************
* \Syntax          : uint32 RCC_GetPClk2_Freq();

* \Description     : Get the PClk 2 frequency (APB2 peripherals driving clock)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of pclk2
*******************************************************************************/
extern uint32 RCC_GetPClk2_Freq(void);

#endif /* RCC_H */

/**********************************************************************************************************************
 *  END OF FILE: Rcc.h
 *********************************************************************************************************************/
