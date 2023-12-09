#include "Header.h"
#pragma once

class Person {
	char name[MAXSTRINGSIZE];
	char birthDate[MAXBIRTHDATESIZE];
	char cardNumber[MAXCARDNUMBERSIZE];

public:
	Person();

	void setName(char* name);

	void setBirthDate(char* birthDate);

	void setCardNumber(char* cardNumber);

	~Person();
};