#include "Lcd.h"

#include <stdlib.h>

void Lcd::initDisplay()
{	
	static const Command resetCommand{0, 0, 0, 0, 1, 1, 0, 0};

	execute(resetCommand, false, 5.0);
	execute(resetCommand, false, 0.1);
	execute(resetCommand, false, 0.0);
	execute({0, 1, 0, 0, 0, 0, 0, 0}, false, 0.0);

	// function set
	execute({0, 0, 1, 1, 0, 1, 0, 0}, false, 0.039);

	// display on/off
	execute({0, 0, 1, 1, 0, 0, 0, 0}, false, 0.039);

	clear();

	// entry mode
	execute({0, 1, 1, 0, 0, 0, 0, 0}, false, 0.039);
}

void Lcd::clear()
{
	execute({1, 0, 0, 0, 0, 0, 0, 0}, false, 1.53);
}

void Lcd::setPos(const uint8_t &pos)
{
	Command posCommand;
	posCommand.data = pos | (1 << 7);
	
	execute(posCommand, false, 0.039);
}

void Lcd::output(const char &character)
{
	execute((const Command &)character, true, 0.043);

}

void Lcd::output(const char *string)
{
	uint8_t pos = 0;
	while (string != nullptr && *string != 0)
	{
		if (pos == 8)
		{
			setPos(40);
		}
		output(*string++);
		pos++;
	}
}

void Lcd::output(const uint16_t &val)
{
	static char buf[5];
	output(itoa(val, buf, 10));
}

