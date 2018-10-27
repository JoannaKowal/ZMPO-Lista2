#pragma once
#include <vector>
#include "CTable.h"

class CTableManager {
public:
	~CTableManager();
	void addTable();
	void setTableLength(int offset, int length, int* error);
	void deleteTable(int offset, int* error);
	void deleteAll();
	void setTableName(int offset, std::string name,int* error);
	void cloneTable(int offset, int* error);
	std::string printTable(int offset, int* error);
	void setValue(int offset, int pos, int val, int* error);
	void diff(int offset);
	void diffPointer(int* offset);
	

private:
	std::vector<CTable*> myCTables;
	bool offsetCorrect(int offset);
};