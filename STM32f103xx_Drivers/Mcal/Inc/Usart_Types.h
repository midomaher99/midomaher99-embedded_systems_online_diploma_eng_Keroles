/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef USART_TYPES_H
#define USART_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	Usart_Usart1 = 0x40013800u,
	Usart_Usart2 = 0x40004400u,
	Usart_Usart3 = 0x40004800u,
	Usart_Uart4 = 0x40004C00u,
	Usart_Uart5 = 0x40005000u
} Usart_InstanceType;

typedef enum
{
	USART_RX_Only = 0b1u,
	USART_TX_Only = 0b10,
	Usart_TX_RX = 0b11u
} Usart_ModeType;

typedef uint32 Usart_BaudRateType;

typedef enum
{
	Usart_8bitsWord = 0b0u,
	Usart_9bitsWord = 0b1u
} Usart_wordLengthType;

typedef enum
{
	Usart_OneStopBit = 0b00u,	  // 1 stop bit
	Usart_HalfStopBit = 0b01u,	  // 0.5 stop bit not available for UART4 and UART5
	Usart_TwoStopBits = 0b10u,	  // 2 stop bits
	Usart_OneHalfStopBits = 0b11u // 1.5 stop bits not available for UART4 and UART5

} Usart_StopBitsType;

typedef enum
{ // IMPORTANT NOTE: parity bit is inserted at the MSB position if it is enabled
  // (9th bit if wordLength = 9; 8th bit if wordLength = 8)

	Usart_NoParity = 0b00,
	Usart_EvenParity = 0b10,
	Usart_OddParity = 0b11

} Usart_ParityType;

typedef void (*Usart_Notification)();

typedef struct 
{
	Usart_Notification Tx_CallBack;
	Usart_Notification Rx_CallBack;
}Usart_CallBacksType;


typedef struct
{
	Usart_InstanceType USARTx;
	Usart_ModeType mode;
	Usart_BaudRateType BaudRate;
	Usart_wordLengthType wordLength;
	Usart_StopBitsType stopBits;
	Usart_ParityType parity;

} Usart_ConfigType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* USART_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Usart_Types.h
 *********************************************************************************************************************/
