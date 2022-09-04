#include "Dio_Types.h"
#include "PlatformTypes.h"
#include "MemoryMap.h"
void DIO_WriteChannel(Dio_ChannelType pinId, Dio_ChannellevelType level)
{
    uint8 portBase = pinId >> 4;
    uint8 pinNumber = pinId & 0xf;

    IO(portBase)->PORT &= ~ (1<<pinNumber); 
    IO(portBase)->PORT |=  (level<<pinNumber);
}

Dio_ChannellevelType DIO_ReadChannel(Dio_ChannelType pinId)
{
    uint8 portBase = pinId >> 4;
    uint8 pinNumber = pinId & 0xf;

    return( (IO(portBase)->PIN >> pinNumber)&1); 
}

void DIO_FlipChannel(Dio_ChannelType pinId)
{
    uint8 portBase = pinId >> 4;
    uint8 pinNumber = pinId & 0xf;
    IO(portBase)->PORT ^= 1u << pinNumber;
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    IO(PortId)->PORT = Level;
}


Dio_PortLevelType Dio_ReadWritePort(Dio_PortType PortId)
{
    return(IO(PortId)->PIN);
}