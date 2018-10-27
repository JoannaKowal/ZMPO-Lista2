#pragma once
#include "CTableManager.h"
#include "CTableCommand.h"
class AddTableCommand: public CTableCommand {
public:
	AddTableCommand(CTableManager* manager);
	void runCommand();
};
