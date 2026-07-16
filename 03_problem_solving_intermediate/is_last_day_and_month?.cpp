#include <iostream>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};
stDate readDate()
{
    stDate date;

    cout << "\nEnter the day: ";
    cin >> date.day;

    cout << "Enter the month: ";
    cin >> date.month;

    cout << "Enter the year: ";
    cin >> date.year;

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
bool isLastDayInMonth(stDate date)
{
    return date.day == numberOfDaysInMonth(date.year, date.month);
}
bool isLastMonthInYear(stDate date)
{
    return date.month == 12;
}

int main()
{
    stDate date = readDate();

    if (isLastDayInMonth(date))
    {
        cout << "\nYes this is the last day in the month\n";
    }
    else
    {
        cout << "\nNo this is not the last day in the month\n";
    }

    if (isLastMonthInYear(date))
    {
        cout << "\nYes this is the last month in the year\n";
    }
    else
    {
        cout << "\nNo this is not the last month in the year\n";
    }

    return 0;
}