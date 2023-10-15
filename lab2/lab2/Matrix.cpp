#include "Matrix.h"

int enterWithValidation() {
    while (true) {
        int a;
        if (cin >> a && a > 0 ) return a;
        else {
            cout << "Error, try again" << endl;
            cin.clear();
            cin.ignore();
        }
    }
}

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

void Matrix::printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }
}

const Matrix& Matrix::operator = (const Matrix& other)  {
    for (int i = 0; i < size; i++) {
        delete[] mas[i];
    }
    delete[] mas;

    this->size = other.size;
    this->mas = new int* [this->size];
    for (int i = 0; i < this->size; i++)
        this->mas[i] = new int[this->size];

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->mas[i][j] = other.mas[i][j];
        }
    }
    return *this;
}

const Matrix& Matrix::operator&(const Matrix& other) {
    if (this->size != other.size)
        return *this;

    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->mas[i][j] *= other.mas[i][j];
        }
    }
    return *this;
}

Matrix::~Matrix() {
    for (int i = 0; i < size; i++) {
        delete[] mas[i];
    }
    delete[] mas;
}