#include "CloneTableCommand.h"

CloneTableCommand::CloneTableCommand(CTableManager * manager): CTableCommand(manager){
}

void CloneTableCommand::runCommand(){
	std::cout << "Podaj offset: ";
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		int error;
		manager->cloneTable(offset, &error);
		if (error == SUCCESS) {
			std::cout << PROMPT_CREATED_CLONE + input + FULL_STOP << std::endl;
		}
		else {
			if (error == ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS) {
				std::cout << PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS << std::endl;
			}
		}
	}
	else {
		std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_CLONE + APOSTROPHE + FULL_STOP << std::endl;
	}
}
