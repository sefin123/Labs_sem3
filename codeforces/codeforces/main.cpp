#include <iostream>
#include "operatorString.hpp"

int main()
{
    char* firstStr = new char[256];
    char* secondStr = new char[256];
    cout << "First String: ";
    cin.getline(firstStr, 256);
    cout << "Second String: ";
    cin.getline(secondStr, 256);

    MyString firstData(firstStr);
    MyString secondData(secondStr);

    delete[] firstStr;
    delete[] secondStr;

    menu();

    int choice;
    cout << "Choice: ";
    validation(&choice, 7, -1);

    switch (choice)
    {
    case 1:
    {
        secondData = firstData;
        cout << "Second Data: " << secondData.getStr() << endl;
        break;

    }
    case 2:
    {
        MyString newData = firstData + secondData;
        cout << "New Data: " << newData.getStr() << endl;
        break;
    }
    case 3:
    {
        firstData += secondData;
        cout << firstData.getStr() << endl;
        break;
    }
    case 4:
    {
        if (firstData == secondData)
            cout << "True" << endl;
        else
            cout << "False" << endl;
        break;
    }
    case 5:
    {
        if (firstData != secondData)
            cout << "True" << endl;
        else
            cout << "False" << endl;
        break;
    }
    case 6:
    {
        int i, j;
        cout << "Enter index of symbol First String: ";
        validation(&i, (int)strlen(firstData.getStr()) - 1, -1);
        cout << firstData[i] << endl;
        cout << "Enter index of symbol Second String: ";
        validation(&j, (int)strlen(secondData.getStr()) - 1, -1);
        cout << secondData[j] << endl;
        break;
    }
    case 7:
    {
        int start, end;
        cout << "Start index of 1 string: ";
        validation(&start, (int)strlen(firstData.getStr()) - 1, -1);
        cout << "End index of 1 string: ";
        validation(&end, (int)strlen(firstData.getStr()) - 1, start);
        cout << "First String: " << firstData(start, end).getStr() << endl;
        break;
    }

    };

    return 0;
}

