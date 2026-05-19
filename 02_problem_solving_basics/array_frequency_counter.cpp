#include <iostream>
using namespace std;

int readNumber(string message)
{
    int number;

    cout << message << endl;
    cin >> number;

    return number;
}
void readArray(int arr[100], short &numOfElements)
{
    cout << "How many elements do you want? ";
    cin >> numOfElements;

    for (int i = 0; i < numOfElements; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}
void printArray(int arr[100], short numOfElements)
{
    cout << "\nThe original array: ";
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
short checkFrequency(int check, int arr[100], short numOfElements)
{
    short counter = 0;

    for (int i = 0; i < numOfElements; i++)
    {
        if (arr[i] == check)
        {
            counter++;
        }
    }

    return counter;
}

int main()
{
    int arr[100];
    short numOfElements;

    readArray(arr, numOfElements);

    int check = readNumber("\nWhich number do you want to check? ");

    printArray(arr, numOfElements);

    short frequency = checkFrequency(check, arr, numOfElements);
    cout << "Number " << check << " repeated " << frequency << " time(s)" << "\n";

    return 0;
}