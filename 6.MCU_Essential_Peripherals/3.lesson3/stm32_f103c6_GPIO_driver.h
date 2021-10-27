#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//includes

#include <stm32f103x6.h>
#include <sys/_stdint.h>

//config structure

typedef struct {
	uint16_t GPIO_PinNumber;	//specify the GPIO pin TO BE CONFIGURED.
								//this parameter MUST be set value of @ref GPIO_PINS_define.

	uint8_t GPIO_MODE;			//specify the GPIO pin MODE.
								//this parameter MUST be set value of @ref GPIO_MODE_defin.

	uint8_t GPIO_Output_speed;
}GPIO_pinConfig_t;




//==================================
//Macros Configration references
//==================================

//@ref GPIO_PINS_define
#define GPIO_PIN_0						((uint16_t)0x0001)
#define GPIO_PIN_1 						((uint16_t)0x0002)
#define GPIO_PIN_2 						((uint16_t)0x0004)
#define GPIO_PIN_3 						((uint16_t)0x0008)
#define GPIO_PIN_4 						((uint16_t)0x0010)
#define GPIO_PIN_5						((uint16_t)0x0020)
#define GPIO_PIN_6		 				((uint16_t)0x0040)
#define GPIO_PIN_7 						((uint16_t)0x0080)
#define GPIO_PIN_8 						((uint16_t)0x0100)
#define GPIO_PIN_9 						((uint16_t)0x0200)
#define GPIO_PIN_10 					((uint16_t)0x0400)
#define GPIO_PIN_11 					((uint16_t)0x0800)
#define GPIO_PIN_12 					((uint16_t)0x1000)
#define GPIO_PIN_13 					((uint16_t)0x2000)
#define GPIO_PIN_14 					((uint16_t)0x4000)
#define GPIO_PIN_15 					((uint16_t)0x8000)
#define GPIO_PIN_ALL					((uint16_t)0xffff)

//@ref GPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input
#define GPIO_MODE_Analog				(0x00000000U)
#define GPIO_MODE_INPUT_FLO				(0x00000001U)
#define GPIO_MODE_INPUT_PU				(0x00000002U)
#define GPIO_MODE_INPUT_PD				(0x00000003U)
#define GPIO_MODE_INPUT_AF				(0x00000008U)

#define GPIO_MODE_OUTPUT_PP				(0x00000004U)
#define GPIO_MODE_OUTPUT_OD				(0x00000005U)
#define GPIO_MODE_OUTPUT_AF_PP			(0x00000006U)
#define GPIO_MODE_OUTPUT_AF_OD			(0x00000007U)


//@ref GPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define GPIO_SPEED_10M					(0x00000001U)
#define GPIO_SPEED_2M					(0x00000002U)
#define GPIO_SPEED_50M					(0x00000003U)

//@ref GPIO_PIN_state
#define GPIO_PIN_set					0x1
#define GPIO_PIN_reset					0x0

//@ref GPIO_LOCK_define
#define GPIO_LOCK_OK					0x1
#define GPIO_LOCK_ERROR					0x0


/*
 * ====================================================================================================
 * 								APIs Supported by "MCAL GPIO DRIVER
 * ====================================================================================================
 */

void 		MCAL_GPIO_Init		(volatile GPIO_t* GPIOx, GPIO_pinConfig_t* PinConfig);
void 		MCAL_GPIO_DeInit	(volatile GPIO_t* GPIOx);
uint8_t 	MCAL_GPIO_ReadPin	(volatile GPIO_t* GPIOx, uint16_t PinNumber);
uint16_t 	MCAL_GPIO_ReadPort	(volatile GPIO_t* GPIOx);
void 		MCAL_GPIO_WritePin	(volatile GPIO_t* GPIOx, uint16_t PinNumber,uint8_t value);
void 	 	MCAL_GPIO_WritePort	(volatile GPIO_t* GPIOx, uint16_t value);
void 		MCAL_GPIO_TogglePin (volatile GPIO_t* GPIOx,uint16_t PinNumber);


#endif
