#include "Monoblock.h"


Monoblock::Monoblock() {
	this->screenDiagonal = 0;
}

Monoblock::~Monoblock() {}

Monoblock::Monoblock(double screenDiagonalValue, char* body, char* brand, char* modelName) : Desktop(body, brand, modelName) {
	this->screenDiagonal = screenDiagonalValue;
}

Monoblock::Monoblock(const Monoblock& other) : Desktop(other) {
	screenDiagonal = other.screenDiagonal;
}

void Monoblock::printMonoblock() {
	cout << "screen diagonal: ";
	cout << this->screenDiagonal<< endl;
	cout << "Body: ";
	cout << this->body << endl;
	cout << "Maodel name: ";
	cout << this->modelName << endl;
	cout << "Brand:	";
	cout << this->brand << endl;
}

void Monoblock::setScreenDiagonal(double newScreenDiagonal) {
	this->screenDiagonal = newScreenDiagonal;
}

const Monoblock& Monoblock::operator =(const Monoblock& other) {
	strcpy_s(this->body, other.body);
	strcpy_s(this->brand, other.brand);
	strcpy_s(this->modelName, other.modelName);
	this->screenDiagonal = other.screenDiagonal;

	return *this;
}


double Monoblock::getScreenDiagonal() {
	return this->screenDiagonal;
}