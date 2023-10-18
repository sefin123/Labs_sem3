#include "Desktop.h"


Desktop::Desktop() {
	this->body[0] = {NULL};
}

Desktop::~Desktop() {}

Desktop::Desktop(char* bodyStr, char* brand, char* modelName) : Computer(brand, modelName) {
	for (int i = 0; i < strlen(bodyStr); i++) {
		this->body[i] = bodyStr[i];
	}
	this->body[strlen(bodyStr)] = '\0';
}

Desktop::Desktop(const Desktop& other) : Computer(other) {
	for (int i = 0; i < strlen(other.body); i++) {
		body[i] = other.body[i];
	}
	body[strlen(other.body)] = '\0';
}

void Desktop::setBody(const char* newBody) {
	for (int i = 0; i < strlen(newBody); i++) {
		this->body[i] = newBody[i];
	}
	this->body[strlen(newBody)] = '\0';
}

char* Desktop::getBody() {
	return this->body;
}
