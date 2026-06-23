#include <iostream>
using namespace std;

int readYear()
{
    int year;

    cout << "Enter the year to check if leap or not: ";
    cin >> year;

    return year;
}
bool leapYearOrNot(int year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int main()
{
    int year = readYear();

    if (leapYearOrNot(year))
    {
        cout << "[" << year << "] " << "is a leap Year!\n";
    }
    else
    {
        cout << "[" << year << "] " << "Not a leap year!\n";
    }

    return 0;
}