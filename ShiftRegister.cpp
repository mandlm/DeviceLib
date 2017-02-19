#include "ShiftRegister.h"

void ShiftRegister::set(uint8_t value)
{
	for (uint8_t bit = 0; bit < 8; ++bit)
	{
		setSerialPin(value & (1 << (7 - bit)));
		pulseShiftPin();
	}

	pulseStoragePin();
}

void ShiftRegister::pulseShiftPin()
{
	setShiftPin(false);
	setShiftPin(true);
	setShiftPin(false);
}

void ShiftRegister::pulseStoragePin()
{
	setStoragePin(false);
	setStoragePin(true);
	setStoragePin(false);
}

