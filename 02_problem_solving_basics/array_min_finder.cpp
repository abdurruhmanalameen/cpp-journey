#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
void fillArrayWithRandomNumbers(int arr[100], short &numOfElements)
{
    cout << "How many elements do you want? ";
    cin >> numOfElements;

    for (int i = 0; i < numOfElements; i++)
    {
        arr[i] = randomNumber(1, 100);
    }
}
void printArray(int arr[100], short numOfElements)
{
    cout << "\nArray elements: ";
    for (int i = 0; i < numOfElements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void minNumberInArray(int arr[100], short numOfElements)
{
    int min = arr[0];

    for (int i = 1; i < numOfElements; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "Min number is: " << min << endl;
}
int main()
{
    srand(time(unsigned(NULL)));

    int arr[100];
    short numberOfElements;

    fillArrayWithRandomNumbers(arr, numberOfElements);
    printArray(arr, numberOfElements);
    minNumberInArray(arr, numberOfElements);

    return 0;
}