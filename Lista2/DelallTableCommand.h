#pragma once
#include "CTableManager.h"
#include "CTableCommand.h"
#include "Constants.h"
class DelallTableCommand : public CTableCommand {
public:
	DelallTableCommand(CTableManager* manager);
	void runCommand();
};
