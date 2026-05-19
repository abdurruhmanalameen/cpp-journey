#include <iostream>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}
int readArrayLength()
{
    int arrayLength;

    cout << "Enter the length of the array: ";
    cin >> arrayLength;

    return arrayLength;
}
void readArray(int arr[100], short &arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = i + 1;
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
void shuffleArray(int arr[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        swap(arr[randomNumber(0, arrayLength - 1)], arr[randomNumber(0, arrayLength - 1)]);
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], sumArray[100];
    short arrayLength = readArrayLength();

    readArray(arr1, arrayLength);
    printArray(arr1, arrayLength, "\nArray Elements before shuffle: ");

    shuffleArray(arr1, arrayLength);
    printArray(arr1, arrayLength, "\nArray after being shuffled: ");
    return 0;
}