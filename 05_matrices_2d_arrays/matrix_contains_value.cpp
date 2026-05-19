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
int readNumber(string message)
{
    int number;

    cout << message << endl;
    cin >> number;

    return number;
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
void printChecking(bool isNumberInMatrix)
{
    if (isNumberInMatrix)
    {
        cout << "\nYes the number is there!\n";
    }
    else
    {
        cout << "\nNo the number is not there!\n";
    }
}

int main()
{
    int arr[3][3] =
        {
            {9, 88, 0},
            {0, 9, 9},
            {0, 0, 9}};

    printMatrix(arr, 3, 3);

    int toCheck = readNumber("Enter a number to check: ");

    printChecking(isNumberInMatrix(arr, 3, 3, toCheck));

    return 0;
}