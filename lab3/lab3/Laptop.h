#include "Portable.h"

class Laptop : public Portable {
	int numberOfKeys;
public:
	Laptop();

	~Laptop();

	Laptop(int numberOfKeys);
};