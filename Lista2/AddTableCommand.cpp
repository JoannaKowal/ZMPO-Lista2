#include "AddTableCommand.h"

AddTableCommand::AddTableCommand(CTableManager * manager): CTableCommand(manager){
	
}

void AddTableCommand::runCommand(){
	manager->addTable();
	std::cout << "Dodano" << std::endl;
}
