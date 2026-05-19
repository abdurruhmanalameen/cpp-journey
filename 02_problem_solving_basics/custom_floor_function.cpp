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
int floorNumber(float number)
{
    int intPart = (int)number;

    if (number > 0)
        return intPart;
    else
        return --intPart;
}

int main()
{
    float number = readNumber("Enter a number to floor it: ");

    cout << "My floor number: " << floorNumber(number) << endl;

    cout << "C++ floor number: " << floor(number) << endl;

    return 0;
}