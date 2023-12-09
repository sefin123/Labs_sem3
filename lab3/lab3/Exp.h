#pragma once
#include "Header.h"

class Exp {
protected:
	int code;
	char msg[MAXMESSAGESIZE];
public:
	Exp();

	Exp(const char* msg, int code);

	void show();

	~Exp();
};

class ExpInput : public Exp {
public:
	ExpInput(const char* msg, int code);
};