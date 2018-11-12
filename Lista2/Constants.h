#pragma once
#include <string>

const int DEFAULT_LENGTH = 10;

//error codes
const int SUCCESS = 0;
const int ERR_TABLE_INDEX_OUT_OF_BOUNDS = 10;
const int ERR_INCORRECT_LENGTH = 20;
const int ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS = 30;
const int ERR_DUPLICATE_NAME = 1;
const int ERR_DUPLICATE_COMMAND = 2;


//0 arguments
const std::string COMMAND_TAB_LEN = "len";
const std::string COMMAND_DELALL = "delall";
const std::string COMMAND_EXIT = "exit";

//1 argument
const std::string COMMAND_DEL = "del";
const std::string COMMAND_PRINT = "print";
const std::string COMMAND_CLONE = "clone";
const std::string COMMAND_DIFF = "diff";
const std::string COMMAND_DIFF_POINTER = "diff2";

//2 arguments
const std::string COMMAND_RENAME = "rename";

//3+ arguments
const std::string COMMAND_ADD = "add";
const std::string COMMAND_VAL = "val";

//SUCCESS PROMPTS
const std::string PROMPT_DELETED_ALL_TABLES = "Deleted all tables.";
const std::string PROMPT_DEFINED_TABLE = "Defined new table.";
const std::string PROMPT_DELETED_TABLE_AT_OFFSET = "Successfully deleted table at offset: ";
const std::string PROMPT_DEFINED_VALUE_IN_TABLE_AT_OFFSET = "Successfully defined value in table at offset: ";
const std::string PROMPT_EXIT = "Program finished by user. Press any key to exit.";
const std::string PROMPT_DEFINED_LENGTH_IN_TABLE_AT_OFFSET = "Successfully defined length in table at offset: ";
const std::string PROMPT_CREATED_CLONE = "Successfully created a clone of table at offset: ";
const std::string PROMPT_DEFINED_NAME_OF_TABLE_AT_OFFSET = "Successfully defined name of table at offset: ";
const std::string AVAILABLE_COMMANDS = "Available commands: ";

//error messages
const std::string PROMPT_ERROR_INVALID_COMMAND = " is not recognized as an internal command.";
const std::string PROMPT_ERROR_INVALID_ARGUMENTS_NUMBER_FOR_COMMAND = "Invalid number of arguments for command ";
const std::string PROMPT_ERROR_INVALID_ARGUMENTS_FOR_COMMAND = "Invalid arguments for command ";
const std::string PROMPT_ERROR_INVALID_LENGTH = "Invalid length.";
const std::string PROMPT_ERROR_TABLE_OFFSET_OUT_OF_BOUNDS = "Table offset out of bounds.";
const std::string PROMPT_ERROR_INCORRECT_ARGUMENT = "Incorrect argument.";
const std::string PROMPT_ERROR_WRONG_NUMBER_OF_ARGUMENTS = "Wrong number of arguments.";

//utility strings
const std::string COMMAND_PROMPT = "$";
const std::string APOSTROPHE = "'";
const std::string EMPTY_STRING = "";
const std::string FULL_STOP = ".";
const std::string DEFAULT_NAME = "table";
const std::string DEFAULT_CONSTRUCTOR = "bezp: ";
const std::string PARAM_CONSTRUCTOR = "parametr: ";
const std::string COPY = "_copy";
const std::string COPY_CONSTRUCTOR = "kopiuj: ";
const std::string DESTRUCTOR = "usuwam: ";
const std::string LENGTH = "len: ";
const std::string VALUES = "values: ";
const std::string COMMA = ", ";
const std::string LEFT_BRACKET = "(";
const std::string RIGHT_BRACKET = ")";
const std::string SPACE = " ";
const std::string PARAM_OFFSET = "[offset]";
const std::string PARAM_LEN = "[length]";
const std::string PARAM_NAME = "[name]";
const std::string PARAM_VAL = "[value]";
const std::string ENTER_OFFSET = "Offset: ";
const std::string ENTER_LENGTH = "Length: ";
const std::string ENTER_NAME = "Name: ";
const std::string ENTER_OFFSET_IN_VECTOR = "Offset in vector: ";
const std::string ENTER_OFFSET_IN_TABLE = "Offset in table: ";
const std::string ENTER_VALUE = "Value: ";