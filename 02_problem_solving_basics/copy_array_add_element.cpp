#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void readArray(int arr[100], short &arrayLength)
{
    cout << "How many elements do you want? ";
    cin >> arrayLength;

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
void addArrayElement(int number, int arr[100], short &arrayLength)
{
    arr[arrayLength] = number;

    arrayLength++;
}
void copyArrayUsingAddArrayElements(int arr1[100], int arr2[100], short &arr1Length, short &arr2Length)
{
    for (int i = 0; i < arr1Length; i++)
    {
        addArrayElement(arr1[i], arr2, arr2Length);
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], arr2[100];
    short arr1Length = 0;
    short arr2Length = 0;

    readArray(arr1, arr1Length);
    printArray(arr1, arr1Length, "\n Array1 elements: ");
    copyArrayUsingAddArrayElements(arr1, arr2, arr1Length, arr2Length);
    printArray(arr2, arr2Length, "\n Array2 elements after copying: ");

    return 0;
}