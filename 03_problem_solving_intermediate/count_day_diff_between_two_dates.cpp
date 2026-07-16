#include <iostream>
#include <cmath>
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
stDate addADayToDate(stDate date)
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
bool isDate1BeforeDate2(stDate dateOne, stDate dateTwo)
{
    return (dateOne.year < dateTwo.year) ? true : (dateOne.year == dateTwo.year) ? (dateOne.month < dateTwo.month) ? true : (dateOne.month == dateTwo.month) ? (dateOne.day < dateTwo.day)
                                                                                                                                                             : false
                                                                                 : false;
}
void swapDates(stDate &date1, stDate &date2)
{
    stDate tempDate;

    tempDate.day = date1.day;
    tempDate.month = date1.month;
    tempDate.year = date1.year;

    date1.day = date2.day;
    date1.month = date2.month;
    date1.year = date2.year;

    date2.day = tempDate.day;
    date2.month = tempDate.month;
    date2.year = tempDate.year;
}
int countDiffDaysInDates(stDate date1, stDate date2, bool includeEndDay = false)
{
    int days = 0;
    short flagSwap = 1;

    if (!isDate1BeforeDate2(date1, date2))
    {
        swapDates(date1, date2);
        flagSwap = -1;
    }

    while (isDate1BeforeDate2(date1, date2))
    {
        date1 = addADayToDate(date1);
        days++;
    }

    return includeEndDay ? ++days * flagSwap : days * flagSwap;
}
int main()
{
    stDate date1 = readDate();
    stDate date2 = readDate();

    cout << "\nDifference is: " << countDiffDaysInDates(date1, date2) << " day(s)\n";
    cout << "Difference (including end day) is: " << countDiffDaysInDates(date1, date2, true) << " day(s)\n";

    return 0;
}