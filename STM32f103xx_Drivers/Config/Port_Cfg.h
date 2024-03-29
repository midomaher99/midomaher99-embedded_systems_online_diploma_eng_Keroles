/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  Port/ GPIO
 *
 *  Description:  to configure the Port module you should use this file and Port_Lcfg.c file
 *
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/
//to be set by user
#define NUM_PINS_ACTIVATED (2u)

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Port_ConfigType Port_Config[NUM_PINS_ACTIVATED];


#endif /* PORT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
