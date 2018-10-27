#include "CTableManager.h"
#include "Constants.h"

CTableManager::~CTableManager() {
	deleteAll();
}

void CTableManager::addTable() {
	myCTables.push_back(new CTable());
}

void CTableManager::setTableLength(int offset, int length, int* error) {
	if (offsetCorrect(offset)) {
		int errorCode;
		myCTables[offset]->setLength(length, &errorCode);
		*error = errorCode;
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
	}
}

void CTableManager::deleteTable(int offset, int* error) {
	if (offsetCorrect(offset)) {
		*error = SUCCESS;
		delete myCTables[offset];
		myCTables.erase(myCTables.begin() + offset);
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
	}
	
}

void CTableManager::deleteAll() {
	for (int i = 0; i < myCTables.size(); i++) {
		delete myCTables[i];
	}
	myCTables.clear();
}

void CTableManager::setTableName(int offset, std::string name, int* error) {
	if (offsetCorrect(offset)) {
		*error = SUCCESS;
		myCTables[offset]->setName(name);
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
	}
}

void CTableManager::cloneTable(int offset, int* error) {
	if (offsetCorrect(offset)) {
		*error = SUCCESS;
		myCTables.push_back(new CTable(*myCTables[offset]));
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
	}
}

std::string CTableManager::printTable(int offset, int* error){
	if (offsetCorrect(offset)) {
		*error = SUCCESS;
		return myCTables[offset]->toString();
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
		return "";
	}
}

void CTableManager::setValue(int offset, int pos, int val, int* error){
	if (offsetCorrect(offset)) {
		int errorCode;
		myCTables[offset]->setValue(val, pos, &errorCode);
		*error = errorCode;
	}
	else {
		*error = ERR_TABLE_MANAGER_INDEX_OUT_OF_BOUNDS;
	}
}

void CTableManager::diff(int offset){
	myCTables[offset]->vDiff(*myCTables[offset]);
}
void CTableManager::diffPointer(int* offset) {
	myCTables[*offset]->vDiff(myCTables[*offset]);
}

bool CTableManager::offsetCorrect(int offset) {
	return offset >= 0 && offset < myCTables.size();
}


