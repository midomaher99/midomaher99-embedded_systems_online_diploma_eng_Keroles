/*
 * init.h
 *
 *  Created on: Jul 14, 2022
 *      Author: Maher
 */

#ifndef INIT_H_
#define INIT_H_
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: initializing PB2 & PD2 & PD3 as (HI-Z) INPUT
 * 			  PD5 & PD6 & PD7 as OUTPUT initially  SINK
 */
extern void IO_INIT();
//___________________________________________________________
/*
 * INPUT 	: NONE
 * OUTPUT 	: NONE
 * BRIEF	: initializing EXTI INT 0 to cause interrupt for ANY LOGICAL CHANGE detection
 * 								INT 1 to cause interrupt for RISING EDGE detection
 * 								INT 2 to cause interrupt for FALLING EDGE detection
 * 				and enabling these interrupts and enable interrupts globally
 */
extern void EXTI_INIT();

#endif /* INIT_H_ */
