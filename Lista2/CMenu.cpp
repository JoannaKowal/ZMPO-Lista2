#include "CMenu.h"

void CMenu::run() {
	std::string userInput;
	bool finished = false;
	while (!finished) {
		printNameAndCommand();
		printNames();
		std::getline(std::cin, userInput);
		if (userInput == BACK) {
			finished = true;
		}
		else {
			std::vector<std::string> args;
			splitCommand(userInput, args);
			if (args[0] == COMMAND_SEARCH) {
				if (args.size() == 2) {
					this->search(args[1]);
				}
				else {
					std::cout << PROMPT_ERROR_WRONG_NUMBER_OF_ARGUMENTS << std::endl;
				}
			}
			else if (args[0] == COMMAND_HELP) {
				if (args.size() == 2) {
					bool found = false;
					for (int i = 0; i < myCommands.size() && !found; i++) {
						if (myCommands[i]->getCommand() == args[1]) {
							myCommands[i]->printDescription();
							found = true;
						}
					}
					if (!found) {
						std::cout << PROMPT_ERROR_INCORRECT_COMMAND << std::endl;
					}
				}
				else {
					std::cout << PROMPT_ERROR_WRONG_NUMBER_OF_ARGUMENTS << std::endl;
				}
			}
			else {
				int index = indexOfCommand(userInput);
				if (index == -1) {
					std::cout << PROMPT_ERROR_INCORRECT_COMMAND << std::endl;
				}
				else {
					myCommands[index]->run();
				}
			}
		}
		
	}	
}

CMenu::CMenu(){

	this->parent = nullptr;
}

CMenu::CMenu(std::string name, std::string command){
	this->name = name;
	this->command = command;
	this->parent = nullptr;

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
			menuItem->setParent(this);
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
		std::cout << i + 1 << FULL_STOP << myCommands[i]->toString() << std::endl;
	}
}

std::string CMenu::toString(){
	return name + SPACE + LEFT_BRACKET + command + RIGHT_BRACKET;
}

void CMenu::setParent(CMenuItem * parent){
	this->parent = parent;
}

void CMenu::search(std::string commandName){
	
	if (parent == nullptr) {
		find(commandName, std::string());
	}
	else {
		parent->search(commandName);
	}
}

std::string CMenu::save(){
	std::string result;
	result += LEFT_BRACKET_APOSTROPHE;
	result += this->name;
	result += APOSTROPHE_COMMA_APOSTROPHE;
	result += this->command;
	result += APOSTROPHE_SEMICOLON;
	for (int i = 0; i < myCommands.size(); i++) {
		result += myCommands[i]->save();
		if (i != myCommands.size() - 1) {
			result += COMMA;
		}
	}
	result += RIGHT_BRACKET;
	return result;
}

int CMenu::readFromString(std::string tree, int startIndex){
	for (int i = 0; i < myCommands.size(); i++) {
		delete myCommands[i];
	}
	myCommands.clear();
	int length = tree.length();
	int currentIndex = startIndex;
	std::string name;
	std::string command;
	std::vector<CMenuItem*> children;

	if (tree.at(startIndex) == CHAR_LEFT_BRACKET) {
		startIndex++;
		if (tree.at(startIndex) == CHAR_APOSTROPHE) {
			startIndex++;
			currentIndex = startIndex;
			while (currentIndex < length && tree.at(currentIndex) != CHAR_APOSTROPHE) {
						currentIndex++;
			}
			name = tree.substr(startIndex, currentIndex - startIndex);
			currentIndex++;
			if (tree.at(currentIndex) == CHAR_COMMA) {
				currentIndex++;
				if(tree.at(currentIndex) == CHAR_APOSTROPHE){
					currentIndex++;
					startIndex = currentIndex;
					while (currentIndex < length && tree.at(currentIndex) != CHAR_APOSTROPHE) {
						currentIndex++;
					}
					command = tree.substr(startIndex, currentIndex - startIndex);
					currentIndex++;
					if (tree.at(currentIndex) == CHAR_SEMICOLON) {
						currentIndex++;
						CMenuItem* child = nullptr;
						while (tree.at(currentIndex) != CHAR_RIGHT_BRACKET) {
							int nextIndex;
							if (tree.at(currentIndex) == CHAR_LEFT_BRACKET) {
								child = new CMenu();
								nextIndex = child->readFromString(tree, currentIndex);
							}
							else if (tree.at(currentIndex) == CHAR_LEFT_SQUARE_BRACKET) {
								child = new CMenuCommand();
								nextIndex = child->readFromString(tree, currentIndex);
							}
							else {
								nextIndex = -1;
							}
							if (nextIndex < 0) {
								if (child != nullptr) {
									delete child;
								}
								for (int i = 0; i < children.size(); i++) {
									delete children[i];
								}
								return nextIndex;
							}
							else {
								currentIndex = nextIndex;
								children.push_back(child);
								child->setParent(this);
								if (tree.at(currentIndex) == CHAR_COMMA) {
									currentIndex++;
								}
							}
						}
						if (tree.at(currentIndex == CHAR_RIGHT_BRACKET)) {
							this->myCommands = children;
							this->setName(name);
							this->setCommandName(command);
							return currentIndex + 1;
						}
						else {
							char actualChar = tree.at(currentIndex);
							printParseError(CHAR_RIGHT_BRACKET, actualChar, currentIndex);
							return -1;
						}
					}
					else {
						char actualChar = tree.at(currentIndex);
						printParseError(CHAR_SEMICOLON, actualChar, currentIndex);
						return -1;
					}
				}
				else {
					char actualChar = tree.at(currentIndex);
					printParseError(CHAR_APOSTROPHE, actualChar, currentIndex);
					return -1;
				}
			}
			else {
				char actualChar = tree.at(currentIndex);
				printParseError(CHAR_COMMA, actualChar, currentIndex);
				return -1;
			}	
		}
		else {
			char actualChar = tree.at(startIndex);
			printParseError(CHAR_APOSTROPHE, actualChar, startIndex);
			return -1;
		}	
	}
	else {
		char actualChar = tree.at(startIndex);
		printParseError(CHAR_LEFT_BRACKET, actualChar, startIndex);
		return -1;
	}
	
	
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
void CMenu::find(std::string commandName, std::string path) {
	if (this->command == commandName) {
		std::cout << path + commandName << std::endl;
	}
	for (int i = 0; i < myCommands.size(); i++) {
		myCommands[i]->find(commandName, path + this->command + ARROW);
	}
}

void CMenu::splitCommand(std::string currentCommand, std::vector<std::string> &args){
	std::istringstream iss(currentCommand);
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(args));
}

void CMenu::printDescription(){
	std::cout << PROMPT_ERROR_INCORRECT_COMMAND << std::endl;
}



