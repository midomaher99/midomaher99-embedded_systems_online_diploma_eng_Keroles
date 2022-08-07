/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Rcc_Types.h
 *       Module:  RCC
 *
 *  Description:  Types to be used in RCC driver
 *
 *********************************************************************************************************************/
#ifndef RCC_TYPES_H
#define RCC_TYPES_H


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HSI_freq (8000000u)

// If HSE OSC is connected the hardware, its freq MUST be set in the HSE_freq macro
#define HSE_freq (0u)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

// least two digits for bit offset
// and most two digits for the register offset
typedef enum
{
    // Note: AS the registers is in an order of AHB then APB2 Then APB1
    //       Then AHP peripherlas will take the index of its bit number
    //            APB2 peripherlas will take the ndex of its bit number +32
    //            APB1 peripherlas will take the ndex of its bit number +64

    // Only used peripherals are implemented

    // AHP Bus peripherals
    // to be implemented

    // APB2 Bus peripherals
    RCC_AFIO_EN = 0u + 32u,

    RCC_IOPA_EN = 2u + 32u,
    RCC_IOPB_EN,
    RCC_IOPC_EN,
    RCC_IOPD_EN,
    RCC_IOPE_EN,
    RCC_IOPF_EN,
    RCC_IOPG_EN,

    RCC_USART1_EN = 14u + 32u,

    // APB1 Bus peripherals
    RCC_USART2_EN = 17u + 64u,
    RCC_USART3_EN,
    RCC_UART4_EN,
    RCC_UART5_EN

} Rcc_PeripheralsType;

typedef struct
{
    Rcc_PeripheralsType peripheral;
} Rcc_ClockGatingConfigType;

#endif /* RCC_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Rcc_Types.h
 *********************************************************************************************************************/
