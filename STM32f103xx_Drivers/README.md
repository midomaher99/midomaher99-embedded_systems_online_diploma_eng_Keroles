# STM32F103xx drivers
  All codes in this folder are aligned with (MISRA 2012) standard. Codes are checked using cppcheck/addons.
## Implemented Features
### NVIC Driver
	1. Enabling and prioritizing global interrupt of a specific peripheral.
	2. Disabling global interrupt of a specific peripheral.
		NOTE: Not all peripherals interrupt are implemented.
			  The implemented interrupts till now:
				1. USARTx 	x ->1, 2 or 3. 
				2. UARTx	x->1, 2.
    
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
      		NOTE: Calculating these clocks frequences if the Sysclk is driven by PLLCLK is not implemented yet.

### AFIO Driver
	Rammping of GPIO pins to ther alternate fun
