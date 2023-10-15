#include "Laptop.h"

Laptop::Laptop() {
	this->numberOfKeys = 0;
}

Laptop::~Laptop() {}

Laptop::Laptop(int numberOfKeys) {
	this->numberOfKeys = numberOfKeys;
}