#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void readArray(int arr[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = randomNumber(1, 100);
    }
}
void printArray(int arr[100], short arrayLength, string message)
{
    cout << message;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int readArrayLength()
{
    int arrayLength;

    cout << "Enter the length of the array: ";
    cin >> arrayLength;

    return arrayLength;
}
void reverseArray(int arr1[100], int arr2[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr2[i] = arr1[arrayLength - 1 - i];
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], arr2[100];
    short arrayLength = readArrayLength();

    readArray(arr1, arrayLength);
    printArray(arr1, arrayLength, "Array before reversing: ");

    reverseArray(arr1, arr2, arrayLength);
    printArray(arr2, arrayLength, "Array after reversing: ");

    return 0;
}