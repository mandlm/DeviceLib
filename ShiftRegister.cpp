#include "ShiftRegister.h"

void ShiftRegister::set(uint8_t value)
{
	for (uint8_t bit = 0; bit < 8; ++bit)
	{
		bool currentBit = (value >> (7 - bit)) & 1;
		setSerialPin(currentBit);
		pulseShiftPin();
	}

	pulseStoragePin();
}



