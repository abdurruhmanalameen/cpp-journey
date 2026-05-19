#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void readArray(int arr[100], short &numOfElements)
{
    cout << "How many elements do you want? ";
    cin >> numOfElements;

    for (int i = 0; i < numOfElements; i++)
    {
        arr[i] = randomNumber(1, 100);
    }
}
void printArray(int arr[100], short numOfElements, string message)
{
    cout << message;
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void copyArray(int arr1[100], int arr2[100], short numOfElements)
{
    for (int i = 0; i < numOfElements; i++)
    {
        arr2[i] = arr1[i];
    }
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], arr2[100];
    short numberOfElements;

    readArray(arr1, numberOfElements);
    printArray(arr1, numberOfElements, "\n Array1 elements: ");
    copyArray(arr1, arr2, numberOfElements);
    printArray(arr1, numberOfElements, "\n Array2 elements after copying: ");

    return 0;
}