#include "Desktop.h"

class Monoblock : public Desktop {
	double screenDiagonal;
public:
	Monoblock();
	
	~Monoblock();

	Monoblock(double screenDiagonalValue);
};