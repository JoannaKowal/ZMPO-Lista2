#include "PrintCommand.h"

PrintCommand::PrintCommand(std::string text){
	this->myText = text;
}

void PrintCommand::runCommand(){
	std::cout << myText << std::endl;
}
