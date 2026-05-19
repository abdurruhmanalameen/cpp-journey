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
int sumNumberInArray(int arr[100], short numOfElements)
{
    int sum = arr[0];

    for (int i = 1; i < numOfElements; i++)
    {
        sum += arr[i];
    }

    return sum;
}
void averageOfSum(int sum, int numOfElements)
{
    float average = (float)sum / (float)numOfElements;

    cout << "Average: " << average << endl;
}
int main()
{
    srand(time(unsigned(NULL)));

    int arr[100];
    short numberOfElements;

    fillArrayWithRandomNumbers(arr, numberOfElements);
    printArray(arr, numberOfElements);
    int sum = sumNumberInArray(arr, numberOfElements);
    averageOfSum(sum, numberOfElements);
    return 0;
}