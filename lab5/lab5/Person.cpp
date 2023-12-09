#include "Person.h"

Person::Person() {
	this->name[0] = '\0';
	this->birthDate[0] = '\0';
	this->cardNumber[0] = '\0';
}

void Person::setName(char* NewName) {
	stringCopy(this->name, NewName);
}

void Person::setBirthDate(char* newBirthDate) {
	stringCopy(this->birthDate, newBirthDate);
}

void Person::setCardNumber(char* newCardNumber) {
	stringCopy(this->cardNumber, newCardNumber);
}

Person::~Person() {}