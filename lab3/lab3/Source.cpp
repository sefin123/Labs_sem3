#include "Header.h"

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

void showMenu() {
    cout << "1.Monoblock" << endl;
    cout << "2.Laptop" << endl;
    cout << "3.Tablet" << endl;
    cout << "4.EXIT" << endl;

}