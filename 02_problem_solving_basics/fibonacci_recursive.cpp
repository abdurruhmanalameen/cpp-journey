#include <iostream>
using namespace std;
void PrintFibonacciUsingRecursion(int number, int prev1, int prev2)
{
    int fibNumber;

    if (number > 0)
    {
        fibNumber = prev1 + prev2;
        cout << fibNumber << "\t";
        prev2 = prev1;
        prev1 = fibNumber;

        PrintFibonacciUsingRecursion(number - 1, prev1, prev2);
    }
}
int main()
{
    PrintFibonacciUsingRecursion(10, 0, 1);
}