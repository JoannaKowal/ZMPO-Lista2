#include "AddTableCommand.h"

AddTableCommand::AddTableCommand(CTableManager * manager): CTableCommand(manager){
	
}

void AddTableCommand::runCommand(){
	manager->addTable();
	std::cout << PROMPT_DEFINED_TABLE<< std::endl;
}
