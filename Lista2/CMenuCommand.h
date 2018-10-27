#pragma once
#include "CCommand.h"
#include "CMenuItem.h"
#include "Constants.h"
const std::string EMPTY_COMMAND = "Pusta komenda";
class CMenuCommand: public CMenuItem {
public:
	CMenuCommand(std::string name, std::string command);
	CMenuCommand(std::string name, std::string command, CCommand* myCommand);
	~CMenuCommand();
	void run();
	void setCommand(CCommand* newCommand);
	std::string toString();
	std::string getName();
	std::string getCommand();
	
private:
	CCommand * myCommand;
	void deleteCommand();
};
