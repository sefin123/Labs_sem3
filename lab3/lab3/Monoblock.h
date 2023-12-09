#include "Desktop.h"

class Monoblock : public Desktop {
	double screenDiagonal;
public:
	Monoblock();
	
	~Monoblock();

	Monoblock(double screenDiagonalValue, char* bodyStr, char* brand, char* modelName);

	Monoblock(const Monoblock& other);

	void printMonoblock();

	void setScreenDiagonal(double newScreenDiagonal);

	double getScreenDiagonal();

	const Monoblock& operator = (const Monoblock& other);
};