#include "List.h"


void menuShow() {
	std::cout << "1.Push front" << endl;
	std::cout << "2.Push back" << endl;
	std::cout << "3.Pop front" << endl;
	std::cout << "4.Pop back" << endl;
	std::cout << "5.Peek" << endl;
	std::cout << "6.Clear list" << endl;
	std::cout << "7.Exit" << endl;
	std::cout << "Choice:" << endl;
}

int valueForMethod() {
	cout << "Enter value:" << endl;
	int value;
	cin >> value;
	return value;
}

int enterWithValidationForScope(int scope) {
	while (true) {
		int a;
		if (cin >> a && a > 0 && a < scope) return a;
		else {
			cout << "Error, try again" << endl;
			cin.clear();
			cin.ignore();
		}
	}
}