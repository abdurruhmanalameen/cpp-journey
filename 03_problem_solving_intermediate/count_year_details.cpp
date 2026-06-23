#include <iostream>
using namespace std;

int readYear()
{
    int year;

    cout << "Enter the year to show it's details: ";
    cin >> year;

    return year;
}
bool leapYearOrNot(int year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int numberOfDaysInYear(int year)
{
    return (leapYearOrNot(year) ? 366 : 365);
}
int numberOfHoursInYear(int year)
{
    return (24 * numberOfDaysInYear(year));
}
int numberOfMinutesInYear(int year)
{
    return (60 * numberOfHoursInYear(year));
}
int numberOfSecondsInYear(int year)
{
    return (60 * numberOfMinutesInYear(year));
}
int main()
{
    int year = readYear();

    cout << "Days: " << numberOfDaysInYear(year) << endl;
    cout << "Hours: " << numberOfHoursInYear(year) << endl;
    cout << "Minutes: " << numberOfMinutesInYear(year) << endl;
    cout << "Seconds: " << numberOfSecondsInYear(year) << endl;

    return 0;
}