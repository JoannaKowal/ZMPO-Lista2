#pragma once
#include<string>

class CTable {

public:
	CTable();
	CTable(std::string newName, int tableLen);
	CTable(CTable& other);
	~CTable();
	void setName(std::string newName);
	void setValue(int val, int offset, int* errorCode);
	int getValue(int offset, int* error_code);
	CTable clone();
	void setLength(int length, int* errorCode);
	std::string toString();
	void clearAndCopyTable(CTable& other);
	void vDiff(CTable cTab);
	void vDiff(CTable* cTab);
	
private:
	int* table;
	int tableLength;
	std::string name;
	void copyTable(CTable& other);
};