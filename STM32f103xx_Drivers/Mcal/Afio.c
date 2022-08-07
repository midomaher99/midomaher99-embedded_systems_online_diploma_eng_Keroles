/*
 * Afio.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 *      details: Alternate Functions I/O driver to remap GPIO pins to its alternate functions
 *               Only the Init function is implemented and its configrations is set in Afio_Lcfg.c and Afio_cfg.h file
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Afio_Types.h"
#include "Afio_Cfg.h"
#include "MemoryMap.h"
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void AFIO_Init(void)
* \Description     : initialize AFIO module to remap GPIO pins to its alternate functions
                     from Afio_Lcfg.c and AFIO_Cfg.h
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void AFIO_Init(void)
{
    uint8 i;
    uint8 bitShift;
    uint8 mask;
    uint8 value;
    for (i = 0; i < NUM_REMAPPED_PERIPHERALS; i++)
    {
        mask = Afio_config[i].alternatePeripheral >> 8;
        bitShift = (Afio_config[i].alternatePeripheral & 0x0F0) >> 4;
        value = Afio_config[i].alternatePeripheral & 0x00F;

        AFIO->MAPR &= ~((uint32)mask << (uint32)bitShift); // reset the MAPR register
        AFIO->MAPR |= (uint32)value << (uint32)bitShift;   // Enable required remap
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Afio.c
 *********************************************************************************************************************/
