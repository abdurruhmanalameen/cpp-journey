#include <iostream>
using namespace std;

int readInput(string message)
{
    int year;

    cout << message;
    cin >> year;

    return year;
}
bool leapYearOrNot(int year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int numberOfDaysInMonth(int year, int month)
{
    if (month < 1 || month > 12)
    {
        return 0;
    }

    int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return month == 2 ? leapYearOrNot(year) ? 29 : 28 : daysInMonths[month];
}
int numberOfHoursInMonth(int year, int month)
{
    return (24 * numberOfDaysInMonth(year, month));
}
int numberOfMinutesInMonth(int year, int month)
{
    return (60 * numberOfHoursInMonth(year, month));
}
int numberOfSecondsInMonth(int year, int month)
{
    return (60 * numberOfMinutesInMonth(year, month));
}
int main()
{
    int year = readInput("Enter the year: ");
    int month = readInput("Enter the month: ");

    cout << "Days: " << numberOfDaysInMonth(year, month) << endl;
    cout << "Hours: " << numberOfHoursInMonth(year, month) << endl;
    cout << "Minutes: " << numberOfMinutesInMonth(year, month) << endl;
    cout << "Seconds: " << numberOfSecondsInMonth(year, month) << endl;

    return 0;
}