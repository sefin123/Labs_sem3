#include <iostream>
using namespace std;
#define MAXSTRINGSIZE 256

class Computer {
protected:
	char brand[MAXSTRINGSIZE];
	char modelName[MAXSTRINGSIZE];
public:
	Computer();

	~Computer();

	Computer(char* brandStr, char* modelnameStr);
};