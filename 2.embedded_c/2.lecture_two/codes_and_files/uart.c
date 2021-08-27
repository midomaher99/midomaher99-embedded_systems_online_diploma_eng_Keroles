#define UART0DR *(volatile unsigned int*)((unsigned int*)0x101f1000)
void send_uart_message(char* message)
{

	while (*message != '\0')
	{
		UART0DR = (unsigned int) *message;
		message++;
	}
}