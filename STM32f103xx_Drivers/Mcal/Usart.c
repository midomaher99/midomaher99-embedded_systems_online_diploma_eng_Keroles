/*
 * main.c
 *
 *      Author:  ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *
 *      details: USART driver
 * 				ONLY UART basic functionalities are implemented
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemoryMap.h"
#include "PlatformTypes.h"
#include "Usart_Cfg.h"
#include "Usart_Types.h"
#include "Rcc.h"
/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

static Usart_CallBacksType Usart_CallBacksArray[5] ; 
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void USART_Init(void)
{
	uint8 i;
	uint32 base;
	uint32 fClk;
	uint32 div;
	uint32 mantissa;
	uint32 fraction;
	for (i = 0; i < NUM_USARTs_ACTIVATED; i++)
	{
		base = Usart_Config[i].USARTx;
		// reseting CR1 and required pin for stop bits in CR2
		USART(base)->CR1 = 0x0u;
		USART(base)->CR2 &= ~(0b11u << 12u);

		USART(base)->CR1 |= (Usart_Config[i].parity << 9u) | (Usart_Config[i].wordLength << 12u);
		USART(base)->CR2 |= (Usart_Config[i].stopBits << 12u);

		// baud rate calculations
		// check 27.3.4 Fractional baud rate generation in TM4C123 TRM

		// get the USART instance clock frequency
		switch (Usart_Config[i].USARTx)
		{
		case Usart_Usart1:
			fClk = RCC_GetPClk2_Freq();
			break;
		default:
			fClk = RCC_GetPClk2_Freq();
			break;
		}

		// eqn is MULTIPLIED by 100 to avoid float using
		div = (fClk * 25u) / (Usart_Config[i].BaudRate * 4u);

		mantissa = div / 100u;		   // the real part of USARTDIV
		fraction = (div % 100u) * 16u; // the fractional part Multiplied by 16

		// rounding the fractional part to nearest decemal number
		if ((fraction % 100u) >= 50u)
		{
			fraction = (fraction + 100u) / 100u;
		}
		else
		{
			fraction /= 100u;
		}
		mantissa = mantissa + ((fraction & 0x10u) >> 4u); // add carry if found to mantissa
		fraction = fraction & 0xFu;						  // fraction without carry to fit the frist foue bits

		USART(base)->BRR = 0x0; // reseting BRR reg
		USART(base)->BRR |= ((uint32)fraction << 0u) | ((uint32)mantissa << 4u);

		USART(base)->CR1 |= ((uint32)Usart_Config[i].mode << 2u); // Tx, Rx or Tx/Rx
		USART(base)->CR1 |= (1u << 13u);						  // Enable USART instance
		
		USART(base)->DR =(uint8) 0b11;
	}
}

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
void USART_Send(Usart_InstanceType USARTx, uint16 data)
{

	 if (!((uint32)(USART(USARTx)->CR1) & ( 1u<< 7u))) // polling mechanism
	 {
	 	while (!((uint32)(USART(USARTx)->SR )& (1u << 7u)))
		{
		}
	}
	else
	{
	}

	switch (((uint32)(USART(USARTx)->CR1) >> 12u) & 1u) // cheack word length
	{
	case 0: // word length = 8bit
		USART(USARTx)->DR = data & 0xFFu;
		break;
	case 1: // word length = 9bit
		USART(USARTx)->DR = data & 0x1FFu;
		break;
	default:
		break;
	}
}

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
void USART_Recieve(Usart_InstanceType USARTx, uint16 *data)
{
	if (!(((uint32)(USART(USARTx)->CR1))&(1u<< 5u))) // polling mechanism
	{
		while (!(((uint32)(USART(USARTx)->SR))&( 1u << 5u)))
		{
		}
	}
	else
	{
	}
	if ((((uint32)(USART(USARTx)->CR1) >> 12) & 1u) == 1u) // word length = 9bit
	{
		if ((((uint32)(USART(USARTx)->CR1) >> 12u) & 1u) == 1u) // parity control enabled
		{
			*data = (uint16)USART(USARTx)->DR & 0xFFu;
		}
		else // parity control disabled
		{
			*data = (uint16)USART(USARTx)->DR & 0x1FFu;
		}
	}
	else // word length = 8bit
	{
		if (((uint32)((uint32)(USART(USARTx)->CR1) >> 12u) & 1u) == 1u) // parity control enabled
		{
			*data = (uint16)USART(USARTx)->DR & 0x7Fu;
		}
		else // parity control disabled
		{
			*data = (uint16)USART(USARTx)->DR & 0xFFu;
		}
	}
}

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
void USART_EnableTxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr)
{
	switch (USARTx)
	{
	case Usart_Usart1:
		Usart_CallBacksArray[0].Tx_CallBack = callBackPtr;
		break;
	case Usart_Usart2:
		Usart_CallBacksArray[1].Tx_CallBack = callBackPtr;
		break;
	case Usart_Usart3:
		Usart_CallBacksArray[2].Tx_CallBack = callBackPtr;
		break;
	case Usart_Uart4:
		Usart_CallBacksArray[3].Tx_CallBack = callBackPtr;
		break;
	case Usart_Uart5:
		Usart_CallBacksArray[4].Tx_CallBack = callBackPtr;
		break;
	default:
		break;
	}

	USART(USARTx)->CR1 |= 1u << 7u; // enable Tx buffer empty interrupt
}

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
void USART_EnableRxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr)
{
	switch (USARTx)
	{
	case Usart_Usart1:
		Usart_CallBacksArray[0].Rx_CallBack = callBackPtr;
		break;
	case Usart_Usart2:
		Usart_CallBacksArray[1].Rx_CallBack = callBackPtr;
		break;
	case Usart_Usart3:
		Usart_CallBacksArray[2].Rx_CallBack = callBackPtr;
		break;
	case Usart_Uart4:
		Usart_CallBacksArray[3].Rx_CallBack = callBackPtr;
		break;
	case Usart_Uart5:
		Usart_CallBacksArray[4].Rx_CallBack = callBackPtr;
		break;
	default:
		break;
	}

	USART(USARTx)->CR1 |= 1u << 5u; // enable Rx buffer empty interrupt
}

/**********************************************************************************************************************
 *  Handlers
 *********************************************************************************************************************/

void USART1_IRQHandler()
{
	if (((USART1->SR >> 7u) & 1u) && ((USART1->CR1 >> 7u) & 1u)) // Tx buffer empty and TxE interrupt enabled
	{
		Usart_CallBacksArray[0].Tx_CallBack();
	}
	else if (((USART1->SR >> 5u) & 1u) && ((USART1->CR1 >> 5u) & 1u)) // Rx buffer not empty and RxNE interrupt enabled
	{
		Usart_CallBacksArray[0].Rx_CallBack();
	}
	else
	{
	}
}
void USART2_IRQHandler()
{
	if (((USART2->SR >> 7u) & 1u) && ((USART2->CR1 >> 7u) & 1u)) // Tx buffer empty and TxE interrupt enabled
	{
		Usart_CallBacksArray[0].Tx_CallBack();
	}
	else if (((USART2->SR >> 5u) & 1u) && ((USART2->CR1 >> 5u) & 1u)) // Rx buffer not empty and RxNE interrupt enabled
	{
		Usart_CallBacksArray[0].Rx_CallBack();
	}
	else
	{
	}
}
void USART3_IRQHandler()
{
	if (((USART3->SR >> 7u) & 1u) && ((USART3->CR1 >> 7u) & 1u)) // Tx buffer empty and TxE interrupt enabled
	{
		Usart_CallBacksArray[0].Tx_CallBack();
	}
	else if (((USART3->SR >> 5u) & 1u) && ((USART3->CR1 >> 5u) & 1u)) // Rx buffer not empty and RxNE interrupt enabled
	{
		Usart_CallBacksArray[0].Rx_CallBack();
	}
	else
	{
	}
}
void UART4_IRQHandler()
{
	if (((UART4->SR >> 7u) & 1u) && ((UART4->CR1 >> 7u) & 1u)) // Tx buffer empty and TxE interrupt enabled
	{
		Usart_CallBacksArray[0].Tx_CallBack();
	}
	else if (((UART4->SR >> 5u) & 1u) && ((UART4->CR1 >> 5u) & 1u)) // Rx buffer not empty and RxNE interrupt enabled
	{
		Usart_CallBacksArray[0].Rx_CallBack();
	}
	else
	{
	}
}
void UART5_IRQHandler()
{
	if (((UART5->SR >> 7u) & 1u) && ((UART5->CR1 >> 7u) & 1u)) // Tx buffer empty and TxE interrupt enabled
	{
		Usart_CallBacksArray[0].Tx_CallBack();
	}
	else if (((UART5->SR >> 5u) & 1u) && ((UART5->CR1 >> 5u) & 1u)) // Rx buffer not empty and RxNE interrupt enabled
	{
		Usart_CallBacksArray[0].Rx_CallBack();
	}
	else
	{
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Usart.c
 *********************************************************************************************************************/