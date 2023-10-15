#include "Computer.h"

Computer::Computer() {}

Computer::~Computer() {}

Computer::Computer(char* brandStr, char* modelnameStr) {
	strncpy(this->brand, brandStr, MAXSTRINGSIZE - 1);
	this->brand[MAXSTRINGSIZE - 1] = '\0';
	strncpy(this->modelName, modelnameStr, MAXSTRINGSIZE - 1);
	this->modelName[MAXSTRINGSIZE - 1] = '\0';
}
