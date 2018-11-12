#include "CMenuItem.h"

CMenuItem::~CMenuItem() {};

void CMenuItem::setParent(CMenuItem * parent){
	this->parent = parent;
}

std::string CMenuItem::getDescription(){
	return description;
}
