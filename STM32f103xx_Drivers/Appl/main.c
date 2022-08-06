#include "MemoryMap.h"
#include "PlatformTypes.h"
#include "Nvic.h"
#include "Rcc.h"
#include "Afio.h"
#include "port.h"
#include "Usart.h"

void recive_callback();

uint16 buffer=0;
int main()
{
	RCC->CFGR &= ~(0b11); //force system to use HSI RC
	NVIC_Init();
	RCC_Init();
	Port_Init();
	AFIO_Init();
	USART_Init();
	USART_EnableRxNotification(Usart_Usart1, recive_callback);
	
	
	while (1)
	{
	}
}
void recive_callback()
{
	USART_Recieve(Usart_Usart1,&buffer);
	USART_Send(Usart_Usart1,&buffer);

}
