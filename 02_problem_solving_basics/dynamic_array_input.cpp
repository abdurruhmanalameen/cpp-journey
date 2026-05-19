#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}
void addArrayElement(int number, int arr[100], int &arrayLength)
{
    arr[arrayLength] = number;

    arrayLength++;
}
void fillArray(int arr[100], int &arrayLength)
{
    bool choice;
    do
    {
        addArrayElement(readPositiveNumber("Please enter a number? "), arr, arrayLength);

        cout << "\nDo you want more numbers? [1]Yes [0]No ";
        cin >> choice;

    } while (choice);
}
void printArray(int arr[100], int arrayLength)
{
    cout << "Array length: " << arrayLength << endl;
    cout << "Array elements: ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[100];
    int arrayLength = 0;

    fillArray(arr, arrayLength);
    printArray(arr, arrayLength);

    return 0;
}