#include "RenameTableCommand.h"

RenameTableCommand::RenameTableCommand(CTableManager * manager): CTableCommand(manager){
}

void RenameTableCommand::runCommand(){
	std::cout << ENTER_OFFSET;
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		std::cout << ENTER_NAME;
		std::getline(std::cin, input);
		std::string name = input;
		int error;
		manager->setTableName(offset,name, &error);
		if (error == SUCCESS) {
			std::cout << PROMPT_DEFINED_NAME_OF_TABLE_AT_OFFSET << offset << FULL_STOP << std::endl;
		}
		else {
			if (error == ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS) {
				std::cout << PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS << std::endl;
			}
		}
	}
	else {
		std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_RENAME + APOSTROPHE + FULL_STOP << std::endl;
	}
}
