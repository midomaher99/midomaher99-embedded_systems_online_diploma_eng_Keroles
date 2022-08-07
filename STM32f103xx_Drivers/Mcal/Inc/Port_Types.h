/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_types.h
 *       Module:  Poirt/ GPIO
 *
 *  Description:  Types to be used in Port driver
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPE_H
#define PORT_TYPE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define LCKK_MASK (1u << 16u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
    // Most four significant digits are the least four digits of port base address
    // The third least significant digit is 0 for pins in the CRL register
    //                                  and 1 for pins in the CRH register
    // the least two digits indicates bit offset in CRL and CRH registers

    PORT_PA0 = 0x0800000u,
    PORT_PA1 = 0x0800004u,
    PORT_PA2 = 0x0800008u,
    PORT_PA3 = 0x080000Cu,
    PORT_PA4 = 0x0800010u,
    PORT_PA5 = 0x0800014u,
    PORT_PA6 = 0x0800018u,
    PORT_PA7 = 0x080001Cu,
    PORT_PA8 = 0x0800100u,
    PORT_PA9 = 0x0800104u,
    PORT_PA10 = 0x0800108u,
    PORT_PA11 = 0x080010Cu,
    PORT_PA12 = 0x0800110u,
    PORT_PA13 = 0x0800114u,
    PORT_PA14 = 0x0800118u,
    PORT_PA15 = 0x080011Cu,

    PORT_PB0 = 0x0C00000u,
    PORT_PB1 = 0x0C00004u,
    PORT_PB2 = 0x0C00008u,
    PORT_PB3 = 0x0C0000Cu,
    PORT_PB4 = 0x0C00010u,
    PORT_PB5 = 0x0C00014u,
    PORT_PB6 = 0x0C00018u,
    PORT_PB7 = 0x0C0001Cu,
    PORT_PB8 = 0x0C00100u,
    PORT_PB9 = 0x0C00104u,
    PORT_PB10 = 0x0C00108u,
    PORT_PB11 = 0x0C0010Cu,
    PORT_PB12 = 0x0C00110u,
    PORT_PB13 = 0x0C00114u,
    PORT_PB14 = 0x0C00118u,
    PORT_PB15 = 0x0C0011Cu,

    PORT_PC0 = 0X1000000u,
    PORT_PC1 = 0X1000004u,
    PORT_PC2 = 0X1000008u,
    PORT_PC3 = 0X100000Cu,
    PORT_PC4 = 0X1000010u,
    PORT_PC5 = 0X1000014u,
    PORT_PC6 = 0X1000018u,
    PORT_PC7 = 0X100001Cu,
    PORT_PC8 = 0X1000100u,
    PORT_PC9 = 0X1000104u,
    PORT_PC10 = 0X1000108u,
    PORT_PC11 = 0X100010Cu,
    PORT_PC12 = 0X1000110u,
    PORT_PC13 = 0X1000114u,
    PORT_PC14 = 0X1000118u,
    PORT_PC15 = 0X100011Cu,

    PORT_PD0 = 0x1400000u,
    PORT_PD1 = 0x1400004u,
    PORT_PD2 = 0x1400008u,
    PORT_PD3 = 0x140000Cu,
    PORT_PD4 = 0x1400010u,
    PORT_PD5 = 0x1400014u,
    PORT_PD6 = 0x1400018u,
    PORT_PD7 = 0x140001Cu,
    PORT_PD8 = 0x1400100u,
    PORT_PD9 = 0x1400104u,
    PORT_PD10 = 0x1400108u,
    PORT_PD11 = 0x140010Cu,
    PORT_PD12 = 0x1400110u,
    PORT_PD13 = 0x1400114u,
    PORT_PD14 = 0x1400118u,
    PORT_PD15 = 0x140011Cu,

    PORT_PE0 = 0x1800000u,
    PORT_PE1 = 0x1800004u,
    PORT_PE2 = 0x1800008u,
    PORT_PE3 = 0x180000Cu,
    PORT_PE4 = 0x1800010u,
    PORT_PE5 = 0x1800014u,
    PORT_PE6 = 0x1800018u,
    PORT_PE7 = 0x180001Cu,
    PORT_PE8 = 0x1800100u,
    PORT_PE9 = 0x1800104u,
    PORT_PE10 = 0x1800108u,
    PORT_PE11 = 0x180010Cu,
    PORT_PE12 = 0x1800110u,
    PORT_PE13 = 0x1800114u,
    PORT_PE14 = 0x1800118u,
    PORT_PE15 = 0x180011Cu,

    PORT_PF0 = 0x1C00000u,
    PORT_PF1 = 0x1C00004u,
    PORT_PF2 = 0x1C00008u,
    PORT_PF3 = 0x1C0000Cu,
    PORT_PF4 = 0x1C00010u,
    PORT_PF5 = 0x1C00014u,
    PORT_PF6 = 0x1C00018u,
    PORT_PF7 = 0x1C0001Cu,
    PORT_PF8 = 0x1C00100u,
    PORT_PF9 = 0x1C00104u,
    PORT_PF10 = 0x1C00108u,
    PORT_PF11 = 0x1C0010Cu,
    PORT_PF12 = 0x1C00110u,
    PORT_PF13 = 0x1C00114u,
    PORT_PF14 = 0x1C00118u,
    PORT_PF15 = 0x1C001C1u,

    PORT_PG0 = 0x2000000u,
    PORT_PG1 = 0x2000004u,
    PORT_PG2 = 0x2000008u,
    PORT_PG3 = 0x200000Cu,
    PORT_PG4 = 0x2000010u,
    PORT_PG5 = 0x2000014u,
    PORT_PG6 = 0x2000018u,
    PORT_PG7 = 0x200001Cu,
    PORT_PG8 = 0x2000100u,
    PORT_PG9 = 0x2000104u,
    PORT_PG10 = 0x2000108u,
    PORT_PG11 = 0x200010Cu,
    PORT_PG12 = 0x2000110u,
    PORT_PG13 = 0x2000114u,
    PORT_PG14 = 0x2000118u,
    PORT_PG15 = 0x200011Cu,
} Port_PinType;

typedef enum
{
    // the Most significant digit is the ODR bit
    // the other digits is CNFy[1:0] and MODEy[1:0] in CRL and CRH registers

    PORT_AnalogInput = 0b00000,
    PORT_FloatingInput = 0b00100,
    PORT_PullUpInput = 0b11000,
    PORT_PullDownInput = 0b01000,

    PORT_GP_PushPullOutput_10MHZ = 0b00001,
    PORT_GP_PushPullOutput_2MHZ = 0b00010,
    PORT_GP_PushPullOutput_50MHZ = 0b00011,

    PORT_GP_OpenDrainOutput_10MHZ = 0b00101,
    PORT_GP_OpenDrainOutput_2MHZ = 0b00110,
    PORT_GP_OpenDrainOutput_50MHZ = 0b00111,

    PORT_AF_PushPullOutput_10MHZ = 0b01001,
    PORT_AF_PushPullOutput_2MHZ = 0b01010,
    PORT_AF_PushPullOutput_50MHZ = 0b01011,

    PORT_AF_OpenDrainOutput_10MHZ = 0b01101,
    PORT_AF_OpenDrainOutput_2MHZ = 0b01110,
    PORT_AF_OpenDrainOutput_50MHZ = 0b01111

} Port_PinConfigurationType;

typedef struct
{
    Port_PinType pinID;
    Port_PinConfigurationType Configuration;
} Port_ConfigType;

#endif /* PORT_TYPE_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/
