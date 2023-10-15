#include "Portable.h"

Portable::Portable() {
	this->batteryCharge = 0;
	this->screenDiagonal = 0;
}

Portable::~Portable() {}

Portable::Portable(int batteryChargeValue, double screenDiagonalValue) {
	this->batteryCharge = batteryChargeValue;
	this->screenDiagonal = screenDiagonalValue;
}
