#pragma once
#include <string>
class CMenuItem {

public:
	virtual ~CMenuItem() = 0;
	virtual void run() = 0;
	virtual std::string toString() = 0;
	virtual std::string getName() = 0;
	virtual std::string getCommand() = 0;
	virtual void printLeaves() = 0;

protected:
	std::string command;
	std::string name;
};