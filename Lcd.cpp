#include "Lcd.h"

#include <stdlib.h>

void Lcd::initDisplay()
{	
	static const Command resetCommand{0, 0, 0, 0, 1, 1, 0, 0};
	static const Command fourBitModeCommand{0, 1, 0, 0, 0, 0, 0, 0};		
	static const Command functionSetCommand{0, 0, 1, 1, 0, 1, 0, 0};
	static const Command displayOnOffCommand{0, 0, 1, 1, 0, 0, 0, 0};
	static const Command entryModeCommand{0, 1, 1, 0, 0, 0, 0, 0};

	execute(resetCommand, false, 5000);
	execute(resetCommand, false, 100);
	execute(resetCommand, false, 0);

	execute(fourBitModeCommand, false, 0);
	execute(functionSetCommand, false, 39);
	execute(displayOnOffCommand, false, 39);
	clear();
	execute(entryModeCommand, false, 39);
}

void Lcd::clear()
{
	execute({1, 0, 0, 0, 0, 0, 0, 0}, false, 1530);
}

void Lcd::setPos(const uint8_t &pos)
{
	Command posCommand;
	posCommand.data = pos | (1 << 7);
	
	execute(posCommand, false, 39);
}

void Lcd::output(const char &character)
{
	execute((const Command &)character, true, 43);
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

void Lcd::output(const uint16_t val)
{
	static char buf[5];
	output(itoa(val, buf, 10));
}

