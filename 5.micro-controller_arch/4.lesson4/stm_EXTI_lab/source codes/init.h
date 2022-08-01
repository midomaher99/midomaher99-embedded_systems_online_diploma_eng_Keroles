/*
 * init.h
 *
 * @author         : ENG/Mohamed Mostafa Maher
 * @contact		   : mohamed.mostafa.maher.999@gmail.com
 */

#ifndef INIT_H_
#define INIT_H_
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: opening clock gating for IOPA and AFIO peripherals
 * 			  with no change in clock source or frequency
 */
extern void CLOCK_INIT();
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: initializing PA0 as floating input and PA13 as output PUSH-PULL with max CLK 2MHZ
 */
extern void GPIO_INIT();
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: routing PA0 to EXTI line 0
 */
extern void AFIO_INIT();
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: initializing EXTI line0 as a rising edge triggered and unmask EXTI line 0
 */
extern void EXTI_INIT();
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: enabling IRQ6 ---> EXTI0
 */
extern void NVIC_INIT();

#endif /* INIT_H_ */
