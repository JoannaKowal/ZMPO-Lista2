#pragma once
#include <string>
const char MINUS = '-';
const std::string MAX_INT_STRING = std::to_string(INT_MAX);
const int MAX_INT_STRING_LENGTH = MAX_INT_STRING.size();

namespace numberUtils {
	bool isNumber(std::string& argument);
	bool overflowsInt(std::string& argument);
}
