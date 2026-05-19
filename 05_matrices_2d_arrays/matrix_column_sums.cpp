#include <iostream>
#include <iomanip>
#include "include/myLibrary.h"
#include <stdio.h>
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
int getsumOfColumn(int matrix[3][3], int rows, int columns)
{
    int sumOfColumn = 0;

    for (int i = 0; i < rows; i++)
    {
        sumOfColumn += matrix[i][columns];
    }

    return sumOfColumn;
}
void printSumOfMatrix(int matrix[3][3], int rows, int columns)
{
    for (int i = 0; i < columns; i++)
    {
        cout << "\nThe following are the sum of each column in the matrix:\n";
        printf("Sum of row [%d] = %d\n", i + 1, getsumOfColumn(matrix, rows, i));
    }
}

int main()
{
    int matrix[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(matrix, 3, 3);

    cout << "The following is a 3x3 random matrix:\n";
    printMatrix(matrix, 3, 3);

    printSumOfMatrix(matrix, 3, 3);
    return 0;
}