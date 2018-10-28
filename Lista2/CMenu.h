#pragma once
#include "CMenuItem.h"
#include <vector>
#include <iostream>
#include "Constants.h"

const std::string INCORRECT_INDEX = "Incorrect index";
const std::string INCORRECT_COMMAND = "No such command";
const std::string BACK = "back";

class CMenu: public CMenuItem {
public:
	CMenu(std::string name, std::string command);
	~CMenu();
	int addItem(CMenuItem* menuItem);
	void deleteItem(int index);
	CMenuItem* getItem(int index);
	void run();
	std::string getName();
	std::string getCommand();
	std::string toString();
	void printLeaves();
private:
	std::vector<CMenuItem*> myCommands;
	void printNameAndCommand();
	void printNames();
	bool indexCorrect(int index);
	int indexOfName(std::string name);
	int indexOfCommand(std::string command);
};
