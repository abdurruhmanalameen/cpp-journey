#include <iostream>
#include <iomanip>
#include "include/myLibrary.h"
using namespace std;

void fillMatrixWithRandomNums(int matrix[3][3], int rows, int columns)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = randomNumber(1, 100);
        }
    }
}
void printMatrix(int matrix[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(3) << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}
int main()
{
    int matrix[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(matrix, 3, 3);

    printMatrix(matrix, 3, 3);

    return 0;
}