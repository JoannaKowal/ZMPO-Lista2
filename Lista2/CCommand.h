#pragma once
#include <iostream>
#include <string>
const std::string DEFAULT_TEXT = "Komenda domy�lna";

class CCommand {
public:
	virtual ~CCommand();
	virtual void runCommand();
};
