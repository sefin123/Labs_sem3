#include "List.h"

int main() {
    List<int> list;

    int menuValue = MAGICNUMBER;
    while (menuValue != EXIT) {
        list.printList();
        std::cout << "Size of list:" << list.getSize() << endl;
        menuShow();

        menuValue = enterWithValidationForScope(MAXMENUVALUE);
        system("cls");
        if (menuValue == 1) {
            std::cout << "Push front" << endl;
            int value = valueForMethod();
            list.pushFront(value);
        }
        if (menuValue == 2) {
            std::cout << "Push back" << endl;
            int value = valueForMethod();
            list.pushBack(value);
        }
        if (menuValue == 3) {
            std::cout << "Pop front" << endl;
            list.popFront();
        }
        if (menuValue == 4) {
            std::cout << "Pop back" << endl;
            list.popBack();
        }
        try {
            if (menuValue == 5) {
                int index;
                std::cout << "Enter index" << endl;
                cin >> index;
                int number;
                number = list.peek(index);
                std::cout << number << endl;
            }
        }
        catch (out_of_range problem) {
            std::cout << problem.what();
        }

        if (menuValue == 6)
            list.clearList();
    }

    return 0;
}