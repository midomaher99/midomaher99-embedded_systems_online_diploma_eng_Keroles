/*
 * Afio.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: to use AFIO driver you should set reqiured remaping  
 *               and MUST set the number of required Remaped peripherals in Afio_Cfg.h
 *                
 *         NOTE: To Use the Afio module you MUST Enable its clock gating from RCC module driver
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Afio_Types.h"
#include "Afio_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

//remapping to be set b user
const Afio_ConfigType Afio_config[NUM_REMAPPED_PERIPHERALS]=
{   //Remapped Peripheral
    //from Afio_types.h
    {AFIO_USART1_0}
};
/**********************************************************************************************************************
 *  END OF FILE: Afio_Lcfg.c
 *********************************************************************************************************************/
