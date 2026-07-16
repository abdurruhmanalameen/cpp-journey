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
stDate readDate()
{
    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
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
bool isLastDayInMonth(stDate date)
{
    return date.day == numberOfDaysInMonth(date.year, date.month);
}
bool isLastMonthInYear(stDate date)
{
    return date.month == 12;
}
stDate decreaseDateByOneDay(stDate &date)
{
    if (date.day == 1)
    {
        if (date.month == 1)
        {
            date.year--;
            date.month = 12;
            date.day = 31;
        }
        else
        {
            date.month--;
            date.day = numberOfDaysInMonth(date.year, date.month);
        }
    }
    else
    {
        date.day--;
    }

    return date;
}
stDate decreaseDateByXDays(stDate &date, int days)
{
    for (int i = 0; i < days; i++)
    {
        date = decreaseDateByOneDay(date);
    }

    return date;
}
stDate decreaseDateByOneWeek(stDate &date)
{
    for (int i = 0; i < 7; i++)
    {
        date = decreaseDateByOneDay(date);
    }

    return date;
}
stDate decreaseDateByXWeeks(stDate &date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        date = decreaseDateByOneWeek(date);
    }

    return date;
}
stDate decreaseDateByOneMonth(stDate &date)
{

    if (date.month == 1)
    {
        date.month = 12;
        date.year--;
    }
    else
    {
        date.month--;
    }

    int days = numberOfDaysInMonth(date.year, date.month);

    if (date.day > days)
    {
        date.day = days;
    }

    return date;
}
stDate decreaseDateByXMonths(stDate &date, int months)
{
    for (int i = 0; i < months; i++)
    {
        date = decreaseDateByOneMonth(date);
    }

    return date;
}
stDate decreaseDateByOneYear(stDate &date)
{
    date.year--;

    return date;
}
stDate decreaseDateByXYears(stDate &date, int years)
{
    for (int i = 0; i < years; i++)
    {
        decreaseDateByOneYear(date);
    }

    return date;
}
stDate decreaseDateByXYearsFaster(stDate &date, int years)
{
    date.year -= years;

    return date;
}
stDate decreaseDateByOneDecade(stDate &date)
{
    date.year -= 10;

    return date;
}
stDate decreaseDateByXDecades(stDate &date, int decades)
{
    for (int i = 0; i < decades; i++)
    {
        decreaseDateByOneDecade(date);
    }

    return date;
}
stDate decreaseDateByXDecadesFaster(stDate &date, int decades)
{
    date.year -= (decades * 10);

    return date;
}
stDate decreaseDateByOneCentury(stDate &date)
{
    date.year -= 100;

    return date;
}
stDate decreaseDateByMillennium(stDate &date)
{
    date.year -= 1000;

    return date;
}
int main()
{
    stDate date = readDate();

    decreaseDateByOneDay(date);
    cout << "01-Substracting one day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXDays(date, 10);
    cout << "02-Substracting " << "10" << " days is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByOneWeek(date);
    cout << "03-Substracting one week is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXWeeks(date, 10);
    cout << "04-Substracting " << "10" << " weeks is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByOneMonth(date);
    cout << "05-Substracting one month is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXMonths(date, 5);
    cout << "06-Substracting " << "5" << " months is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByOneYear(date);
    cout << "07-Substracting one year is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXYears(date, 10);
    cout << "08-Substracting " << "10" << " years is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXYearsFaster(date, 10);
    cout << "09-Substracting " << "10" << " years faster is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByOneDecade(date);
    cout << "10-Substracting one decade is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXDecades(date, 10);
    cout << "11-Substracting " << "10" << " decades is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByXDecadesFaster(date, 10);
    cout << "12-Substracting " << "10" << " decades faster is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByOneCentury(date);
    cout << "13-Substracting one century is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    decreaseDateByMillennium(date);
    cout << "14-Substracting one millennium is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}