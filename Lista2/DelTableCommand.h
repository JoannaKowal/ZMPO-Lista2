#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class DelTableCommand: public CTableCommand {
public:
	DelTableCommand(CTableManager* manager);
	void runCommand();
};

