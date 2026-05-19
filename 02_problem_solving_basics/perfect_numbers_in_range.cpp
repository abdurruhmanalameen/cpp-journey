#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message;
        cin >> number;
    } while (number < 0);

    return number;
}
bool checkPerfectOrNot(int number)
{
    int sum = 0;

    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return sum == number;
}
void printPerfectNumsFrom1ToN(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (checkPerfectOrNot(i))
        {
            cout << i << endl;
        }
    }
}

int main()
{
    printPerfectNumsFrom1ToN(readPositiveNumber("Enter a number to show all the perfect numbers: "));
    return 0;
}