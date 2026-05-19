#include <iostream>
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

int minNumInMatrix(int arr[3][3], int rows, int columns)
{
    int min = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    return min;
}
int maxNumInMatrix(int arr[3][3], int rows, int columns)
{
    int max = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    return max;
}
int main()
{
    int arr[3][3] = {
        {77, 5, 12},
        {22, 20, 1},
        {1, 0, 9}};

    cout << "Matrix1:\n";
    printMatrix(arr, 3, 3);

    cout << "Minimum number in matrix: " << minNumInMatrix(arr, 3, 3) << "\n";

    cout << "Maximum number in matrix:" << maxNumInMatrix(arr, 3, 3) << "\n";

    return 0;
}