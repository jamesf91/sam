#ifndef _CAN_H_INCLUDED
#define _CAN_H_INCLUDED

#include "variant.h"
#include <stdio.h>

Class CANClass{
public:
	CANClass(Can *_can, uint32_t _id, void(*_initCb)(void));
private:
}

#if CAN_INTERFACES_COUNT > 0
extern CANClass CAN;
#endif

#endif