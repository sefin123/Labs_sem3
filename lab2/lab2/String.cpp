#include "String.h"

void menu() {
	cout << "1.Operator(=)" << endl;
	cout << "2.operator(+)" << endl;
	cout << "3.operator(+=)" << endl;
	cout << "4.operator(==)" << endl;
	cout << "5.operator(!=)" << endl;
	cout << "6.operator[]" << endl;
	cout << "7.operator()" << endl;
	cout << "8.Exit" << endl;
}

String::String() {
	this->size = 0;
	this->str = nullptr;
}

String::String(const char* initStr) {
		this->size = strlen(initStr);
		
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++) {
			this->str[i] = initStr[i];
		}
		this->str[this->size] = '\0';
}

String::~String() {
		delete[] this->str;
}

void String::printStr() {
	cout << this->str << endl;
}

const String& String::operator = (const String& other) {
	delete[] this->str;
	
	this->size = other.size;

	this->str = new char[this->size + 1];

	for (int i = 0; i < this->size; i++) {
		this->str[i] = other.str[i];
	}
	this->str[this->size] = '\0';
	
	return *this;
}

const String String::operator + (const String& other) {
	
	String newStr;
	newStr.size = this->size + other.size;

	newStr.str = new char[newStr.size + 1];
	
	for (int i = 0; i < this->size; i++)
		newStr.str[i] = this->str[i];

	int i = this->size;
	int j = 0;
	while (i != other.size + this->size && j != other.size) {
		newStr.str[i] = other.str[j];
		i++;
		j++;
	}
	
	newStr.str[newStr.size] = '\0';

	return newStr;
}

const String& String::operator += (const String& other) {

	String newStr;

	newStr.size = this->size + other.size;

	newStr.str = new char[newStr.size + 1];
	
	for (int i = 0; i < this->size; i++)
		newStr.str[i] = this->str[i];

	int i = this->size;
	int j = 0;
	while (i != other.size + this->size && j != other.size) {
		newStr.str[i] = other.str[j];
		i++;
		j++;
	}
	newStr.str[this->size + other.size] = '\0';

	*this = newStr;
	return *this;

}

bool String::operator==(const String& other) {
	if (this->size != other.size)
		return false;

	for (int i = 0; i < this->size; i++) {
		if (this->str[i] != other.str[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator !=(const String& other) {
	return !(this->operator==(other));
}

char String::operator[](int index) {
	if (index > this->size || index < 0)
		return NULL;
	
	return this->str[index];
}

const String String::operator () (int start, int end) {
	String* newStr = new String();
	if (start >= this->size || end >= this->size || start < 0 || end < 0)
		return *this;

	if (end < start)
		swap(start, end);

	newStr->size = end - start + 1;
	newStr->str = new char[newStr->size + 1];
	int i = start;
	int j = 0;
	while (i <= end) {
		newStr->str[j] = this->str[i];
		i++;
		j++;
	}

	newStr->str[newStr->size] = '\0';

	return *newStr;
}