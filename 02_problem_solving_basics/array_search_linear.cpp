#include <iostream>
#include <cstdlib>
using namespace std;

int generateRandomNumber(int from, int to)
{
    int randomNumber = rand() % (to - from + 1) + from;

    return randomNumber;
}
int readNumber(string message)
{
    int number;

    cout << message << endl;

    cin >> number;

    return number;
}
void fillArrayWithRandomNumbers(int arr[100], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = generateRandomNumber(1, 100);
    }
}
void printArray(int arr[100], int arrayLength)
{
    cout << "Array Elements:\n";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void searchNumberInArray(int arr[100], int arrayLength, int toSearch)
{
    cout << "The number you are looking for is: " << toSearch << endl;

    for (int i = 0; i < arrayLength; i++)
    {
        if (toSearch == arr[i])
        {
            cout << "The number found at position: " << i << endl;
            cout << "The number found in the order: " << i + 1 << endl;

            break;
        }
        if (i == arrayLength - 1)
        {
            cout << "The number is not found :-(\n";
        }
    }
}
int main()
{
    srand(time(unsigned(NULL)));

    int arr[100];
    int arrayLength = readNumber("How many Elements? ");

    fillArrayWithRandomNumbers(arr, arrayLength);
    printArray(arr, arrayLength);

    int toSearch = readNumber("\nPlease enter a number to search for?");
    searchNumberInArray(arr, arrayLength, toSearch);

    return 0;
}