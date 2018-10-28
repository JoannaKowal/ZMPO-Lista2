#include "DelallTableCommand.h"

DelallTableCommand::DelallTableCommand(CTableManager * manager): CTableCommand(manager){
	
}

void DelallTableCommand::runCommand(){
	manager->deleteAll();
	std::cout << PROMPT_DELETED_ALL_TABLES << std::endl;
}
