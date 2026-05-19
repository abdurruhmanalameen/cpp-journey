#include <iostream>
#include <cstdio>
#include "include/myLibrary.h"
using namespace std;

void fillMatrixWithRandomNums(int matrix[3][3], int rows, int columns)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = randomNumber(1, 10);
        }
    }
}
void printMatrix(int matrix[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%0*d\t", 2, matrix[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

int sumOfMatrix(int arr[3][3], int rows, int columns)
{
    int sum = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
    }

    return sum;
}

int main()
{
    int arr[3][3];

    srand(time(unsigned(NULL)));

    fillMatrixWithRandomNums(arr, 3, 3);
    cout << "Array:\n";
    printMatrix(arr, 3, 3);

    cout << "Sum of matrix is: " << sumOfMatrix(arr, 3, 3) << endl;

    return 0;
}