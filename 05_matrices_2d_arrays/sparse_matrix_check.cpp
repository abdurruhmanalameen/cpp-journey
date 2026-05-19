#include <iostream>
#include <cstdio>
using namespace std;

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
int countNumberInMatrix(int arr[3][3], int rows, int columns, int toCheck)
{
    int frequency = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == toCheck)
            {
                frequency++;
            }
        }
    }

    return frequency;
}
bool isSparse(int arr[3][3], int rows, int columns)
{
    return countNumberInMatrix(arr, rows, columns, 0) > (rows * columns) / 2;
}
void printSparseOrNot(bool isSparse)
{
    if (isSparse)
    {
        cout << "\nYes the array is sparse!\n";
    }
    else
    {
        cout << "\nNo the array is not sparse!\n";
    }
}

int main()
{
    int arr[3][3] =
        {
            {9, 0, 0},
            {9, 0, 9},
            {0, 0, 9}};

    printMatrix(arr, 3, 3);

    printSparseOrNot(isSparse(arr, 3, 3));

    return 0;
}