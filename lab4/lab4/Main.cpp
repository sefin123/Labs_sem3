#include "List.h"
#include "Monoblock.h"

int main() {
    List<Monoblock> list;

    int menuValue = MAGICNUMBER;
    while (menuValue != EXIT) {
        list.printList();
        std::cout << "Size of list:" << list.getSize() << std::endl;
        menuShow();

        menuValue = enterWithValidationForScope(MAXMENUVALUE);
        system("cls");
        if (menuValue == 1) {
            std::cout << "Push front" << std::endl;
            Monoblock value;
            value.setMonoblockParametrs();
            list.pushFront(value); 
            list.writeListToFile();
        }
        if (menuValue == 2) {
            std::cout << "Push back" << std::endl;
            Monoblock value;
            value.setMonoblockParametrs();
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
                int index;
                std::cout << "Enter index" << std::endl;
                std::cin >> index;
                Monoblock number;
                number = list.peek(index);
                number.printMonoblock();
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