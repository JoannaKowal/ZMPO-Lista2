#pragma once
#include <iostream>
#include <string>
const std::string DEFAULT_TEXT = "Komenda domyœlna";

class CCommand {
public:
	virtual ~CCommand();
	virtual void runCommand();
};
