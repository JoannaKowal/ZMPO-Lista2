#include "LengthTableCommand.h"

LengthTableCommand::LengthTableCommand(CTableManager * manager): CTableCommand(manager){
}

void LengthTableCommand::runCommand(){
	std::cout << "Podaj offset: ";
	std::string input;
	std::getline(std::cin, input);
	if (isNumber(input) && !overflowsInt(input)) {
		int offset = std::atoi(input.c_str());
		std::cout << "Podaj dlugosc: ";
		std::getline(std::cin, input);
		if (isNumber(input) && !overflowsInt(input)) {
			int length = std::atoi(input.c_str());
			int error;
			manager->setTableLength(offset, length, &error);
			if (error == SUCCESS) {
				std::cout << PROMPT_DEFINED_LENGTH_IN_TABLE_AT_OFFSET << offset << FULL_STOP << std::endl;
			}
			else {
				if (error == ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS) {
					std::cout << PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS << std::endl;
				}
				else if (error == ERR_INCORRECT_LENGTH) {
					std::cout << PROMPT_ERROR_INVALID_LENGTH + FULL_STOP << std::endl;
				}
			}
		}
		else {
			std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_TAB_LEN + APOSTROPHE + FULL_STOP << std::endl;
		}	
	}
	else {
		std::cout << PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND + APOSTROPHE + COMMAND_TAB_LEN + APOSTROPHE + FULL_STOP << std::endl;
	}
}
