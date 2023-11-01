#pragma once
#include "Header.h"

class Computer {
protected:
	char brand[MAXSTRINGSIZE];
	char modelName[MAXSTRINGSIZE];
public:
	Computer();

	virtual ~Computer();

	Computer(char* brandStr, char* modelnameStr);

	Computer(const Computer& other);

	char* getBrand();

	char* getModelName();

	void setBrand(const char* newBrand);

	void setModelName(const char* newModelName);
};