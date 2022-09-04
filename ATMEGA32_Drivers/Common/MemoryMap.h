#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "PlatformTypes.h"

#define PORTA_BASE  (0x39)  
#define PORTB_BASE  (0x36)
#define PORTC_BASE  (0x33)
#define PORTD_BASE  (0x30)

typedef struct
{
    vuint8 PIN ;
    vuint8 DDR ;
    vuint8 PORT;
}IOPorts_Type;


#define IOA ((IOPorts_Type*)PORTA_BASE)
#define IOB ((IOPorts_Type*)PORTB_BASE)
#define IOC ((IOPorts_Type*)PORTC_BASE)
#define IOD ((IOPorts_Type*)PORTD_BASE)

#define IO(BASE)    ((IOPorts_Type*)BASE)
#endif