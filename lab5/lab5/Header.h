#pragma once
#include <iostream>
#define MAXMESSAGESIZE 80
#define MAXSTRINGSIZE 256
#define MAXBIRTHDATESIZE 11
#define MAXCARDNUMBERSIZE 17

void checkName(char* name); 

void stringCopy(char* str1, char* str2);

void checkBirthDate(char* date);

void checkCardNumber(char* cardNumber);
