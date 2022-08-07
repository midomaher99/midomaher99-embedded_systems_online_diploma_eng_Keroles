/*
 * Rcc.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: Reset and Clock control driver to enable/ disable clocks and reseting required peripherals,
 *               and calculat HCLK, PclK1 and PCLK2 frequincies
 */
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

#define IS_AHP_Periphiral(PeripheralId)  ((PeripheralId) < AHP_PERIPHERAL)

#define IS_APB2_Periphiral(PeripheralId) ((PeripheralId) < APB2_PERIPHERAL)

#define IS_APB1_Periphiral(PeripheralId) ((PeripheralId) < APB1_PERIPHERAL)

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : uint32 RCC_GetPllClk_Freq(void)

* \Description     : Get the PLlClk frequency (not implemented yet)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32 the PllCLK frequency
*******************************************************************************/
uint32 RCC_GetPllClk_Freq(void)
{
    // not implemented yet
    return 0;
}
/******************************************************************************
* \Syntax          : uint32 RCC_GetSysClk1_Freq();

* \Description     : Get the SysClk frequency
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of pclk1
*******************************************************************************/
uint32 RCC_GetSysClk_Freq(void)
{
    uint8 SWS = (RCC->CFGR >> 2u) & 0x3u;
    uint32 SysClk =0;
    switch (SWS)
    {
    case 0:
        SysClk = HSI_freq; // this line violates (MISRA 2012) advisory Rule 15.5
        break;
    case 1:
        SysClk = HSE_freq; // this line violates (MISRA 2012) advisory Rule 15.5
        break;
    case 2:
        SysClk = RCC_GetPllClk_Freq(); // this line violates (MISRA 2012) advisory Rule 15.5
        break;
    default:
        break;
    }
    return SysClk ;
}

/******************************************************************************
* \Syntax          : uint32 RCC_GetHClk_Freq();

* \Description     : Get the HClk  frequency (AHP driving clock)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of HCLK
*******************************************************************************/
uint32 RCC_GetHClk_Freq()
{
    uint32 HPRE = (RCC->CFGR >> 4u) & 0xf;
    uint8 AHBPrescaler = 0; // prescaler by shifts as shift righ 1 is devide by 2

    if (HPRE >= 8u)
    {
        AHBPrescaler = HPRE - 7; // As shift by 1 is 8 which is devide by 2
    }
    else{}

    return (RCC_GetSysClk_Freq() >> AHBPrescaler); // shift right by 1 == devide by 2
}

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
            RCC->AHBENR |= 1u << (uint32)peripheral;
        }
        else if (IS_APB2_Periphiral(peripheral))
        {
            peripheral %= 32u;
            RCC->APB2ENR |= 1u << (uint32)peripheral;
        }
        else if (IS_APB1_Periphiral(peripheral))
        {
            peripheral %= 64u;
            RCC->APB1ENR |= 1u << (uint32)peripheral;
        }
        else{}
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
    Rcc_PeripheralsType locPeripheral = peripheral;

    if (IS_AHP_Periphiral(locPeripheral))
    {
        RCC->AHBENR |= 1u << (uint32)locPeripheral;
    }
    else if (IS_APB2_Periphiral(locPeripheral))
    {
        locPeripheral %= 32u; // this line violates (MISRA 2012) advisory Rule 17.8
        RCC->APB2ENR |= 1u << (uint32)locPeripheral;
    }
    else if (IS_APB1_Periphiral(locPeripheral))
    {
        locPeripheral %= 64u; // this line violates (MISRA 2012) advisory Rule 17.8
        RCC->APB1ENR |= 1u << (uint32)locPeripheral;
    }
    else{}
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
    Rcc_PeripheralsType locPeripheral = peripheral;

    if (IS_AHP_Periphiral(locPeripheral))
    {
        RCC->AHBENR &= ~(1u << (uint32)locPeripheral);
    }
    else if (IS_APB2_Periphiral(locPeripheral))
    {
        locPeripheral %= 32u; //this line violates (MISRA 2012) advisory Rule 17.8
        RCC->APB2ENR &= ~(1u << (uint32)locPeripheral);
    }
    else if (IS_APB1_Periphiral(locPeripheral))
    {
        locPeripheral %= 64u; //this line violates (MISRA 2012) advisory Rule 17.8
        RCC->APB1ENR &= ~(1u << (uint32)locPeripheral);
    }
    else{}
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
    Rcc_PeripheralsType locPeripheral = peripheral;
    if (IS_APB2_Periphiral(locPeripheral))
    {
        locPeripheral %= 32u;
        RCC->APB2BRSTR |= (1u << (uint32)locPeripheral);
    }
    else if (IS_APB1_Periphiral(locPeripheral))
    {
        locPeripheral %= 64u; 
        RCC->APB1BRSTR |= 1u << (uint32)locPeripheral;
    }
    else{}
}

/******************************************************************************
* \Syntax          : uint32 RCC_GetPClk1_Freq();

* \Description     : Get the PClk 2 frequency (APB1 peripherals driving clock)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of pclk1
*******************************************************************************/
uint32 RCC_GetPClk1_Freq()
{
    uint32 PPRE1 = (((uint32)RCC->CFGR) >> 8u) & 0x7;
    uint8 APB1Prescaler = 0; // prescaler by shifts as shift righ 1 is devide by 2

    if (PPRE1 >= 4u)
    {
        APB1Prescaler = PPRE1 - 3; // As shift by 1 is 4 which is devide by 2
    }
    else{}
    return (RCC_GetHClk_Freq() >> (uint32)APB1Prescaler); // shift right by 1 == devide by 2
}

/******************************************************************************
* \Syntax          : uint32 RCC_GetPClk1_Freq();

* \Description     : Get the PClk 2 frequency (APB2 peripherals driving clock)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : uint32     the frequency of pclk2
*******************************************************************************/
uint32 RCC_GetPClk2_Freq()
{
    uint32 PPRE2 = (((uint32)RCC->CFGR) >> 11u) & 0x7;
    uint8 APB2Prescaler = 0; // prescaler by shifts as shift righ 1 is devide by 2

    if (PPRE2 >= 4u)
    {
        APB2Prescaler = PPRE2 - 3; // As shift by 1 is 4 which is devide by 2
    }
    return (RCC_GetHClk_Freq() >> (uint32)APB2Prescaler); // shift right by 1 == devide by 2
}
/**********************************************************************************************************************
 *  END OF FILE: Rcc.c
 *********************************************************************************************************************/
