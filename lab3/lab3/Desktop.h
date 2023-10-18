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
};