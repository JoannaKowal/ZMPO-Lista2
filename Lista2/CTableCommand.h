#pragma once
#include "CCommand.h"
#include "CTableManager.h"
class CTableCommand : public CCommand {
public:
	CTableCommand(CTableManager* manager);
	virtual ~CTableCommand();
	virtual void runCommand() = 0;
protected:
	CTableManager * manager;
};
