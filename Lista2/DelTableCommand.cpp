#include "DelTableCommand.h"

DelTableCommand::DelTableCommand(CTableManager * manager): CTableCommand(manager){
}

void DelTableCommand::runCommand(){
	std::cout << ENTER_OFFSET;
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		int error;
		manager->deleteTable(offset, &error);
		if (error == SUCCESS) {
			std::cout<< PROMPT_DELETED_TABLE_AT_OFFSET + input + FULL_STOP << std::endl;
		}
		else {
			if (error == ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS) {
				std::cout<< PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS << std::endl;
			}
		}
	}
	else {
		std::cout << PROMPT_ERROR_INCORRECT_ARGUMENT << std::endl;
	}
}
