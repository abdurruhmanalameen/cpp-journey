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
void printDigits(int number)
{
    int remainder = 0;
    int number2 = 0;

    while (number > 0)
    {
        remainder = number % 10;
        number2 = number2 * 10 + remainder;
        number = number / 10;
    }
    cout << number2 << "\n";
}
int main()
{
    printDigits(readPositiveNumber("Enter a positive number: "));
    return 0;
}