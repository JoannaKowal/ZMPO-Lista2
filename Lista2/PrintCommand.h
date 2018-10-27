#pragma once
#include "CCommand.h"
class PrintCommand: public CCommand {
public:
	PrintCommand(std::string text);
	void runCommand();
private:
	std::string myText;
};