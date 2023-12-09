#include "Desktop.h"

class Monoblock : public Desktop {
	double screenDiagonal;
public:
	Monoblock();

	~Monoblock();

	Monoblock(double screenDiagonalValue, char* bodyStr, char* brand, char* modelName);

	Monoblock(const Monoblock& other);

	void printMonoblock();

	void setMonoblockParametrs();

	void setScreenDiagonal(double newScreenDiagonal);

	double getScreenDiagonal();

	friend std::ofstream& operator << (std::ofstream& a, Monoblock& obj);

	friend std::ifstream& operator >> (std::ifstream& a, Monoblock& obj);
};