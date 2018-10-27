#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class LengthTableCommand: public CTableCommand {
public:
	LengthTableCommand(CTableManager* manager);
	void runCommand();
};
