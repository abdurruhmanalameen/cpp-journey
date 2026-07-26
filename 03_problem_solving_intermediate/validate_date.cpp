#include <iostream>
using namespace std;

int readDay()
{
    int day;

    cout << "\nEnter the day: ";
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
bool dateValidation(stDate date)
{
    if (date.month >= 1 && date.month <= 12)
    {
        if (date.day >= 1 && date.day <= numberOfDaysInMonth(date.year, date.month))
        {
            return true;
        }
    }

    return false;
}
int main()
{

    stDate date = readDate();
    bool isValidDate = dateValidation(date);

    if (isValidDate)
    {
        cout << "\nDate is valid\n";
    }
    else
    {
        cout << "\nDate is invalid\n";
    }

    return 0;
}