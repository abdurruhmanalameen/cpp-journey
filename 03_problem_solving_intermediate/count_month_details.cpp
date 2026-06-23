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

    if (month == 2)
    {
        return leapYearOrNot(year) ? 29 : 28;
    }

    int MonthsOf31Day[13] = {
        1, 3, 5, 7, 8, 10, 12};

    for (int i = 0; i < 7; i++)
    {
        if (MonthsOf31Day[i] == month)
        {
            return 31;
        }
    }

    return 30;
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