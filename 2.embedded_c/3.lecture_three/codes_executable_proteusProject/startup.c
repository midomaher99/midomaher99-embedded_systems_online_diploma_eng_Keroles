#include <stdint.h>

extern unsigned int _stack_top;

extern unsigned int _E_RODATA;
extern unsigned int _E_DATA;
extern unsigned int _S_DATA;
extern unsigned int _E_BSS;
extern unsigned int _S_BSS;

extern int main();

void Reset_Handler();

void Default_Handler()__attribute__((alias("Reset_Handler")));
void NMI_Handler() __attribute__((alias("Reset_Handler")));	
void H_fault_Handler() __attribute__((alias("Reset_Handler")));
void MM_Fault_Handler() __attribute__((alias("Reset_Handler")));
void Bus_Fault() __attribute__((alias("Reset_Handler")));
void Usage_Fault_Handler() __attribute__((alias("Reset_Handler")));


uint32_t vectors [] __attribute__((section(".vectors"))) = {
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler
};


void Reset_Handler(){

	unsigned int data_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ; 
	unsigned char* src = (unsigned char*)&_E_RODATA;
	unsigned char* dst = (unsigned char*)&_S_DATA;
	
	int i;
	for(i = 0; i < data_size; i++){
		*((unsigned char*)dst++) = *((unsigned char*)src++);
	}
	
	unsigned int bss_size = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS;
	dst = (unsigned char*)&_S_BSS;
	
	for(i = 0; i < bss_size; i++){
		*((unsigned char*)dst++) = (unsigned char)0;
	}
	
	
	main();
	
}