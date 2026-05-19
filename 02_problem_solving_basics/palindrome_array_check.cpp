#include <iostream>
using namespace std;

void fillArrayWithNumbers(int arr[100], int &arrLength)
{
    arrLength = 6;

    arr[0] = 9;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 30;
    arr[4] = 20;
    arr[5] = 10;
}
void printArray(int arr[100], int arrayLength, string message)
{
    cout << message << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
bool printPalindromeArrayOrNot(int arr[100], short arrayLength)
{

    for (int i = 0; i < arrayLength / 2; i++)
    {
        if (arr[i] != arr[arrayLength - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[100], arrLength = 0;

    fillArrayWithNumbers(arr, arrLength);

    printArray(arr, arrLength, "Array Elements: ");

    if (printPalindromeArrayOrNot(arr, arrLength))
    {
        cout << "Yes the array is not palindrome!\n";
    }
    else
    {
        cout << "No the array is palindrome!\n";
    }

    return 0;
}