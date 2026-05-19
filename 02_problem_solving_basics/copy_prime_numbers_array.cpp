#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime
};
enPrimeNotPrime checkPrime(int number)
{
    int half = round(number / 2);

    for (int i = 2; i <= half; i++)
    {
        if (number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}
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
void copyPrimeNumbersInArray(int arr1[100], int arr2[100], short numOfElements, short &numOfElements2)
{
    short counter = 0;

    for (int i = 0; i < numOfElements; i++)
    {
        if (checkPrime(arr1[i]) == enPrimeNotPrime::Prime)
        {
            arr2[counter] = arr1[i];
            counter++;
        }
    }

    numOfElements2 = counter;
}

int main()
{
    srand(time(unsigned(NULL)));

    int arr1[100], primeNumArray[100];
    short numberOfElements, numberOfElements2;

    readArray(arr1, numberOfElements);
    printArray(arr1, numberOfElements, "\nArray1 elements: ");
    copyPrimeNumbersInArray(arr1, primeNumArray, numberOfElements, numberOfElements2);
    printArray(primeNumArray, numberOfElements2, "\nPrime Numbers in the array: ");

    return 0;
}