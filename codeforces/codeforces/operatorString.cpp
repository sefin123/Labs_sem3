#include "operatorString.hpp"
MyString::MyString(const char* data)
{
    str = new char[strlen(data) + 1];
    strcpy(str, data);
}
MyString::MyString() {}
MyString::~MyString()
{
    delete[] str;
}

MyString::MyString(const MyString& other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

MyString& MyString::operator=(const MyString& other)
{
    char* newStr = new char[strlen(other.str) + 1];
    strcpy(newStr, other.str);
    delete[] str;
    str = newStr;

    return *this;
}

MyString MyString::operator+(const MyString& other) const
{
    char* newStr = new char[strlen(str) + strlen(other.str) + 1];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    MyString result(newStr);
    delete[] newStr;

    return result;
}

bool MyString::operator==(const MyString& other) const
{
    return strcmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other) const
{
    return strcmp(str, other.str) != 0;
}

MyString& MyString::operator+=(const MyString& other)
{
    char* newStr = new char[strlen(str) + strlen(other.str) + 1];
    strcpy(newStr, str);
    strcat(newStr, other.str);
    delete[] str;
    str = newStr;
    return *this;
}

char& MyString::operator[](const int index) const
{
    return str[index];
}

MyString MyString::operator()(int start, int end) const
{
    char* newStr = new char[(end - start) + 2];
    for (int i = start; i <= end; i++)
    {
        strncat(newStr, &str[i], 1);
    }
    MyString result(newStr);
    delete[] newStr;

    return result;
}

const char* MyString::getStr() const
{
    return this->str;
}


void menu()
{
    cout << "1.Operator =" << endl;
    cout << "2.Operator +" << endl;
    cout << "3.Operator +=" << endl;
    cout << "4.Operator ==" << endl;
    cout << "5.Operator !=" << endl;
    cout << "6.Operator []" << endl;
    cout << "7.Operator ()" << endl;
    cout << "0.Exit" << endl;
}
void validation(int* val, int max, int start) {
    while (true) {
        if (cin >> *val && *val >= 0 && *val <= max && *val >= start) {
            break;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer.\n";
        }
    }

}
