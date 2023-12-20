#include "Monoblock.h"
#include "List.h"

void menuShow() {
	std::cout << "1.Push front" << std::endl;
	std::cout << "2.Push back" << std::endl;
	std::cout << "3.Pop front" << std::endl;
	std::cout << "4.Pop back" << std::endl;
	std::cout << "5.Find data" << std::endl;
	std::cout << "6.Clear list" << std::endl;
	std::cout << "7.Read txt file" << std::endl;
	std::cout << "8.Read bin file" << std::endl;
	std::cout << "9.Exit" << std::endl;
	std::cout << "Choice:" << std::endl;
}

int enterWithValidationForScope(int scope) {
	while (true) {
		int a;
		if (std::cin >> a && a > 0 && a < scope) return a;
		else {
			std::cout << "Error, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
}