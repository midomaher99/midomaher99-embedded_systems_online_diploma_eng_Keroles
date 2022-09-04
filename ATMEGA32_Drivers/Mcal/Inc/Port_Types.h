/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  IO
 *
 *  Description:  Types to be used in Port driver
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MemoryMap.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    // Most two digits refers to the port base address

    Port_PA0 = 0x390,
    Port_PA1 = 0x391,
    Port_PA2 = 0x392,
    Port_PA3 = 0x393,
    Port_PA4 = 0x394,
    Port_PA5 = 0x395,
    Port_PA6 = 0x396,
    Port_PA7 = 0x397,

    Port_PB0 = 0x360,
    Port_PB1 = 0x361,
    Port_PB2 = 0x362,
    Port_PB3 = 0x363,
    Port_PB4 = 0x364,
    Port_PB5 = 0x365,
    Port_PB6 = 0x366,
    Port_PB7 = 0x367,

    Port_PC0 = 0x330,
    Port_PC1 = 0x331,
    Port_PC2 = 0x332,
    Port_PC3 = 0x333,
    Port_PC4 = 0x334,
    Port_PC5 = 0x335,
    Port_PC6 = 0x336,
    Port_PC7 = 0x337,

    Port_PD0 = 0x300,
    Port_PD1 = 0x301,
    Port_PD2 = 0x302,
    Port_PD3 = 0x303,
    Port_PD4 = 0x304,
    Port_PD5 = 0x305,
    Port_PD6 = 0x306,
    Port_PD7 = 0x307
} Port_PinType;

typedef enum
{
    Port_INPUT = 0u,
    Port_OUTPUT
} Port_PinDirectionType;

typedef enum
{
    Port_NoInternalAttach,
    Port_InternallPullUp
} Port_InternallAttach;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
