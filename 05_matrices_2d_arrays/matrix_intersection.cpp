#include <iostream>
#include <iomanip>
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
bool isNumberInMatrix(int arr[3][3], int rows, int columns, int toCheck)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == toCheck)
            {
                return true;
            }
        }
    }
    return false;
}
void intersectedNumbersInMatrix(int arr1[3][3], int arr2[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (isNumberInMatrix(arr2, 3, 3, arr1[i][j]))
            {
                cout << setw(3) << arr1[i][j] << "\t";
            }
        }
    }
}

int main()
{
    int arr1[3][3] = {
        {77, 5, 12},
        {22, 20, 1},
        {1, 0, 9}};
    int arr2[3][3] = {
        {5, 80, 90},
        {22, 77, 1},
        {10, 8, 33}};

    cout << "Matrix1:\n";
    printMatrix(arr1, 3, 3);

    cout << "Matrix2:\n";
    printMatrix(arr2, 3, 3);

    cout << "Intersected numbers are:\n";
    intersectedNumbersInMatrix(arr1, arr2, 3, 3);

    return 0;
}