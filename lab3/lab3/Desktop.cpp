#include "Desktop.h"

Desktop::Desktop() {}

Desktop::~Desktop() {}

Desktop::Desktop(char* bodyStr) {
	strncpy(this->body, bodyStr, MAXSTRINGSIZE - 1);
	this->body[MAXSTRINGSIZE - 1] = '\0';
}