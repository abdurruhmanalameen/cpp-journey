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
int searchNumberInArray(int arr[100], int arrayLength, int toSearch)
{
    cout << "The number you are looking for is: " << toSearch << endl;

    for (int i = 0; i < arrayLength; i++)
    {
        if (toSearch == arr[i])
        {
            return 1;
        }
    }

    return -1;
}
bool isNumberInArray(int toSearch, int arr[100], int arrayLength)
{
    return searchNumberInArray(arr, arrayLength, toSearch) == 1;
}
void foundNotFound(bool foundOrNot)
{
    if (foundOrNot)
    {
        cout << "Yes, The number is found :-)\n";
    }
    else
    {
        cout << "No, The number is not found :-(\n";
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

    foundNotFound(isNumberInArray(toSearch, arr, arrayLength));
    return 0;
}