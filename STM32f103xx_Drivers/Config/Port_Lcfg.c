/*
 * Port_Lcfg.c
 *
 *      Author:  ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      
 *      details: to use Port driver you should set requred Pins modes from this file 
 *               and MUST set the number of required Pins to be Activated in NVIC_Cfg.h
 * 
 *         NOTE: To Use the Port Driver you MUST Enable the GPIO of required port clock gating from RCC module driver
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Cfg.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Port_ConfigType Port_Config[NUM_PINS_ACTIVATED]=
{
    //Pin ID                Mode
    //from Port_Types.h     from Port_Types.h       
    {PORT_PA9,              PORT_GP_PushPullOutput_2MHZ},
    {PORT_PA10,             PORT_FloatingInput}

};

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
