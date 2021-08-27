#include "uart.h"
char  uart_message[]="Learn-in-depth: Mohamed Mostafa";
int main()
{
	send_uart_message(uart_message);
	return 0;
}