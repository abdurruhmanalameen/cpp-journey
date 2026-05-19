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
void invertedPattern(int number)
{
    for (int i = 65; i <= 64 + number; i++)
    {

        for (int j = 65; j <= i; j++)
        {
            cout << char(i);
        }

        cout << endl;
    }
}
int main()
{
    int number = readPositiveNumber("Enter a positive number: ");

    invertedPattern(number);
    return 0;
}