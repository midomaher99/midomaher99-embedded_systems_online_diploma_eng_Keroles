#include "Usart_Types.h"

extern void USART_Init(void);
extern void USART_Send(Usart_InstanceType USARTx, uint16 *buffer);

extern void USART_Recieve(Usart_InstanceType USARTx, uint16 *buffer);

extern void USART_EnableTxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr);
extern void USART_EnableRxNotification(Usart_InstanceType USARTx, Usart_Notification callBackPtr);