#include <iostream>
using namespace std;

struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};
stDate getSystemDate()
{
    stDate date;
    time_t t = time(0);
    tm *now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

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
string getDayName(int dayNumber)
{
    string daysNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return daysNames[dayNumber];
}
short getOrderOfDay(stDate date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + (12 * a) - 2;
    int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}
short getDayOrderInYear(stDate date)
{
    int daysInYear = numberOfDaysInYear(date.year);
    int orderOfTheDay = 0;

    for (int i = 1; i < date.month; i++)
    {
        orderOfTheDay += numberOfDaysInMonth(date.year, i);
    }

    orderOfTheDay += date.day;

    return orderOfTheDay;
}
bool isEndOfWeek(short dayOrder)
{
    if (dayOrder == 6)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isWeekEnd(short dayOrder)
{
    if (dayOrder == 6 || dayOrder == 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isBusinessDay(short dayOrder)
{
    if (dayOrder == 6 || dayOrder == 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}
short daysUntilTheEndOfWeek(short dayOrder)
{
    return 6 - dayOrder;
}
short daysUntilTheEndOfMonth(stDate date)
{
    return numberOfDaysInMonth(date.year, date.month) - date.day;
}
short daysUntilTheEndOfYear(stDate date)
{
    return numberOfDaysInYear(date.year) - getDayOrderInYear(date);
}

int main()
{
    stDate date = getSystemDate();

    short dayOrder = getOrderOfDay(date);

    cout << "\nToday is " << getDayName(dayOrder) << ", " << date.day << "/" << date.month << "/" << date.year << endl;

    cout << "\nis it end of week?\n";
    if (isEndOfWeek(dayOrder))
    {
        cout << "Yes it's end of week\n";
    }
    else
    {
        cout << "No it's not end of week\n";
    }

    cout << "\nis it a weekend?\n";
    if (isWeekEnd(dayOrder))
    {
        cout << "Yes it's a weekend\n";
    }
    else
    {
        cout << "No it's not a weekend\n";
    }

    cout << "\nis it a business day?\n";
    if (isBusinessDay(dayOrder))
    {
        cout << "Yes it's a business day\n";
    }
    else
    {
        cout << "No it's not a business day\n";
    }

    short untilTheEndOfWeek = daysUntilTheEndOfWeek(dayOrder);
    short untilTheEndOfMonth = daysUntilTheEndOfMonth(date);
    short untilTheEndOfYear = daysUntilTheEndOfYear(date);

    cout << "\nDays until end of week :" << untilTheEndOfWeek << " day(s)\n";
    cout << "Days until end of month :" << untilTheEndOfMonth << " day(s)\n";
    cout << "Days until end of year :" << untilTheEndOfYear << " day(s)\n";

    return 0;
}