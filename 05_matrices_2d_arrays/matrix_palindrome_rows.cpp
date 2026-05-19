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

bool isPalindrome(int arr[3][3], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns / 2; j++)
        {
            if (arr[i][j] != arr[i][columns - 1 - j])
            {
                return false;
            }
        }
    }

    return true;
}
void printPalindromeOrNot(int arr[3][3], int rows, int columns)
{
    if (isPalindrome(arr, rows, columns))
    {
        cout << "Yes the array is palindrome!\n";
    }
    else
    {
        cout << "No the array isn't palindrome!\n";
    }
}

int main()
{
    int arr[3][3] = {
        {1, 5, 1},
        {3, 20, 3},
        {6, 0, 6}};

    cout << "Matrix1:\n";
    printMatrix(arr, 3, 3);

    printPalindromeOrNot(arr, 3, 3);

    return 0;
}