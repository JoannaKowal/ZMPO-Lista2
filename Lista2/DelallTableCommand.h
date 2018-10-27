#pragma once
#include "CTableManager.h"
#include "CTableCommand.h"
class DelallTableCommand : public CTableCommand {
public:
	DelallTableCommand(CTableManager* manager);
	void runCommand();
};
