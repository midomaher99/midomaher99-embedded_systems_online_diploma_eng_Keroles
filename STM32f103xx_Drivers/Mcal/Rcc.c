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
#include "Rcc_Types.h"
#include "Rcc_Cfg.h"
#include "PlatformTypes.h"
#include "MemoryMap.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
#define AHP_PERIPHERAL 32u
#define APB2_PERIPHERAL 64u
#define APB1_PERIPHERAL 96u

#define IS_AHP_Periphiral(PeripheralId) (PeripheralId < AHP_PERIPHERAL)
#define IS_APB2_Periphiral(PeripheralId) (PeripheralId < APB2_PERIPHERAL)
#define IS_APB1_Periphiral(PeripheralId) (PeripheralId < APB1_PERIPHERAL)
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
* \Syntax          : void RCC_Init(void)

* \Description     : Initialize RCC module      From Rcc_Lcfg.c and Rcc_Cfg.h
*                    Only clock enalble feature is implemented
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void RCC_Init(void)
{
    uint8 i;

    // Enable clock
    for (i = 0; i < NUM_PERIPHERAlS_ACTIVATED; i++)
    {
        uint32 peripheral = clockGatingConfig[i].peripheral;
        if (IS_AHP_Periphiral(peripheral))
        {
            RCC->AHBENR |= 1u << peripheral;
        }
        else if (IS_APB2_Periphiral(peripheral))
        {
            peripheral %= 32u;
            RCC->APB2ENR |= 1u << peripheral;
        }
        else if (IS_APB1_Periphiral(peripheral))
        {
            peripheral %= 64u;
            RCC->APB1ENR |= 1u << peripheral;
        }
    }
}

/******************************************************************************
* \Syntax          : void RCC_ClockEnable(RCC_PeriphiralsType peripheral)

* \Description     : Enable clock for a specific peripheral
*                    In runime
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void RCC_ClockEnable(Rcc_PeripheralsType peripheral)
{
    if (IS_AHP_Periphiral(peripheral))
    {
        RCC->AHBENR |= 1u << peripheral;
    }
    else if (IS_APB2_Periphiral(peripheral))
    {
        peripheral %= 32u;
        RCC->APB2ENR |= 1u << peripheral;
    }
    else if (IS_APB1_Periphiral(peripheral))
    {
        peripheral %= 64u;
        RCC->APB1ENR |= 1u << peripheral;
    }
}

/******************************************************************************
 * \Syntax          : void RCC_DisableClock(RCC_PeriphiralsType peripheral)
 *
 * \Description     : Disable clock for a specific peripheral
 *                    In runime
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void RCC_ClockDisable(Rcc_PeripheralsType peripheral)
{
    if (IS_AHP_Periphiral(peripheral))
    {
        RCC->AHBENR &= ~(1u << peripheral);
    }
    else if (IS_APB2_Periphiral(peripheral))
    {
        peripheral %= 32u;
        RCC->APB2ENR &= ~(1u << peripheral);
    }
    else if (IS_APB1_Periphiral(peripheral))
    {
        peripheral %= 64u;
        RCC->APB1ENR &= ~(1u << peripheral);
    }
}
/******************************************************************************
* \Syntax          : void RCC_PeripheralReset(RCC_PeriphiralsType peripheral)

* \Description     : Reset a specific peripheral
*                    In runime
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void RCC_PeripheralReset(Rcc_PeripheralsType peripheral)
{
    if (IS_APB2_Periphiral(peripheral))
    {
        peripheral %= 32u;
        RCC->APB2BRSTR |= (1u << peripheral);
    }
    else if (IS_APB1_Periphiral(peripheral))
    {
        peripheral %= 64u;
        RCC->APB1BRSTR |= 1u << peripheral;
    }
}


/******************************************************************************
* \Syntax          : void RCC_PeripheralReset(RCC_PeriphiralsType peripheral)

* \Description     : Reset a specific peripheral
*                    In runime
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : RCC_PeriphiralsType    requred peripherla to be clock enabled from Rcc_Types.h
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
uint32 RCC_GetPllClk_Freq(void)
{
    // not implemented yet
    return 0;
}

uint32 RCC_GetSysClk_Freq(void)
{
    uint8 SWS = (RCC->CFGR >> 2u) & 0x3u;

    switch (SWS)
    {
    case 0:
        return HSI_freq;
        break;
    case 1:
        return HSE_freq;
        break;
    case 2:
        return RCC_GetPllClk_Freq();
    }
}

uint32 RCC_GetHClk_Freq()
{
    uint32 HPRE = (RCC->CFGR >> 4u) & 0xf;
    uint8 AHBPrescaler = 0; //prescaler by shifts as shift righ 1 is devide by 2

    if (HPRE >= 8u)
        AHBPrescaler = HPRE - 7; // As shift by 1 is 8 which is devide by 2

    return (RCC_GetSysClk_Freq() >> AHBPrescaler); // shift right by 1 == devide by 2
}

uint32 RCC_GetPClk1_Freq()
{
    uint32 PPRE1 = (RCC->CFGR >> 8u) & 0x7;
    uint8 APB1Prescaler = 0; //prescaler by shifts as shift righ 1 is devide by 2


    if (PPRE1 >= 4u)
        APB1Prescaler = PPRE1 - 3; // As shift by 1 is 4 which is devide by 2

    return (RCC_GetHClk_Freq() >> APB1Prescaler); // shift right by 1 == devide by 2
}

uint32 RCC_GetPClk2_Freq()
{
    uint32 PPRE2 = (RCC->CFGR >> 11u) & 0x7;
    uint8 APB2Prescaler = 0; //prescaler by shifts as shift righ 1 is devide by 2


    if (PPRE2 >= 4u)
        APB2Prescaler = PPRE2 - 3; // As shift by 1 is 4 which is devide by 2

    return (RCC_GetHClk_Freq() >> APB2Prescaler); // shift right by 1 == devide by 2
}
/**********************************************************************************************************************
 *  END OF FILE: Rcc.c
 *********************************************************************************************************************/
