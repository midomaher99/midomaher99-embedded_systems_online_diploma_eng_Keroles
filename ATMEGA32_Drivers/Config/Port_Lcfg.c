/*
 * main.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: to use Port driver you should set required Pins directions and internall attach 
 *               from this file
 */


 
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

//IMPORTANT NOTE: To use Internall PullUp you MUST set the PULLUP_ENABLE macro to 1 in Port_Cfg.h file

Port_ConfigType Port_ConfigArray[]=
{
    //options for each field is in Port_Types
    //pinId     direction   internall attach
    {Port_PA0,  Port_OUTPUT, Port_NoInternalAttach},
    {Port_PD2,  Port_OUTPUT, Port_NoInternalAttach},
    {Port_PB3,  Port_INPUT, Port_InternallPullUp}
};

uint8 Port_ConfigArraySize= sizeof(Port_ConfigArray)/sizeof(Port_ConfigType);
/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
