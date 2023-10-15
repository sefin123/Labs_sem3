#include "Matrix.h"
#include "String.h"

int main() {

    cout << "Enter size: ";
    int size = enterWithValidation();

    Matrix matrix(size);
    matrix.enter();
    cout << "----------------------" << endl;
    cout << "Enter size of second matrix" << endl;
    int sizeSecond = enterWithValidation();

    Matrix matrix2(sizeSecond);
    matrix2.enter();

    Matrix copy(matrix);
    cout << "Operator(=)" << endl;
    matrix2 = matrix;
    matrix2.printMatrix();
    cout << "Operator(&)" << endl;
    matrix2 & matrix;
    matrix2.printMatrix();

    char a[MAXSTRINGSIZE];
    char b[MAXSTRINGSIZE];
    cout << "enter 2 string:" << endl;
    cin >> a;
    cin >> b;
    String str1(a);
    String str2(b);
    String str3;
    int choice = MAGICNUMBER;
    while (choice != 8) {
        menu();
        cout << "String 1:" << endl;
        str1.printStr();
        cout << "String 2:" << endl;
        str2.printStr();
        cout << "choice: " << endl;
        choice = enterWithValidationForScope(MAXINDEXMENU);
        
        if(choice == 1) {
            cout << "Operator(=)" << endl;
            str1 = str2;
            str1.printStr();
        }
        if (choice == 2) {
            cout << "operator(+)" << endl;
            str3 = str1 + str2;
            str3.printStr();
        }
        if (choice == 3) {
            cout << "operator(+=)" << endl;
            str1 += str2;
            str1.printStr();    
        }
        if (choice == 4) {
            cout << "operator(==)" << endl;
            if (str1 == str2) {
                cout << "str1 == str2" << endl;
            }
            else {
                cout << "str1 != str2" << endl;
            }
        }
        if (choice == 5) {
            cout << "operator(!=)" << endl;
            if (str1 != str2) {
                cout << "str1 != str2" << endl;
            }
            else {
                cout << "str1 == str2" << endl;
            }
        }
        if (choice == 6) {
            cout << "Enter index:";
            int index = enterWithValidation();
            cout << "operator[]" << endl << str1[index] << endl;
        }
        if (choice == 7) {
            int start, end;
            cout << "Enter start and end:";
            start = enterWithValidation();
            end = enterWithValidation();
            cout << "operator()" << endl;
            str3 = str1(start, end);
            str3.printStr();
        }
    }
    return 0;
}