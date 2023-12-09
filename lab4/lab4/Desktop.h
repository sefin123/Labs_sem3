#include "Computer.h"

class Desktop : public Computer {
protected:
	char body[MAXSTRINGSIZE];
public:
	Desktop();

	~Desktop();

	Desktop(char* bodyStr, char* brand, char* modelName);

	Desktop(const Desktop& other);

	void setBody(const char* newBody);

	char* getBody();

	friend std::ofstream& operator << (std::ofstream& a, Desktop& obj);

	friend std::ifstream& operator >> (std::ifstream& a, Desktop& obj);
};