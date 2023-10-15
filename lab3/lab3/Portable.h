#include "Computer.h"

class Portable : public Computer {
protected:
	int batteryCharge;
	double screenDiagonal;
public:
	Portable();
	
	~Portable();

	Portable(int batteryChargeValue, double screenDiagonalValue);
};