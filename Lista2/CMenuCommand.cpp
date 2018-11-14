#include "CMenuCommand.h"


CMenuCommand::CMenuCommand(){

	myCommand = nullptr;
}

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

void CMenuCommand::setDescription(std::string newDescription){
	this->description = newDescription;
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
	result += LEFT_SQUARE_BRACKET_APOSTROPHE;
	result += this->name;
	result += APOSTROPHE_COMMA_APOSTROPHE;
	result += this->command;
	result += APOSTROPHE_COMMA_APOSTROPHE;
	result += this->description;
	result += APOSTROPHE_RIGHT_SQUARE_BRACKET;
	return result;
}

int CMenuCommand::saveFromString(std::string tree, int startIndex){
	int length = tree.length();
	int currentIndex = startIndex;
	std::string name;
	std::string command;
	std::string description;
	if (tree.at(currentIndex) == CHAR_LEFT_SQUARE_BRACKET) {
		currentIndex++;
		if (tree.at(currentIndex) == CHAR_APOSTROPHE) {
			currentIndex++;
			startIndex = currentIndex;
			while (currentIndex < length && tree.at(currentIndex) != CHAR_APOSTROPHE) {
				currentIndex++;
			}
			name = tree.substr(startIndex, currentIndex - startIndex);
			currentIndex++;
			if (tree.at(currentIndex) == CHAR_COMMA) {
				currentIndex++;
				if (tree.at(currentIndex) == CHAR_APOSTROPHE) {
					currentIndex++;
					startIndex = currentIndex;
					while (currentIndex < length && tree.at(currentIndex) != CHAR_APOSTROPHE) {
						currentIndex++;
					}
					command = tree.substr(startIndex, currentIndex - startIndex);
					currentIndex++;
					if (tree.at(currentIndex) == CHAR_COMMA) {
						currentIndex++;
						if (tree.at(currentIndex) == CHAR_APOSTROPHE) {
							currentIndex++;
							startIndex = currentIndex;
							while (currentIndex < length && tree.at(currentIndex) != CHAR_APOSTROPHE) {
								currentIndex++;
							}
							description = tree.substr(startIndex, currentIndex - startIndex);
							currentIndex++;
							if (tree.at(currentIndex == CHAR_RIGHT_SQUARE_BRACKET)) {
								this->setName(name);
								this->setCommandName(command);
								this->setDescription(description);
								return currentIndex + 1;
							}
							else {
								char actualChar = tree.at(currentIndex);
								printParseError(CHAR_RIGHT_SQUARE_BRACKET, actualChar, currentIndex);
							}
						}
						else {
							char actualChar = tree.at(currentIndex);
							printParseError(CHAR_APOSTROPHE, actualChar, currentIndex);
						}				
					}
					else {
						char actualChar = tree.at(currentIndex);
						printParseError(CHAR_COMMA, actualChar, currentIndex);
					}
				}
				else {
					char actualChar = tree.at(currentIndex);
					printParseError(CHAR_APOSTROPHE, actualChar, currentIndex);
				}
			}
			else {
				char actualChar = tree.at(currentIndex);
				printParseError(CHAR_COMMA, actualChar, currentIndex);
			}
		}
		else {
			char actualChar = tree.at(currentIndex);
			printParseError(CHAR_APOSTROPHE, actualChar, currentIndex);
		}
	}
	else {
		char actualChar = tree.at(currentIndex);
		printParseError(CHAR_LEFT_SQUARE_BRACKET, actualChar, currentIndex);	
	}
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
	



