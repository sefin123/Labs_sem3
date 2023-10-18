#include "Tablet.h"


Tablet::Tablet() {
	this->modem[0] = { NULL };
}

Tablet::~Tablet() {}

Tablet::Tablet(char* modemStr, int batteryCharge, double screenDiagonal, char* brand, char* modelName) : Portable(batteryCharge, screenDiagonal, brand, modelName) {
	for (int i = 0; i < strlen(modemStr); i++) {
		this->modem[i] = modemStr[i];
	}
	this->modem[strlen(modemStr)] = '\0';
}

Tablet::Tablet(const Tablet &other) : Portable(other) {
	for (int i = 0; i < strlen(other.modem); i++) {
		modem[i] = other.modem[i];
	}
	modem[strlen(other.modem)] = '\0';
}

void Tablet::printTablet() {
	cout << "Modem: ";
	cout << this->modem << endl;
	cout << "Screen diagonal: ";
	cout << this->screenDiagonal << endl;
	cout << "Battery charge: ";
	cout << this->batteryCharge << endl;
	cout << "Maodel name: ";
	cout << this->modelName << endl;
	cout << "Brand:	";
	cout << this->brand << endl;
}

void Tablet::setModem(const char* newModem) {
	for (int i = 0; i < strlen(newModem); i++) {
		this->modem[i] = newModem[i];
	}
	this->modem[strlen(newModem)] = '\0';
}

char* Tablet::getModem() {
	return this->modem;
}
