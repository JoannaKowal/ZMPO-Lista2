#pragma once
#include "CMenuItem.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <iterator>
#include "Constants.h"
#include "CMenuCommand.h"


const std::string INCORRECT_INDEX = "Incorrect index";
const std::string INCORRECT_COMMAND = "No such command";
const std::string BACK = "back";

class CMenu: public CMenuItem {
public:
	CMenu();
	CMenu(std::string name, std::string command);
	~CMenu();
	int addItem(CMenuItem* menuItem);
	void deleteItem(int index);
	CMenuItem* getItem(int index);
	void run();
	std::string getName();
	std::string getCommand();
	std::string toString();
	void setParent(CMenuItem* parent);
	void search(std::string commandName);
	std::string save();
	int saveFromString(std::string tree, int startIndex);
	
private:
	std::vector<CMenuItem*> myCommands;
	void printNameAndCommand();
	void printNames();
	bool indexCorrect(int index);
	int indexOfName(std::string name);
	int indexOfCommand(std::string command);
	void find(std::string commandName, std::string path);
	void splitCommand(std::string currentCommand, std::vector<std::string> &args);
	void printDescription(); 

};
