#include "Header.h"

int enterWithValidation() {
    while (true) {
        int a;
        if (cin >> a && a > 0 && a != 1) return a;
        else {
            cout << "Error, try again" << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

int enterMatrixWithValidation() {
    while (true) {
        int a;
        if (cin >> a) return a;
        else {
            cout << "Error, try again" << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

Matrix::Matrix(int sizeOfMatrix) {
    size = sizeOfMatrix;
    mas = new int* [size];
    for (int i = 0; i < size; i++) {
        mas[i] = new int[size];
    }
}

 int Matrix::getSize() {
    return size;
}

Matrix::Matrix(const Matrix& other) {
    size = other.size;
    mas = new int* [size];
    for (int i = 0; i < size; i++) {
        mas[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mas[i][j] = other.mas[i][j];
        }
    }
}

void Matrix::enter() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mas[i][j] = enterMatrixWithValidation();
        }
    }
}

int Matrix::minElement() {
    int minElem = mas[1][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i > j && mas[i][j] < minElem) {
                minElem = mas[i][j];
            }
        }
    }
    return minElem;
}

int Matrix::maxElement() {
    int maxElem = mas[0][1];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i<j && mas[i][j] > maxElem) {
                maxElem = mas[i][j];
            }
        }
    }
    return maxElem;
}

void Matrix::printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++) {
        delete[] mas[i];
    }
    delete[] mas;
}