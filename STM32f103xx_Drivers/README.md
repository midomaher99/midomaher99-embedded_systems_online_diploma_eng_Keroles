# STM32F103xx drivers
  All codes in this folder are aligned with (MISRA 2012) standard. Codes are checked using cppcheck/addons.

### NVIC Driver
	1. Enabling and prioritizing global interrupt of a specific peripheral.
	2. Disabling global interrupt of a specific peripheral.
		NOTE: Not all peripherals interrupt are implemented.
		      The implemented interrupts till now:
		      1. USARTx 	x ->1, 2 or 3. 
		      2. UARTx		x->1, 2.

### RCC Driver
	1. Enabling clock gating for a specific peripheral.
  	2. Disabling clock gating for a specific peripheral.
  	3. Resetting a specific peripheral
      		NOTE: Not all peripherals are implemented to apply upper features.
	              The implemented peripherals till now:
		        1. USARTx 	x ->1, 2 or 3. 
		        2. UARTx	  x->1, 2.
            		3. IOPx     x->A, B, C, D, E, F and G.
            		4. AFIO.
  	4. Calculating the driving clock frequency of APB1 and APB2 busses
      		NOTE: Calculating these clock frequences if the Sysclk is driven by PLLCLK is not implemented yet.

### AFIO Driver
	Rammping of GPIO pins to ther alternate functions.
		NOTE: Not all alternate functions remmaping are implemented.
		      The implemented alternate function rammaping till now:
				1. USART1_0 	Tx->PA9, Rx->PA10
    				2. USART1_1 	Tx->PB6, Rx->PB7
   				3. USART2_0  	CTS->PA0, RTS->PA1,Tx->PA2, Rx->PA3, CK->PA4
    				4. USART2_1  	CTS->PD3, RTS->PD4,Tx->PD5, Rx->PD6, CK->PD7
    				5. USART3_00 	CTS->PB13, RTS->PB14,Tx->PB10, Rx->PB11, CK->PB12
    				6. USART3_01 	CTS->PB13, RTS->PB44,Tx->PC10, Rx->PC11, CK->PC12
    				7. USART3_11  	CTS->PD11, RTS->PD12,Tx->PD8,  Rx->PD9,  CK->PD10

### PORT Driver
	Setting GPIO pis configurations.

### USART Driver
	ONLY the UART basic functionalities and configuratins
- Implemented finctonalities
	1. Send data.
	2. Recieve data.
	3. Setting callback function to be executed when recieving data.
	4. Setting callback function to be executed when transmitting data done.
- Implented Configurations
	1. Mode -> Send only, Receive only or send and recieve.
	2. Baudrate.
	3. Word length.
	5. Number of stop bits.
	6. Parity type.
