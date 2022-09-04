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
#include "PlatformTypes.h"
#include "Timer0_Cfg.h"
#include "Timer0_Types.h"
#include <avr/io.h>

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static uint8 clkSrc;
static Timer0_Notification callbacksArray[2] = {NULL, NULL};
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
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void TIMER0_Init()
{
	TCCR0 &=~(0b1001U);
	TCCR0 |= Timer0Config.mode << 3U;
	clkSrc= Timer0Config.clkSrc;
}
/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void TIMER0_Start()
{
	TCCR0 &=~(0b111U);
	TCCR0 |= clkSrc;
}
/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void TIMER0_Sop()
{
	TCCR0 &=~(0b111U);
	TCCR0 |= Timer0_NoClk;
}
/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void Timer0_EnableNotification_COMP(Timer0_Notification VPtr_callback)
{
    callbacksArray[0] = VPtr_callback;
    TIMSK |= 1U<<1U;
}

void Timer0_DisableNotification_COMP()
{
     TIMSK &=~ (1U<<1U);
}


void Timer0_EnableNotification_OVF(Timer0_Notification VPtr_callback)
{
    callbacksArray[1] = VPtr_callback;
    TIMSK |= 1U;
}

void Timer0_DisableNotification_OVF()
{
     TIMSK &=~ (1U);
}



void __vector_10(void) __attribute__((signal));
void __vector_10()  //TIMER0 COMP
{
    if(callbacksArray[0]!=NULL)
    {
        callbacksArray[0]();
    }
    else
    {

    }
}

void __vector_11(void) __attribute__((signal));
void __vector_11()  //TIMER0 OVF
{
    if(callbacksArray[1]!=NULL)
    {
        callbacksArray[1]();
    }
    else
    {

    }
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/


