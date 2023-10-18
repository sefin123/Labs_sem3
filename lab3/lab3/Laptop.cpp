#include "Laptop.h"


Laptop::Laptop() {
	this->numberOfKeys = 0;
}

Laptop::~Laptop() {}

Laptop::Laptop(int numberOfKeys, int batteryCharge, double screenDiagonal, char* brand, char* modelName) : Portable(batteryCharge, screenDiagonal, brand, modelName) {
	this->numberOfKeys = numberOfKeys;
}

Laptop::Laptop(const Laptop& other) : Portable(other) {
	numberOfKeys = other.numberOfKeys;
}

void Laptop::printLaptop() {
	cout << "Number of keys: ";
	cout << this->numberOfKeys << endl;
	cout << "Screen diagonal: ";
	cout << this->screenDiagonal << endl;
	cout << "Battery charge: ";
	cout << this->batteryCharge << endl;
	cout << "Maodel name: ";
	cout << this->modelName << endl;
	cout << "Brand:	";
	cout << this->brand << endl;
}

void Laptop::setNumberOfKeys(int newNumberOfKeys) {
	this->numberOfKeys = newNumberOfKeys;
}

int Laptop::setNumberOfKeys() {
	return this->numberOfKeys;
}