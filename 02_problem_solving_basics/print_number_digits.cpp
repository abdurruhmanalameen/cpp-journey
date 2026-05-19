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

    while (number > 0)
    {
        remainder = number % 10;
        cout << remainder << endl;
        number = number / 10;
    }
}
int main()
{
    printDigits(readPositiveNumber("Enter a number: "));
    return 0;
}