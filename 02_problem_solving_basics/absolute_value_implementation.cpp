#include <iostream>
#include <cmath>
using namespace std;

float readNumber(string message)
{
    float number;

    cout << message << endl;
    cin >> number;

    return number;
}
float absoluteNumber(float number)
{
    if (number < 0)
    {
        number *= -1;
    }

    return number;
}

int main()
{
    float number = readNumber("Enter a number to absolute it: ");

    cout << "My absolute number: " << absoluteNumber(number) << endl;

    cout << "C++ absolute number: " << abs(number) << endl;

    return 0;
}