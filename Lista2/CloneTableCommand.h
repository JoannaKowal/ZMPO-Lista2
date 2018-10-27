#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class CloneTableCommand :public CTableCommand {
public:
	CloneTableCommand(CTableManager* manager);
	void runCommand();
};
