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
stDate increaseDateByOneDay(stDate &date)
{
    if (isLastDayInMonth(date))
    {
        if (isLastMonthInYear(date))
        {
            date.year++;
            date.month = 1;
            date.day = 1;
        }
        else
        {
            date.month++;
            date.day = 1;
        }
    }
    else
    {
        date.day++;
    }

    return date;
}
stDate increaseDateByXDays(stDate &date, int days)
{
    for (int i = 0; i < days; i++)
    {
        date = increaseDateByOneDay(date);
    }

    return date;
}
stDate increaseDateByOneWeek(stDate &date)
{
    for (int i = 0; i < 7; i++)
    {
        date = increaseDateByOneDay(date);
    }

    return date;
}
stDate increaseDateByXWeeks(stDate &date, int weeks)
{
    for (int i = 0; i < weeks; i++)
    {
        date = increaseDateByOneWeek(date);
    }

    return date;
}
stDate increaseDateByOneMonth(stDate &date)
{

    if (date.month == 12)
    {
        date.month = 1;
        date.year++;
    }
    else
    {
        date.month++;
    }

    int days = numberOfDaysInMonth(date.year, date.month);

    if (date.day > days)
    {
        date.day = days;
    }

    return date;
}
stDate increaseDateByXMonths(stDate &date, int months)
{
    for (int i = 0; i < months; i++)
    {
        date = increaseDateByOneMonth(date);
    }

    return date;
}
stDate increaseDateByOneYear(stDate &date)
{
    date.year++;

    return date;
}
stDate increaseDateByXYears(stDate &date, int years)
{
    for (int i = 0; i < years; i++)
    {
        increaseDateByOneYear(date);
    }

    return date;
}
stDate increaseDateByXYearsFaster(stDate &date, int years)
{
    date.year += years;

    return date;
}
stDate increaseDateByOneDecade(stDate &date)
{
    date.year += 10;

    return date;
}
stDate increaseDateByXDecades(stDate &date, int decades)
{
    for (int i = 0; i < decades; i++)
    {
        increaseDateByOneDecade(date);
    }

    return date;
}
stDate increaseDateByXDecadesFaster(stDate &date, int decades)
{
    date.year += (decades * 10);

    return date;
}
stDate increaseDateByOneCentury(stDate &date)
{
    date.year += 100;

    return date;
}
stDate increaseDateByMillennium(stDate &date)
{
    date.year += 1000;

    return date;
}
int main()
{
    stDate date = readDate();

    increaseDateByOneDay(date);
    cout << "01-Adding one day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXDays(date, 10);
    cout << "02-Adding " << "10" << " days is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByOneWeek(date);
    cout << "03-Adding one week is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXWeeks(date, 10);
    cout << "04-Adding " << "10" << " weeks is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByOneMonth(date);
    cout << "05-Adding one month is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXMonths(date, 5);
    cout << "06-Adding " << "5" << " months is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByOneYear(date);
    cout << "07-Adding one year is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXYears(date, 10);
    cout << "08-Adding " << "10" << " years is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXYearsFaster(date, 10);
    cout << "09-Adding " << "10" << " years faster is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByOneDecade(date);
    cout << "10-Adding one decade is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXDecades(date, 10);
    cout << "11-Adding " << "10" << " decades is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByXDecadesFaster(date, 10);
    cout << "12-Adding " << "10" << " decades faster is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByOneCentury(date);
    cout << "13-Adding one century is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    increaseDateByMillennium(date);
    cout << "14-Adding one millennium is: "
         << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}