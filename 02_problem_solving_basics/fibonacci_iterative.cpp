#include <iostream>
using namespace std;

void fibonacciSeries(int series)
{
    int lastNumber = 0;
    int currentNumber = 1;
    int fibNumber = 0;

    cout << "1\t";
    for (int i = 0; i < series; i++)
    {
        fibNumber = lastNumber + currentNumber;
        cout << fibNumber << "\t";
        lastNumber = currentNumber;
        currentNumber = fibNumber;
    }
}

int main()
{
    fibonacciSeries(10);

    return 0;
}