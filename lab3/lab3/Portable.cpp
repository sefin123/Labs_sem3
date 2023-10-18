#include "Portable.h"


Portable::Portable() {
	this->batteryCharge = 0;
	this->screenDiagonal = 0;
}

Portable::~Portable() {}

Portable::Portable(int batteryChargeValue, double screenDiagonalValue, char* brand, char* modelName) : Computer(brand, modelName) {
	this->batteryCharge = batteryChargeValue;
	this->screenDiagonal = screenDiagonalValue;
}

Portable::Portable(const Portable& other) : Computer(other) {
	batteryCharge = other.batteryCharge;
	screenDiagonal = other.screenDiagonal;
}

void Portable::setbatteryCharge(int newbatteryCharge) {
	this->batteryCharge = newbatteryCharge;
}

void Portable::setScreenDiagonal(double newScreenDiagonal) {
	this->screenDiagonal = newScreenDiagonal;
}

double Portable::getScreenDiagonal() {
	return this->screenDiagonal;
}


int Portable::getBatteryCharge() {
	return this->batteryCharge;
}