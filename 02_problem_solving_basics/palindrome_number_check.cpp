#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}
int reverseNumber(int number)
{
    int remainder = 0, number2 = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        number2 = number2 * 10 + remainder;
    }

    return number2;
}
void printPALINDROMEeOrNot(int number)
{
    if (reverseNumber(number) == number)
    {
        cout << "Yes, it's a PALINDROME number! \n";
    }
    else
    {
        cout << "No, it's NOT A PALINDROME number! \n";
    }
}
int main()
{
    int number = readPositiveNumber("Enter a positive number: ");

    printPALINDROMEeOrNot(number);
    return 0;
}