#include <iostream>
#include <cmath>
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
struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};
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
int getDayOrderInYear(int day, int month, int year)
{
    int daysInYear = numberOfDaysInYear(year);
    int orderOfTheDay = 0;

    for (int i = 1; i < month; i++)
    {
        orderOfTheDay += numberOfDaysInMonth(year, i);
    }

    orderOfTheDay += day;

    return orderOfTheDay;
}
stDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
    stDate Date;
    short RemainingDays = DateOrderInYear;
    short MonthDays = 0;
    Date.year = Year;
    Date.month = 1;

    while (true)
    {
        MonthDays = numberOfDaysInMonth(Year, Date.month);

        if (RemainingDays > MonthDays)
        {
            RemainingDays -= MonthDays;
            Date.month++;
        }
        else
        {
            Date.day = RemainingDays;
            break;
        }
    }

    return Date;
}
int main()
{
    stDate Date;
    int day = readDay();
    int month = readMonth();
    int year = readYear();
    int orderOfTheDay = getDayOrderInYear(day, month, year);

    Date = GetDateFromDayOrderInYear(orderOfTheDay, year);

    cout << Date.day << "/" << Date.month << "/" << Date.year << endl;

    return 0;
}