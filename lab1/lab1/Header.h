#include <iostream>
using namespace std;

int enterWithValidation();

int enterMatrixWithValidation();

class Matrix {
	int size;
	int** mas;
public:

	Matrix(int sizeOfMatrix);

	Matrix(const Matrix& other);

	void enter();
	int getSize();

	int minElement();

	int maxElement();

	void printMatrix();

	~Matrix();
};