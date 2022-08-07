/*
 * main.c
 *
 *      Author:  ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      
 *      details: to use nvic driver you should set requred interrrupts to be
 *               activated and its priority from this file and MUST set the number of 
 *               required interrupts to be activated in NVIC_Cfg.h
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Nvic_Cfg.h"
#include "Nvic_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Nvic_ConfigType Nvic_Config[NUM_INTERRUPTS_ACTIVATED]=
{
    //Module                    Priotiy
    //From Nvic_TYPES.h         from 0 ->15
    {NVIC_USART1,               0}
};
/**********************************************************************************************************************
 *  END OF FILE: Nvic_Lcfg.c
 *********************************************************************************************************************/
