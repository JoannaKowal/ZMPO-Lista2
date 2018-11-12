#include "CMenuCommand.h"


CMenuCommand::CMenuCommand(std::string name, std::string command, std::string description){
	this->name = name;
	this->command = command;
	this->description = description;
	myCommand = nullptr;
}

CMenuCommand::CMenuCommand(std::string name, std::string command, CCommand* myCommand, std::string description){
	this->name = name;
	this->command = command;
	this->myCommand = myCommand;
	this->description = description;
}

CMenuCommand::~CMenuCommand(){
	deleteCommand();
}


void CMenuCommand::run(){
	if (myCommand == nullptr) {
		std::cout << EMPTY_COMMAND << std::endl;
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

void CMenuCommand::search(std::string commandName){
	if (parent == nullptr) {
		find(commandName, std::string());
	}
	else {
		parent->search(commandName);
	}
}

std::string CMenuCommand::save(){
	std::string result;
	result += "['";
	result += this->name;
	result += "','";
	result += this->command;
	result += "','";
	result += this->description;
	result += "']";
	return result;
}

void CMenuCommand::deleteCommand(){
	if (myCommand != nullptr) {
		delete myCommand;
		myCommand = nullptr;
	}
}

void CMenuCommand::find(std::string commandName, std::string path){
	if (this->command == commandName) {
		std::cout << path + commandName << std::endl;
	}
}

void CMenuCommand::printDescription(){
	std::cout << description << std::endl;
}
	



