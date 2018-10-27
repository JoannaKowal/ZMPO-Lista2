#include "DelallTableCommand.h"

DelallTableCommand::DelallTableCommand(CTableManager * manager): CTableCommand(manager){
	
}

void DelallTableCommand::runCommand(){
	manager->deleteAll();
	std::cout << "Usunieto" << std::endl;
}
