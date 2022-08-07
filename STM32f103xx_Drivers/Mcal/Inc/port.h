/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port/ GPIO
 *
 *  Description:  Port driver header file
 * 
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Port_Init(void)

 * \Description     : Initialize the GPIO pins configuraions from port_Cfg.h and Port_Lcfg.c
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void Port_Init(void);

/******************************************************************************
 * \Syntax          : void Port_SetMode(Port_PinType pinId, Port_PinConfigurationType configuration)
 * \Description     : set GPIO pin configuration in run time
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Port_PinType   				the required pin to set its
 * 													configuration from Port_Types.h
 *
 * 					  Port_PinConfigurationType		the required pin configuratoin
 * 													from Port_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void Port_SetConfigration(Port_PinType pinId, Port_PinConfigurationType configuration);
#endif /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
