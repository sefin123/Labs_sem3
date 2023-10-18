#pragma once
#include "Computer.h"

class Portable : public Computer {
protected:
	int batteryCharge;
	double screenDiagonal;
public:
	Portable();
	
	~Portable();

	Portable(int batteryChargeValue, double screenDiagonalValue, char* brand, char* modelName);

	Portable(const Portable& other);

	void setbatteryCharge(int newBatteryCharge);

	void setScreenDiagonal(double newScreenDiagonal);

	double getScreenDiagonal();

	int getBatteryCharge();
};