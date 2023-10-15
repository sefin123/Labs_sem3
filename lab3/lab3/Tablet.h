#include "Portable.h"

class Tablet : public Portable {
	char modem[MAXSTRINGSIZE];
public:
	Tablet();

	~Tablet();

	Tablet(char* modemStr);
};