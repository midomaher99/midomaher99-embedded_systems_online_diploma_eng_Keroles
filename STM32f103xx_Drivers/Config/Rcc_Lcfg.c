/*
 * main.c
 *
 *      Author:  ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      
 *      details: to use RCC driver you should set the peripherlas to be enabled in this file
 * 				 and set the number of required peripherals is Rcc_Cfg.h
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Rcc_Cfg.h"
#include "Rcc_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Rcc_ClockGatingConfigType clockGatingConfig[NUM_PERIPHERAlS_ACTIVATED] =
{	
	//Peripheral
	//from Rcc_Types.h
	{RCC_USART1_EN},
	{RCC_AFIO_EN},
	{RCC_IOPA_EN}
};

/**********************************************************************************************************************
 *  END OF FILE: Rcc_Lcfg.c
 *********************************************************************************************************************/
