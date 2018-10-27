#include "CMenuCommand.h"


CMenuCommand::CMenuCommand(std::string name, std::string command){
	this->name = name;
	this->command = command;
	myCommand = nullptr;
}

CMenuCommand::CMenuCommand(std::string name, std::string command, CCommand* myCommand){
	this->name = name;
	this->command = command;
	this->myCommand = myCommand;
}

CMenuCommand::~CMenuCommand(){
	deleteCommand();
}


void CMenuCommand::run(){
	if (myCommand == nullptr) {
		std::cout << EMPTY_COMMAND;
	}
	else {
		myCommand->runCommand();
	}
}

void CMenuCommand::setCommand(CCommand* newCommand){
	deleteCommand();
	myCommand = newCommand;
}

std::string CMenuCommand::toString(){
	return name + SPACE + LEFT_BRACKET + command + RIGHT_BRACKET;
}

std::string CMenuCommand::getName(){
	return name;
}

std::string CMenuCommand::getCommand(){
	return command;
}

void CMenuCommand::deleteCommand(){
	if (myCommand != nullptr) {
		delete myCommand;
		myCommand = nullptr;
	}
}

