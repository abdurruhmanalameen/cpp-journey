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
int getSumOfRow(int matrix[3][3], int rows, int columns)
{
    int sumOfRow = 0;

    for (int i = 0; i < columns; i++)
    {
        sumOfRow += matrix[rows][i];
    }

    return sumOfRow;
}
void copySumOfRowsInArray(int matrix[3][3], int rows, int columns, int arr[100])
{
    for (int i = 0; i < rows; i++)
    {
        arr[i] = getSumOfRow(matrix, i, columns);
    }
}
void printSumOfMatrix(int arr[100], int rows)
{
    cout << "\nThe following are the sum of each row in the matrix:\n";
    for (int i = 0; i < rows; i++)
    {
        printf("Sum of row [%d] = %d\n", i + 1, arr[i]);
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    int matrix[3][3];
    int arr[100];

    fillMatrixWithRandomNums(matrix, 3, 3);

    cout << "The following is a 3x3 random matrix:\n";
    printMatrix(matrix, 3, 3);

    copySumOfRowsInArray(matrix, 3, 3, arr);
    printSumOfMatrix(arr, 3);

    return 0;
}