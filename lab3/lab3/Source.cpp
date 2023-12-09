#include "Exp.h"

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

void checkChar(char* string) {
    if (strlen(string) > MAXSTRINGSIZE) {
        throw Exp("Invalid Format", 3);
    }
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isspace(string[i])) {
            throw Exp("Invalid format", 3);
        }
    }
}

void checkDouble(double value) {
    if (value > 100000.0) {
        throw Exp("Invalid Format", 2);
    }
}

void checkInt(int value) {
    if (value > 100000) {
        throw Exp("Invalid format.", 1);
    }
}

void showMenu() {
    cout << "1.Monoblock" << endl;
    cout << "2.Laptop" << endl;
    cout << "3.Tablet" << endl;
    cout << "4.EXIT" << endl;
}