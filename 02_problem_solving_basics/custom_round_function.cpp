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
int RoundNumber(float number)
{
    int intPart = (int)number;
    float fractionPart = getFraction(number);
    if (abs(fractionPart) >= .5)
    {
        if (number > 0)
            return ++intPart;
        else
            return --intPart;
    }
    else
    {
        return intPart;
    }
}

int main()
{
    float number = readNumber("Enter a number to Round it: ");

    cout << "My Round number: " << RoundNumber(number) << endl;

    cout << "C++ Round number: " << round(number) << endl;

    return 0;
}