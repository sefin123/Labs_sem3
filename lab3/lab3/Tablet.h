#include "Portable.h"

class Tablet : public Portable {
	char modem[MAXSTRINGSIZE];
public:
	Tablet();

	~Tablet();

	Tablet(char* modemStr, int batteryCharge, double screenDiagonal, char* brandStr, char* modelnameStr);

	Tablet(const Tablet& other);

	void printTablet();

	void setModem(const char* newModem);

	char* getModem();
};