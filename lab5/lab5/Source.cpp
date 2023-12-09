#include "Exp.h"

void stringCopy(char* str1, char* str2) {
	for (int i = 0; i < strlen(str2); i++) {
		str1[i] = str2[i];
	}
	str1[strlen(str2)] = '\0';
}

void checkName(char* name) {
	if (strlen(name) > MAXSTRINGSIZE) {
		throw ExpInput("Invalid name format", 1);
	}
	for (int i = 0; name[i] != '\0'; i++) {
		if (!isalpha(name[i]) && !isspace(name[i])) {
			throw ExpInput("Invalid name format", 1);
		}
	}
}
//0123456789
//12.11.1999
void checkBirthDate(char* birthDate) {
	if (birthDate[2] != '.' || birthDate[5] != '.' || strlen(birthDate) != MAXBIRTHDATESIZE - 1) {
		throw ExpInput("Invalid date format", 2);
	}
	for (int i = 0; i < strlen(birthDate); i++) {
		if (isalpha(birthDate[i]) && isspace(birthDate[i])) {
			throw ExpInput("Invalid date format", 2);
		}
    }
}

void checkCardNumber(char* cardNumber) {
	if (strlen(cardNumber) != MAXCARDNUMBERSIZE - 1) {
		throw ExpInput("Invalid card number format", 3);
	}
	for (int i = 0; i < strlen(cardNumber); i++) {
		if (!isdigit(cardNumber[i])) {
			throw ExpInput("Invalid card number format", 3);
		}
	}
}