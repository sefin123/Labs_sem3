#include "Header.h"

int main() {

    cout << "size: ";
    int size = enterWithValidation();

    Matrix matrix(size);
    matrix.enter();

    Matrix copy(matrix);
    
    int minElem = copy.minElement();
    cout << "Min element: " << minElem << endl;
    
    int maxElem = copy.maxElement();
    cout << "Max element: " << maxElem << endl;

    copy.printMatrix();

    return 0;
}