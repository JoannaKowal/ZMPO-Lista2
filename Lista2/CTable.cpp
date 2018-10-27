#include "CTable.h"
#include "Constants.h"
#include <iostream>

CTable::CTable() {
	setName(DEFAULT_NAME);
	std::cout << DEFAULT_CONSTRUCTOR << name << std::endl;
	table = new int[DEFAULT_LENGTH];
	tableLength = DEFAULT_LENGTH;
}

CTable::CTable(std::string newName, int tableLen) {
	setName(newName);
	std::cout << PARAM_CONSTRUCTOR << name << std::endl;
	table = new int[tableLen];
	tableLength = tableLen;
}
CTable::CTable(CTable& other) {
	setName(other.name + COPY);
	copyTable(other);
	std::cout << COPY_CONSTRUCTOR << name << std::endl;
}
CTable::~CTable() {
	delete table;
	std::cout << DESTRUCTOR<< name << std::endl;
}
void CTable::setName(std::string newName) {
	this->name = newName;
}
void CTable::setValue(int val, int offset, int* errorCode) {
	if (offset < tableLength && offset >= 0) {
		*errorCode = SUCCESS;
		table[offset] = val;
	}
	else {
		*errorCode = ERR_TABLE_INDEX_OUT_OF_BOUNDS;
	}
}
int CTable::getValue(int offset, int* errorCode) {
	if (offset < tableLength && offset >= 0) {
		*errorCode = SUCCESS;
		return table[offset];
	}
	else {
		*errorCode = ERR_TABLE_INDEX_OUT_OF_BOUNDS;
		return 0;
	}
}
CTable CTable::clone() {
	CTable table(*this);
	return table;
}
void CTable::setLength(int length, int* errorCode) {
	if (length > 0 && length != this->tableLength) {
		*errorCode = SUCCESS;
		int* newTable = new int[length];
		if (length > this->tableLength) {
			for (int i = 0; i < this->tableLength; i++) {
				newTable[i] = table[i];
			}
		}
		else if (length < this->tableLength) {
			for (int i = 0; i < length; i++) {
				newTable[i] = table[i];
			}
		}
		delete table;
		table = newTable;
		tableLength = length;
	}
	else {
		*errorCode = ERR_INCORRECT_LENGTH;
	}
}
std::string CTable::toString() {
	std::string info;
	std::string values = VALUES;
	std::string len = LENGTH + std::to_string(tableLength);
	for (int i = 0; i < tableLength; i++) {
		if (i == tableLength - 1) {
			values += std::to_string(table[i]) + RIGHT_BRACKET;
		}
		else {
			values += std::to_string(table[i]) + COMMA;
		}
	}
	info = LEFT_BRACKET + name + SPACE + len + SPACE + values;
	return info;
}
void CTable::clearAndCopyTable(CTable& other) {
	delete table;
	copyTable(other);
}

void CTable::copyTable(CTable& other) {
	tableLength = other.tableLength;
	table = new int[tableLength];
	for (int i = 0; i < other.tableLength; i++) {
		this->table[i] = other.table[i];
	}
}

void CTable::vDiff(CTable cTab) {
	int diff = 0;
	for (int i = 0; i < cTab.tableLength; i++) {
		diff -= cTab.table[i];
	}
	std::cout << diff << std::endl;
}

void CTable::vDiff(CTable* cTab){
	int diff = 0;
	for (int i = 0; i < cTab->tableLength; i++) {
		diff -= cTab->table[i];
	}
	std::cout << diff << std::endl;
}
