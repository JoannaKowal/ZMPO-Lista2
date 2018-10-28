#pragma once
#include "CTableManager.h"
#include "CTableCommand.h"
#include "Constants.h"
class AddTableCommand: public CTableCommand {
public:
	AddTableCommand(CTableManager* manager);
	void runCommand();
};
