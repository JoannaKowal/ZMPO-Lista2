#include "ValueTableCommand.h"

ValueTableCommand::ValueTableCommand(CTableManager * manager): CTableCommand(manager){
}

void ValueTableCommand::runCommand(){
	std::cout << ENTER_OFFSET_IN_VECTOR;
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		std::cout << ENTER_OFFSET_IN_TABLE;
		std::getline(std::cin, input);
		if (isNumber(input) && !overflowsInt(input)) {
			int position = std::atoi(input.c_str());
			std::cout << ENTER_VALUE;
			std::getline(std::cin, input);
			if (isNumber(input) && !overflowsInt(input)) {
				int value = std::atoi(input.c_str());
				int error;
				manager->setValue(offset, position, value, &error);
				if (error == SUCCESS) {
					std::cout << PROMPT_DEFINED_VALUE_IN_TABLE_AT_OFFSET << offset << FULL_STOP << std::endl;
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
		else {
			std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_VAL + APOSTROPHE + FULL_STOP << std::endl;
		}
	}
	else {
		std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_VAL + APOSTROPHE + FULL_STOP << std::endl;
	}
}
