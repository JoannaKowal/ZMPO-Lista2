#pragma once
#include "CTableCommand.h"
#include "NumberUtils.h"
#include "Constants.h"
using namespace numberUtils;
class RenameTableCommand : public CTableCommand {
public:
	RenameTableCommand(CTableManager* manager);
	void runCommand();
};
