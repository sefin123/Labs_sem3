#include "Header.h"
#include <iostream>
#include <forward_list>

int main() {

	std::forward_list<int> list(3);

	int menuValue = MAGICNUMBER;
	while (menuValue != EXIT) {
		for (auto& element : list) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
		menuShow();
		std::cin >> menuValue;
		if (menuValue == 1) {
			std::cout << "Push" << std::endl;
			int value;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			list.push_front(value);
		}
		if (menuValue == 2) {
			std::cout << "Pop" << std::endl;
			list.pop_front();
		}
		if (menuValue == 3) {
			std::cout << "Resize" << std::endl;
			int value;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			list.resize(value);
		}
		if (menuValue == 4) {
			std::cout << "Assigh" << std::endl;
			int value , n;
			std::cout << "Enter n" << std::endl;
			std::cin >> n;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			list.assign(n, value);
		}
		if (menuValue == 5) {
			std::cout << "Emplace after" << std::endl;
			int value , position;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			std::cout << "Enter position" << std::endl;
			std::cin >> position;
			auto it = list.begin();
			std::advance(it, position);
			list.emplace_after(it, value);
		}
		if (menuValue == 6) {
			std::cout << "Clear list" << std::endl;
			list.clear();
		}
		if (menuValue == 7) {
			std::cout << "Find" << std::endl;
			int value;
			std::cout << "Enter value" << std::endl;
			std::cin >> value;
			auto start = list.begin();
			auto end = list.end();
			auto isFound = std::find(start, end, value);
			if (isFound == end) {
				std::cout << "Not found!" << std::endl;
			}
			else {
				std::cout << "Found: " << *isFound << std::endl;
			}
		}
	}
	return 0;
}