#include <iostream>
using namespace std;

int enterWithValidation();

int enterWithValidationForScope(int scope);

int enterMatrixWithValidation();

class Matrix {
	int size;
	int** mas;
public:

	Matrix(int sizeOfMatrix);

	Matrix(const Matrix& other);

	void enter();

	const Matrix& operator = (const Matrix& other);

	const Matrix& operator & (const Matrix& other);

	void printMatrix();

	~Matrix();
};