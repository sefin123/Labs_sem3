#include "List.h"
#include "Monoblock.h"

int main() {
    List<int> list;
    
    int menuValue = MAGICNUMBER;
    while (menuValue != EXIT) {

        for (auto& element : list) {
            std::cout << element << std::endl;
        }

        menuShow();

        menuValue = enterWithValidationForScope(MAXMENUVALUE);
        system("cls");
        if (menuValue == 1) {
            std::cout << "Push front" << std::endl;
            int value;
            std::cout << "Enter value:" << std::endl;
            std::cin >> value;
            list.pushFront(value); 
            list.writeListToFile();
        }
        if (menuValue == 2) {
            std::cout << "Push back" << std::endl;
            int value;
            std::cout << "Enter value:" << std::endl;
            std::cin >> value;
            list.pushBack(value);
            list.writeListToFile();
        }
        if (menuValue == 3) {
            std::cout << "Pop front" << std::endl;
            list.popFront();
        }
        if (menuValue == 4) {
            std::cout << "Pop back" << std::endl;
            list.popBack();
        }
        try {
            if (menuValue == 5) {
                std::cout << "Enter number" << std::endl;
                int number;
                bool isFound;
                std::cin >> number;
                List<int>::iter start = list.begin();
                List<int>::iter end = list.end();
                try {
                    if (isFound = list.search(start, end, number)) {
                        std::cout << "Found" << std::endl;
                    }
                    else {
                        std::cout << "Not found" << std::endl;
                    }
                }
                catch (...) {
                    std::cout << "something gone wrong." << std::endl;
                }
            }
        }
        catch (std::exception& problem) {
            std::string msg;
            msg = problem.what();
            std::cout << msg;
        }

        if (menuValue == 6) {
            list.clearList();
        }

        if (menuValue == 7) {
            list.readFromTXTFileToList();
        }

        if (menuValue == 8) {
            list.readFromBinaryFileToList();
        }
    }

    return 0;
}