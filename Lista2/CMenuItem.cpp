#include "CMenuItem.h"

CMenuItem::~CMenuItem() {};

void CMenuItem::setParent(CMenuItem * parent){
	this->parent = parent;
}

std::string CMenuItem::getDescription(){
	return description;
}

void CMenuItem::printParseError(char expectedChar, char actualChar, int stringIndex){
	std::cout << EXPECTED_CHAR << expectedChar << BUT_GOT << actualChar << AT_INDEX << stringIndex << std::endl;
}

void CMenuItem::setName(std::string newName){
	this->name = newName;
}

void CMenuItem::setCommandName(std::string newCommand){
	this->command = newCommand;
}
