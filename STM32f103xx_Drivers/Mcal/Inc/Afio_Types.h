/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Afio.h
 *       Module:  Aleternate Function I/O (AFIO)
 *
 *  Description:  Types which is used eith Afio driver
 *                ONLY USART remaping is implemented till now
 *
 *********************************************************************************************************************/
#ifndef AFIO_TYPER_H
#define AFIO_TYPER_H

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    // most significanr digit is the Mask of this mapped pereipheral
    // middle digit for bit shift
    // and least significant digit for remaping value
    // EX: 0x320
    // 3->This alternate function has 2 bits in MAPR register so its Mask is 0b11 = 0x3
    // 2->This alternate function is located at bit 2 in MAPR register
    // 0->its required to write 0 in the corresponding bit to enable this alternate function

    // can't use more than one alternate function option in a time for same peripheral

    // NOTE: Only USART alternate function is implemented

    // USART1
    AFIO_USART1_0 = 0x20, // Tx->PA9, Rx->PA10
    AFIO_USART1_1 = 0x21, // Tx->PB6, Rx->PB7

    // USART2
    AFIO_USART2_0 = 0x30, // CTS->PA0, RTS->PA1,Tx->PA2, Rx->PA3, CK->PA4
    AFIO_USART2_1 = 0x31, // CTS->PD3, RTS->PD4,Tx->PD5, Rx->PD6, CK->PD7

    // USART3
    AFIO_USART3_00 = 0x40, // CTS->PB13, RTS->PB14,Tx->PB10, Rx->PB11, CK->PB12
    AFIO_USART3_01 = 0x41, // CTS->PB13, RTS->PB44,Tx->PC10, Rx->PC11, CK->PC12
    AFIO_USART3_11 = 0x43  // CTS->PD11, RTS->PD12,Tx->PD8,  Rx->PD9,  CK->PD10

} Afio_AlternatefunctionsType;

typedef struct
{
    Afio_AlternatefunctionsType alternatePeripheral;
} Afio_ConfigType;

#endif /* AFIO_TYPER_H */

/**********************************************************************************************************************
 *  END OF FILE: Afio_Types.h
 *********************************************************************************************************************/
