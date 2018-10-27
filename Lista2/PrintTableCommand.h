#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class PrintTableCommand :public CTableCommand {
public:
	PrintTableCommand(CTableManager* manager);
	void runCommand();
};