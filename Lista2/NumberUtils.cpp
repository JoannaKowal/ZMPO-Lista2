#include "NumberUtils.h"

bool numberUtils::isNumber(std::string & argument){
	if (argument.at(0) == MINUS) {
		argument = argument.substr(1, argument.size() - 1);
	}
	std::string::const_iterator it = argument.begin();
	while (it != argument.end() && isdigit(*it)) {
		++it;
	}
	return !argument.empty() && it == argument.end();
}

bool numberUtils::overflowsInt(std::string & argument)
{
	if (argument.at(0) == MINUS) {
		argument = argument.substr(1, argument.size() - 1);
	}
	if (argument.size() < MAX_INT_STRING_LENGTH) {
		return false;
	}
	if (argument.size() > MAX_INT_STRING_LENGTH) {
		return true;
	}
	else {
		bool overflows = false;
		std::string::const_iterator it = argument.begin();
		std::string::const_iterator maxIntIt = MAX_INT_STRING.begin();
		while (it != argument.end() && !overflows) {
			if ((*maxIntIt) < (*it)) {
				overflows = true;
			}
			++it;
			++maxIntIt;
		}
		return overflows;
	}
}


	


