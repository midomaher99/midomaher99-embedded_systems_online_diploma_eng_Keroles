/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Usart.h
 *       Module:  USARt
 *
 *  Description:  USART driver header file     
 *  
 *********************************************************************************************************************/
#ifndef USART_H
#define USART_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"
#include "Usart_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void USART_Init(void)
 * \Description     : Initialize the USART configurations (Frame, baudrate amd the direction(Tx, Rx OR Tx/Rx))
 * 					  This configurations is set in Usart_Lcfg.c
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void USART_Init(void);

/******************************************************************************
 * \Syntax          : void USART_Send(Usart_InstanceType USARTx, uint16 data)
 * \Description     : Sends the data required to be sent by USART To the USARt data buffer 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Usart_InstanceType 	the USARt instance used From Usart_types.h
 * 					  uint16 data			the data required to be sent        
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
extern void USART_Send(Usart_InstanceType USARTx, uint16 data);

/******************************************************************************
 * \Syntax          : void USART_Recieve(Usart_InstanceType USARTx, uint16 *data)
 * \Description     : Recieves the data arrives the USARt data buffer 
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : None Reentrant
 * \Parameters (in) : Usart_InstanceType 	the USARt instance used From Usart_types.h        
 * \Parameters (out): uint16 *buffer		Pointer to the buffer that will recieves the data from the functin
 * \Return value:   : None
 *******************************************************************************/
extern void USART_Recieve(Usart_InstanceType USARTx, uint16 *data);

/******************************************************************************
 * \Syntax          : void USART_EnableTxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr)
 * \Description     : Enables the transmit buffer empty TxE interrupt and assign a user defined Callback function to be 
 * 					  Excecuted when the interrupt occures
 * 					  NOTE : user must enable USARTx global interrupt from NVIC driver
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Usart_InstanceType 	the USARt instance used From Usart_types.h        
 * \Parameters (out): Usart_Notification	the desired callback function to be execurtes From Usart_types.h
 * 						NOTE : the callback MUST be void function(void)
 * \Return value:   : None
 *******************************************************************************/
extern void USART_EnableTxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr);

/******************************************************************************
 * \Syntax          : void USART_EnableRxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr)
 * \Description     : Enables the Recieve buffer not empty RxNE interrupt and assign a user defined Callback function to be 
 * 					  Excecuted when the interrupt occures
 * 					  NOTE : user must enable USARTx global interrupt from NVIC driver
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Usart_InstanceType 	the USARt instance used From Usart_types.h        
 * \Parameters (out): Usart_Notification	the desired callback function to be execurtes From Usart_types.h
 * 						NOTE : the callback MUST be void function(void)
 * \Return value:   : None
 *******************************************************************************/
extern void USART_EnableRxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr);
 
#endif  /* USART_H */

/**********************************************************************************************************************
 *  END OF FILE: Usart.h
 *********************************************************************************************************************/
 