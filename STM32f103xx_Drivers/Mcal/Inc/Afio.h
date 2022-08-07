/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Afio.h
 *       Module:  Aleternate Function I/O (AFIO)
 *
 *  Description:  Afio driver header file
 *
 *********************************************************************************************************************/
#ifndef AFIO_H
#define AFIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Afio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void AFIO_Init(void)
* \Description     : initialize AFIO module to remap GPIO pins to its alternate functions
                     from Afio_Lcfg.c and AFIO_Cfg.h
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
extern void AFIO_Init(void);

#endif /* AFIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Afio.h
 *********************************************************************************************************************/