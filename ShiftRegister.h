#pragma once

#include <stdint.h>

class ShiftRegister
{
	public:
		void set(uint8_t value);

	private:
		virtual void setSerialPin(bool value) = 0;
		virtual void setShiftPin(bool value) = 0;
		virtual void setStoragePin(bool value) = 0;

		void pulseShiftPin();
		void pulseStoragePin();
};

