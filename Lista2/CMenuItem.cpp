#include "CMenuItem.h"

CMenuItem::~CMenuItem() {};

void CMenuItem::setParent(CMenuItem * parent){
	this->parent = parent;
}

std::string CMenuItem::getDescription(){
	return description;
}

void CMenuItem::setName(std::string newName){
	this->name = newName;
}

void CMenuItem::setCommandName(std::string newCommand){
	this->command = newCommand;
}
