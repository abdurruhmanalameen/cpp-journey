#include <iostream>
using namespace std;

void fillArrayWithNumbers(int arr[100], int &arrLength)
{
    arrLength = 10;

    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
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
int findNumberPositionInArray(int toSearch, int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (arr[i] == toSearch)
        {
            return i;
        }
    }

    return -1;
}
bool isNumberInArray(int toSearch, int arr[100], int arrLength)
{
    return findNumberPositionInArray(toSearch, arr, arrLength) != -1;
}
void addArrayElement(int number, int arr[100], int &arrLength)
{
    arr[arrLength] = number;

    arrLength++;
}
void copyDistinctNumbersInArray(int arrSource[100], int arrDestination[100], int sourceLength, int &destinationLength)
{
    for (int i = 0; i < sourceLength; i++)
    {
        if (!isNumberInArray(arrSource[i], arrDestination, destinationLength))
        {
            addArrayElement(arrSource[i], arrDestination, destinationLength);
        }
    }
}

int main()
{
    int arrSource[100], arrDestination[100];
    int sourceLength = 0, destinationLength = 0;

    fillArrayWithNumbers(arrSource, sourceLength);

    printArray(arrSource, sourceLength, "Array elements: ");

    copyDistinctNumbersInArray(arrSource, arrDestination, sourceLength, destinationLength);
    printArray(arrDestination, destinationLength, "\nDistinct Numbers: ");

    return 0;
}