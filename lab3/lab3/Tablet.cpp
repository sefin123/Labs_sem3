#include "Tablet.h"

Tablet::Tablet() {}

Tablet::~Tablet() {}

Tablet::Tablet(char* modemStr) {
	strncpy(this->modem, modemStr, MAXSTRINGSIZE - 1);
	this->modem[MAXSTRINGSIZE - 1] = '\0';
}