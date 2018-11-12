#pragma once
#include "CCommand.h"
#include "CMenuItem.h"
#include "Constants.h"
const std::string EMPTY_COMMAND = "Pusta komenda";
class CMenuCommand: public CMenuItem {
public:
	CMenuCommand(std::string name, std::string command, std::string description);
	CMenuCommand(std::string name, std::string command, CCommand* myCommand, std::string description);
	~CMenuCommand();
	void run();
	void setCommand(CCommand* newCommand);
	std::string toString();
	std::string getName();
	std::string getCommand();
	void search(std::string commandName);
	std::string save();
	
	
private:
	CCommand* myCommand;
	std::string description;
	void deleteCommand();
	void find(std::string commandName, std::string path);
	void printDescription();
};
