#pragma once

#include <stdint.h>

class Lcd
{
public:
	union Command
	{
		struct
		{
			bool DB0: 1;
			bool DB1: 1;
			bool DB2: 1;
			bool DB3: 1;
			bool DB4: 1;
			bool DB5: 1;
			bool DB6: 1;
			bool DB7: 1;
		};
		uint8_t data;
	};

public:
	void initDisplay();
	void clear();

	void output(const char &character);
	void output(const char *string);
	void output(const uint16_t val);

private:
	void setPos(const uint8_t &pos);

	virtual void execute(const Command &cmd, bool RS, uint16_t delay_us) = 0;
};

