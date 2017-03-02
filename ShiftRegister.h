#pragma once

#include <stdint.h>

class ShiftRegister
{
	public:
		void set(uint8_t value);

	private:
		virtual void setSerialPin(bool value) = 0;

		virtual void pulseShiftPin() = 0;
		virtual void pulseStoragePin() = 0;
};

