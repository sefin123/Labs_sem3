#include "Computer.h"

class Desktop : public Computer {
protected:
	char body[MAXSTRINGSIZE];
public:
	Desktop();

	~Desktop();

	Desktop(char* bodyStr);
};