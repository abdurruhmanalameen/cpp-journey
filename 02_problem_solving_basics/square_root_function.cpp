#include <iostream>
#include <cmath>
using namespace std;

int readNumber(string message)
{
    int number;

    cout << message << endl;
    cin >> number;

    return number;
}
int sqrtNumber(int number)
{

    return pow(number, .5);
}

int main()
{
    float number = readNumber("Enter a number to sqrt it: ");

    cout << "My sqrt number: " << sqrtNumber(number) << endl;

    cout << "C++ sqrt number: " << sqrt(number) << endl;

    return 0;
}