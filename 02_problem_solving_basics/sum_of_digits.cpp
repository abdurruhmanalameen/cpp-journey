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
void printSumOfDigits(int number)
{
    int remainder = 0;
    int sum = 0;

    while (number > 0)
    {
        remainder = number % 10;
        sum += remainder;
        number = number / 10;
    }
    cout << "Sum of digits = " << sum << endl;
}
int main()
{
    printSumOfDigits(readPositiveNumber("Enter a positive number: "));
    return 0;
}