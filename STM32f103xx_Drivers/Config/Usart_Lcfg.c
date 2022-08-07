/*
 * Port_Lcfg.c
 *
 *      Author:  ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      
 *      details: to use Port driver you should set requred Pins modes from this file 
 *               and MUST set the number of required Pins to be Activated in NVIC_Cfg.h
 * 
 *         NOTE: -To Use the USART Driver you MUST Enable the required USART instance's clock gating from RCC module driver
 *               -Only UART basic functionalities is implemented
 *              
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Usart_Types.h"
#include "Usart_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Usart_ConfigType  Usart_Config[NUM_USARTs_ACTIVATED]=
{   //USART instance        mode                    Baud rate   word length             stop bits               parity
    //From Usart_Types.h    From Usart_Types.h                  from Usart_Types.h      from Usart_Types.h      from Usart_Types.h
    {Usart_Usart1,          Usart_TX_RX,            115200,       Usart_9bitsWord,        Usart_OneStopBit,       Usart_OddParity}
};

/**********************************************************************************************************************
 *  END OF FILE: Usart_Lcfg.c
 *********************************************************************************************************************/
