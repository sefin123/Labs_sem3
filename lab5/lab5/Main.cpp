#include "Exp.h"
#include "Person.h"

int main() {

	Person person;
	std::cout << "Enter name:" << std::endl;
	char name[MAXSTRINGSIZE];
	std::cin >> name;

	try {
		checkName(name);
		person.setName(name);
	}
	catch (ExpInput& problem) {
		problem.show();
	}

	std::cout << "Enter birth date" << std::endl;
	char birthDate[MAXBIRTHDATESIZE];
	std::cin >> birthDate;
	
	try {
		checkBirthDate(birthDate);
		person.setBirthDate(birthDate);
	}
	catch (ExpInput& problem) {
		problem.show();
	}

	std::cout << "Enter card number" << std::endl;
	char cardNumber[MAXCARDNUMBERSIZE];
	std::cin >> cardNumber;

	try {
		checkCardNumber(cardNumber);
		person.setCardNumber(cardNumber);
	}
	catch (ExpInput& problem) {
		problem.show();
	}

	return 0;
}