#pragma once
#include <string>
#include <iostream>
class CMenuItem {

public:
	virtual ~CMenuItem() = 0;
	virtual void run() = 0;
	virtual std::string toString() = 0;
	virtual std::string getName() = 0;
	virtual void setName(std::string newName);
	virtual std::string getCommand() = 0;
	virtual void setCommandName(std::string newCommand);
	virtual void search(std::string commandName) = 0;
	virtual void find(std::string commandName, std::string path) = 0;
	virtual void printDescription() = 0;
	virtual void setParent(CMenuItem* parent);
	virtual std::string getDescription();
	virtual std::string save() = 0;
	virtual int saveFromString(std::string tree, int startIndex) = 0;

protected:
	std::string command;
	std::string name;
	std::string description;
	CMenuItem* parent;
};