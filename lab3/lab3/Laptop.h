#include "Portable.h"

class Laptop : public Portable {
	int numberOfKeys;
public:
	Laptop();

	~Laptop();

	Laptop(int numberOfKeys, int batteryChargeValue, double screenDiagonalValue, char* brand, char* modelName);

	Laptop(const Laptop& other);

	void printLaptop();

	void setNumberOfKeys(int newNumberOfKeys);

	int setNumberOfKeys();
};