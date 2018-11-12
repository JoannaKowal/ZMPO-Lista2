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
			if (args[0] == "search") {
				if (args.size() == 2) {
					this->search(args[1]);
				}
				else {
					std::cout << PROMPT_ERROR_WRONG_NUMBER_OF_ARGUMENTS << std::endl;
				}
			}
			else if (args[0] == "help") {
				if (args.size() == 2) {
					bool found = false;
					for (int i = 0; i < myCommands.size() && !found; i++) {
						if (myCommands[i]->getCommand() == args[1]) {
							myCommands[i]->printDescription();
							found = true;
						}
					}
					if (!found) {
						std::cout << "brak komendy" << std::endl;
					}
				}
				else {
					std::cout << PROMPT_ERROR_WRONG_NUMBER_OF_ARGUMENTS << std::endl;
				}
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
	result += "('";
	result += this->name;
	result += "','";
	result += this->command;
	result += "';";
	for (int i = 0; i < myCommands.size(); i++) {
		result += myCommands[i]->save();
		if (i != myCommands.size() - 1) {
			result += ",";
		}
	}
	result += ")";
	return result;
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
		myCommands[i]->find(commandName, path + this->command + "->");
	}
}

void CMenu::splitCommand(std::string currentCommand, std::vector<std::string> &args){
	std::istringstream iss(currentCommand);
	std::copy(std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>(),
		std::back_inserter(args));
}

void CMenu::printDescription(){
	std::cout << "brak komendy" << std::endl;
}



