#pragma once
#include "CCommand.h"
#include "CMenuItem.h"
#include "Constants.h"

class CMenuCommand: public CMenuItem {
public:
	CMenuCommand();
	CMenuCommand(std::string name, std::string command, std::string description);
	CMenuCommand(std::string name, std::string command, CCommand* myCommand, std::string description);
	~CMenuCommand();
	void run();
	void setCommand(CCommand* newCommand);
	void setDescription(std::string newDescription);
	std::string toString();
	std::string getName();
	std::string getCommand();
	void search(std::string commandName);
	std::string save();
	int readFromString(std::string tree, int startIndex);
	
private:
	CCommand* myCommand;
	std::string description;
	void deleteCommand();
	void find(std::string commandName, std::string path);
	void printDescription();
};
