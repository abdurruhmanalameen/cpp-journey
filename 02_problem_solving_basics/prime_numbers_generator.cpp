#include <iostream>
#include <math.h>

using namespace std;

enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime
};

int readPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message << "\n";
        cin >> number;
    } while (number < 0);

    return number;
}

enPrimeNotPrime PrimeNotPrime(int number)
{
    int half = round(number / 2);

    for (int i = 2; i <= half; i++)
    {
        if (number % i == 0)
        {
            return enPrimeNotPrime::NotPrime;
        }
    }
    return enPrimeNotPrime::Prime;
}

void printPrimeNumbers(int input)
{
    for (int i = 1; i <= input; i++)
    {
        if (PrimeNotPrime(i) == enPrimeNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
}
int main()
{
    printPrimeNumbers(readPositiveNumber("Enter a positive number: "));

    return 0;
}