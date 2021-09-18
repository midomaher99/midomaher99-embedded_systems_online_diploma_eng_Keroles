extern unsigned int _stack_top;
extern void main ();
extern unsigned int _E_RODATA;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void Reset_Handler		();
void NMI_Handler			() 	__attribute__((alias("Reset_Handler")));
void HardFault_Handler		() 	__attribute__((alias("Reset_Handler")));
void MemManage_Fault_Handler()	__attribute__((alias("Reset_Handler")));
void Bus_Fault_Handler		() 	__attribute__((alias("Reset_Handler")));
void Usage_Fault_Handler	() 	__attribute__((alias("Reset_Handler")));






unsigned int vectors[] __attribute__((section(".vectors"))) =
{
	(unsigned int) &_stack_top,
	(unsigned int) &Reset_Handler,
	(unsigned int) &NMI_Handler,
	(unsigned int) &HardFault_Handler,
	(unsigned int) &MemManage_Fault_Handler,
	(unsigned int) &Bus_Fault_Handler,
	(unsigned int) &Usage_Fault_Handler
};

void Reset_Handler()
{
	/*copying .data*/
	int i ;
	unsigned int size =(unsigned char*) &_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* src =(unsigned char*) &_E_RODATA;
	unsigned char* dst =(unsigned char*) &_S_DATA;
	for (i = 0; i < size; i++)
	{
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	}

	/*initialize .bss*/
	size =(unsigned char*) &_E_BSS - (unsigned char*)&_S_BSS;
	dst =(unsigned char*) &_S_BSS;

	for (i = 0; i < size; i++)
	{
		*((unsigned char*)dst++) = (unsigned char)0;
	}
	main();
}