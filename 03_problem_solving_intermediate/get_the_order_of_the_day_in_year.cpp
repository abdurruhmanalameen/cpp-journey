#include <iostream>
using namespace std;

int readDay()
{
    int day;

    cout << "Enter the day: ";
    cin >> day;

    return day;
}
int readMonth()
{
    int month;

    cout << "Enter the month: ";
    cin >> month;

    return month;
}
int readYear()
{
    int year;

    cout << "Enter the year: ";
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
int numberOfDaysInMonth(int year, int month)
{
    if (month < 1 || month > 12)
    {
        return 0;
    }

    if (month == 2)
    {
        return checkLeapYearOrNot(year) ? 29 : 28;
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
int numberOfDaysInYear(int year)
{
    return (checkLeapYearOrNot(year) ? 366 : 365);
}
void getDayOrderInYear(int day, int month, int year)
{
    int daysInYear = numberOfDaysInYear(year);
    int orderOfTheDay = 0;

    for (int i = 1; i < month; i++)
    {
        orderOfTheDay += numberOfDaysInMonth(year, i);
    }

    orderOfTheDay += day;

    cout << "Number of days from the begining of the year is " << orderOfTheDay << endl;
}
int main()
{
    int day = readDay();
    int month = readMonth();
    int year = readYear();

    getDayOrderInYear(day, month, year);

    return 0;
}