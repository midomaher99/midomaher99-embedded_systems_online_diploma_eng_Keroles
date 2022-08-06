/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

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

static Usart_CallBacksType Usart_CallBacksArray[5] = {NULL};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
 * \Description     : Describe this service
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : parameterName   Parameter Describtion
 * \Parameters (out): None
 * \Return value:   : Std_ReturnType  E_OK
 *                                    E_NOT_OK
 *******************************************************************************/
void USART_Init(void)
{
	uint8 i;
	uint32 base;
	uint32 fClk, div, mantissa, fraction;
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
			fraction = (fraction + 100u) / 100u;
		else
			fraction /= 100u;

		mantissa = mantissa + ((fraction & 0x10u) >> 4u); // add carry if found to mantissa
		fraction = fraction & 0xFu;						  // fraction without carry to fit the frist foue bits

		USART(base)->BRR = 0x0; // reseting BRR reg
		USART(base)->BRR |= (fraction << 0) | (mantissa << 4u);

		USART(base)->CR1 |= (Usart_Config[i].mode << 2u);
		USART(base)->CR1 |= (1u << 13u); // Enable USART instance
	}
}

void USART_Send(Usart_InstanceType USARTx, uint16 *buffer)
{
	if (!(((USART(USARTx)->CR1) >> 7) & 1u)) // polling mechanism
		while (!(USART(USARTx)->SR & 1 << 7))
			;

	switch (((USART(USARTx)->CR1) >> 12) & 1u) // cheack word length
	{
	case 0: // word length = 8bit
		USART(USARTx)->DR = *buffer & 0xFF;
		break;
	case 1: // word length = 9bit
		USART(USARTx)->DR = *buffer & 0x1FF;
		break;
	}
}

void USART_Recieve(Usart_InstanceType USARTx, uint16 *buffer)
{
	if (!(((USART(USARTx)->CR1) >> 5) & 1u)) // polling mechanism
		while (!(USART(USARTx)->SR & 1 << 5))
			;

	if ((((USART(USARTx)->CR1) >> 12) & 1u) == 1) // word length = 9bit
	{
		if ((((USART(USARTx)->CR1) >> 12) & 1u) == 1) // parity control enabled
			*buffer = (uint16)USART(USARTx)->DR & 0xFF;
		else // parity control disabled
			*buffer = (uint16)USART(USARTx)->DR & 0x1FF;
	}
	else // word length = 8bit
	{
		if ((((USART(USARTx)->CR1) >> 12) & 1u) == 1) // parity control enabled
			*buffer = (uint16)USART(USARTx)->DR & 0x7F;
		else // parity control disabled
			*buffer = (uint16)USART(USARTx)->DR & 0xFF;
	}
}

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
	}

	USART(USARTx)->CR1 |= 1 << 7; // enable Tx buffer empty interrupt
}
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
	}

	USART(USARTx)->CR1 |= 1 << 5; // enable Rx buffer empty interrupt
}

void USART1_IRQHandler()
{
	if(((USART1->SR >>7u)&1u) && ((USART1->CR1 >>7u)&1u))	// Tx buffer empty and TxE interrupt enabled
		Usart_CallBacksArray[0].Tx_CallBack();		
	else if(((USART1->SR >>5u)&1u) && ((USART1->CR1 >>5u)&1u)) // Rx buffer not empty and RxNE interrupt enabled
		Usart_CallBacksArray[0].Rx_CallBack();
}
void USART2_IRQHandler()
{
	if(((USART2->SR >>7u)&1u) && ((USART2->CR1 >>7u)&1u))	// Tx buffer empty and TxE interrupt enabled
		Usart_CallBacksArray[0].Tx_CallBack();		
	else if(((USART2->SR >>5u)&1u) && ((USART2->CR1 >>5u)&1u)) // Rx buffer not empty and RxNE interrupt enabled
		Usart_CallBacksArray[0].Rx_CallBack();
}
void USART3_IRQHandler()
{
	if(((USART3->SR >>7u)&1u) && ((USART3->CR1 >>7u)&1u))	// Tx buffer empty and TxE interrupt enabled
		Usart_CallBacksArray[0].Tx_CallBack();		
	else if(((USART3->SR >>5u)&1u) && ((USART3->CR1 >>5u)&1u)) // Rx buffer not empty and RxNE interrupt enabled
		Usart_CallBacksArray[0].Rx_CallBack();
} 
void UART4_IRQHandler()
{
	if(((UART4->SR >>7u)&1u) && ((UART4->CR1 >>7u)&1u))	// Tx buffer empty and TxE interrupt enabled
		Usart_CallBacksArray[0].Tx_CallBack();		
	else if(((UART4->SR >>5u)&1u) && ((UART4->CR1 >>5u)&1u)) // Rx buffer not empty and RxNE interrupt enabled
		Usart_CallBacksArray[0].Rx_CallBack();
}                         
void UART5_IRQHandler()
{
	if(((UART5->SR >>7u)&1u) && ((UART5->CR1 >>7u)&1u))	// Tx buffer empty and TxE interrupt enabled
		Usart_CallBacksArray[0].Tx_CallBack();		
	else if(((UART5->SR >>5u)&1u) && ((UART5->CR1 >>5u)&1u)) // Rx buffer not empty and RxNE interrupt enabled
		Usart_CallBacksArray[0].Rx_CallBack();
}


/**********************************************************************************************************************
 *  END OF FILE: Usart.c
 *********************************************************************************************************************/