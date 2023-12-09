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

void Monoblock::setMonoblockParametrs() {
	double screenDiagonal;
	char body[MAXSTRINGSIZE];
	char modelName[MAXSTRINGSIZE];
	char brand[MAXSTRINGSIZE];

	std::cout << "Enter screen diagonal" << std::endl;
	std::cin >> screenDiagonal;
	std::cout << "Enter body" << std::endl;
	std::cin >> body;
	std::cout << "Enter model name" << std::endl;
	std::cin >> modelName;
	std::cout << "Enter brand" << std::endl;
	std::cin >> brand;

	this->setBody(body);
	this->setModelName(modelName);
	this->setBrand(brand);
	this->setScreenDiagonal(screenDiagonal);
}

void Monoblock::printMonoblock() {
	std::cout << "screen diagonal: ";
	std::cout << this->screenDiagonal << std::endl;
	std::cout << "Body: ";
	std::cout << this->body << std::endl;
	std::cout << "Maodel name: ";
	std::cout << this->modelName << std::endl;
	std::cout << "Brand:	";
	std::cout << this->brand << std::endl;
}

void Monoblock::setScreenDiagonal(double newScreenDiagonal) {
	this->screenDiagonal = newScreenDiagonal;
}

double Monoblock::getScreenDiagonal() {
	return this->screenDiagonal;
}

std::ofstream& operator << (std::ofstream& a, Monoblock& obj) {
	a << dynamic_cast<Desktop&>(obj) << obj.screenDiagonal << std::endl;
	return a;
}

std::ifstream& operator >> (std::ifstream& a, Monoblock& obj) {
	a >> dynamic_cast<Desktop&>(obj) >> obj.screenDiagonal;
	return a;
}