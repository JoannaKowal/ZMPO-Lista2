#include "PrintTableCommand.h"

PrintTableCommand::PrintTableCommand(CTableManager * manager): CTableCommand(manager){
}

void PrintTableCommand::runCommand(){
	std::cout << ENTER_OFFSET;
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		int error;
		std::string info = manager->printTable(offset, &error);
		if (error == SUCCESS) {
			std::cout << info << std::endl;
		}
		else {
			if (error == ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS) {
				std::cout << PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS << std::endl;
			}
		}
	}
	else {
		std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_VAL + APOSTROPHE + FULL_STOP << std::endl;
	}
}
