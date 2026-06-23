#include <iostream>
using namespace std;

int readYear()
{
    int year;

    cout << "Enter the year to check if leap or not: ";
    cin >> year;

    return year;
}
bool checkLeapYearOrNot(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return false;
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int year = readYear();

    if (checkLeapYearOrNot(year))
    {
        cout << "[" << year << "] " << "is a leap Year!\n";
    }
    else
    {
        cout << "[" << year << "] " << "Not a leap year!\n";
    }

    return 0;
}