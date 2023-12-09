#include "Computer.h"

Computer::Computer() {
	this->brand[0] = { NULL };
	this->modelName[0] = { NULL };
}

Computer::~Computer() {}

Computer::Computer(char* brandStr, char* modelnameStr) {
	for (int i = 0; i < strlen(brandStr); i++) {
		this->brand[i] = brandStr[i];
	}
	this->brand[strlen(brandStr)] = '\0';
	for (int i = 0; i < strlen(modelnameStr); i++) {
		this->modelName[i] = modelnameStr[i];
	}
	this->modelName[strlen(modelnameStr)] = '\0';
}

Computer::Computer(const Computer& other) {
	for (int i = 0; i < strlen(other.brand); i++) {
		brand[i] = other.brand[i];
	}
	brand[strlen(other.brand)] = '\0';
	for (int i = 0; i < strlen(other.modelName); i++) {
		modelName[i] = other.modelName[i];
	}
	modelName[strlen(other.modelName)] = '\0';
}

void Computer::setBrand(const char* newBrand) {
	for (int i = 0; i < strlen(newBrand); i++) {
		this->brand[i] = newBrand[i];
	}
	this->brand[strlen(newBrand)] = '\0';
}

char* Computer::getBrand() {
	return this->brand;
}

char* Computer::getModelName() {
	return this->modelName;
}

void Computer::setModelName(const char* newModelName) {
	for (int i = 0; i < strlen(newModelName); i++) {
		this->modelName[i] = newModelName[i];
	}
	this->modelName[strlen(newModelName)] = '\0';
}

std::ofstream& operator << (std::ofstream& a, Computer& obj) {
	a << obj.brand << std::endl << obj.modelName << std::endl;
	return a;
}

std::ifstream& operator >> (std::ifstream& a, Computer& obj) {
	a >> obj.brand >> obj.modelName;
	return a;
}
