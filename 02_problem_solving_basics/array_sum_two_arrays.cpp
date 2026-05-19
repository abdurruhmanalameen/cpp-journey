#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void readArray(int arr1[100], short &arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr1[i] = randomNumber(1, 100);
    }
}
int readArrayLength()
{
    int arrayLength;

    cout << "Enter the length of the array: ";
    cin >> arrayLength;

    return arrayLength;
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
void sumOfTwoArrays(int arr1[100], int arr2[100], int sumArrays[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        sumArrays[i] = arr1[i] + arr2[i];
    }
}
int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], arr2[100], sumArray[100];
    short arrayLength = readArrayLength();

    readArray(arr1, arrayLength);
    readArray(arr2, arrayLength);

    printArray(arr1, arrayLength, "Array 1: ");
    printArray(arr2, arrayLength, "Array 2: ");

    sumOfTwoArrays(arr1, arr2, sumArray, arrayLength);
    printArray(sumArray, arrayLength, "Sum of those arrays: ");

    return 0;
}