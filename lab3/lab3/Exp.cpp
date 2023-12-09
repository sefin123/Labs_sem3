#include "Exp.h"

Exp::Exp() {
	this->code = 0;
	this->msg[0] = '\0';
}
Exp::Exp(const char* msg, int code) {
	this->code = code;
	for (int i = 0; i < strlen(msg); i++) {
		this->msg[i] = msg[i];
	}
	this->msg[strlen(msg)] = '\0';
}

void Exp::show() {
	std::cout << "Code of exception: " << this->code << std::endl;
	std::cout << this->msg << std::endl;
}

Exp::~Exp() {}

ExpInput::ExpInput(const char* msg, int code) : Exp(msg, code) {}