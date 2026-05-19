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
        arr[i] = randomNumber(-100, 100);
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
void countPositiveNumbersUsingAddArrayElements(int arr[100], short &arrLength)
{
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] > 0)
        {
            counter++;
        }
    }

    cout << "Positive numbers are " << counter << " elements\n";
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr[100];
    short arrLength = 0;

    readArray(arr, arrLength);
    printArray(arr, arrLength, "\nArray elements: ");
    countPositiveNumbersUsingAddArrayElements(arr, arrLength);

    return 0;
}