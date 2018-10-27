#include "CMenu.h"

void CMenu::run() {
	std::string userInput;
	bool finished = false;
	while (!finished) {
		printNameAndCommand();
		printNames();
		std::cin >> userInput;
		if (userInput == BACK) {
			finished = true;
		}
		else {
			int index = indexOfCommand(userInput);
			if (index == -1) {
				std::cout << INCORRECT_COMMAND << std::endl;
			}
			else {
				myCommands[index]->run();
			}
		}
	}	
}

CMenu::CMenu(std::string name, std::string command){
	this->name = name;
	this->command = command;
}

CMenu::~CMenu(){
	for (int i = 0; i < myCommands.size(); i++) {
		delete myCommands[i];
	}
}

int CMenu::addItem(CMenuItem* menuItem){
	bool duplicateName = indexOfName(menuItem->getName()) != -1;
	
	if (duplicateName) {
		return ERR_DUPLICATE_NAME;
	}
	else {
		bool duplicateCommand = indexOfCommand(menuItem->getCommand()) != -1;
		
		if (duplicateCommand) {
			return ERR_DUPLICATE_COMMAND;
		}
		else {
			myCommands.push_back(menuItem);
			return SUCCESS;
		}
	}
}

void CMenu::deleteItem(int index){
	if (indexCorrect(index)) {
		delete myCommands[index];
		myCommands.erase(myCommands.begin() + index);
	}
	else {
		std::cout << INCORRECT_INDEX;
	}
}

CMenuItem* CMenu::getItem(int index){
	if (indexCorrect(index)) {
		return myCommands[index];
	}
	else {
		std::cout << INCORRECT_INDEX;
		return nullptr;
	}
}

std::string CMenu::getName(){
	return name;
}

std::string CMenu::getCommand(){
	return command;
}

void CMenu::printNameAndCommand() {
	std::cout << this->toString() << std::endl;
}

void CMenu::printNames(){
	for (int i = 0; i < myCommands.size(); i++) {
		std::cout << i + 1 << DOT << myCommands[i]->toString() << std::endl;
	}
}

std::string CMenu::toString(){
	return name + SPACE + LEFT_BRACKET + command + RIGHT_BRACKET;
}

bool CMenu::indexCorrect(int index){
	return index >= 0 && index < myCommands.size();
}

int CMenu::indexOfName(std::string name)
{
	int index = -1;
	for (int i = 0; i < myCommands.size() && index == -1; i++) {
		if (name == myCommands[i]->getName()) {
			index = i;
		}
	}
	return index;
}

int CMenu::indexOfCommand(std::string command)
{
	int index = -1;
	for (int i = 0; i < myCommands.size() && index == -1; i++) {
		if (command == myCommands[i]->getCommand()) {
			index = i;
		}
	}
	return index;
}

