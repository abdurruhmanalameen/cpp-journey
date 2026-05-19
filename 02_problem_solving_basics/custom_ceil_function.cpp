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
float getFraction(float number)
{
    return number - (int)number;
}
int ceilNumber(float number)
{
    int intPart = (int)number;

    if (abs(getFraction(number)) > 0)
        if (number > 0)
            return ++intPart;
        else
            return intPart;
    else
        return intPart;
}

int main()
{
    float number = readNumber("Enter a number to ceil it: ");

    cout << "My ceil number: " << ceilNumber(number) << endl;

    cout << "C++ ceil number: " << ceil(number) << endl;

    return 0;
}