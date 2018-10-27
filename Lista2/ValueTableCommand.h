#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class ValueTableCommand : public CTableCommand {
public:
	ValueTableCommand(CTableManager* manager);
	void runCommand();
};
