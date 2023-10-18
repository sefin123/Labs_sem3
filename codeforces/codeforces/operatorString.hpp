#include <iostream>
using namespace std;
class MyString
{
    char* str;
public:
    MyString(const char* str);
    MyString();
    ~MyString();
    MyString(const MyString& other);
    MyString operator+(const MyString& other) const;
    bool operator==(const MyString& other) const;
    bool operator!=(const MyString& other) const;
    MyString& operator+=(const MyString& other);
    MyString& operator=(const MyString& other);
    char& operator[](const int index) const;
    MyString operator()(int start, int end) const;
    const char* getStr() const;
};
void menu();
void validation(int* val, int max, int start);
