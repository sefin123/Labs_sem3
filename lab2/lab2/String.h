#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define MAXINDEXMENU 9
#define MAGICNUMBER 99
#define MAXSTRINGSIZE 256

void menu();

class String {
	char* str;
	int size;
public:

	String();

	String(const char* initStr);

	void printStr();

	~String();

	const String& operator = (const String& other);

	const String operator + (const String& other);

	const String& operator += (const String& other);

	bool operator == (const String& other);

	bool operator != (const String& other);

	char operator [] (int index);

	const String operator () (int a, int b);
};