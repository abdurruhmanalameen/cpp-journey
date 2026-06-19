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

    cout << "How many members are they? ";
    cin >> arrayLength;

    return arrayLength;
}
void readArray(string arr[100], short &arrayLength)
{
    cout << "Enter the names of members:\n";
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
    }
}
void printArray(string arr[100], short arrayLength, string message)
{
    cout << message;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "[" << i + 1 << "] " << arr[i] << endl;
    }
    cout << endl;
}
void shuffleArray(string arr[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        swap(arr[randomNumber(0, arrayLength - 1)], arr[randomNumber(0, arrayLength - 1)]);
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    string arr1[100];
    short arrayLength = readArrayLength();

    readArray(arr1, arrayLength);
    printArray(arr1, arrayLength, "\nArray Elements before shuffle:\n");

    shuffleArray(arr1, arrayLength);
    printArray(arr1, arrayLength, "\nArray after being shuffled:\n");

    return 0;
}