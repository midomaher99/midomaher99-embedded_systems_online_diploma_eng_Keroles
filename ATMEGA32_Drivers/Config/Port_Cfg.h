/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"
#include "PlatformTypes.h"
/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
#define PULLUP_ENABLE   1u

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    Port_PinType pinID;
    Port_PinDirectionType direction;
    Port_InternallAttach internallAttach;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern Port_ConfigType Port_ConfigArray[];
extern uint8 Port_ConfigArraySize;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
