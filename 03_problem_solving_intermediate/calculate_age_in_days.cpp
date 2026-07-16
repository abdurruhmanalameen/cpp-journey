#pragma warning(disable : 4996)

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
int countDiffDaysInDates(stDate date1, stDate date2, bool includeEndDay = false)
{
    int days = 0;

    while (isDate1BeforeDate2(date1, date2))
    {
        date1 = addADayToDate(date1);
        days++;
    }

    return includeEndDay ? ++days : days;
}
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
int countAgeInDays(stDate birthDay, stDate currentDate)
{
    int days = countDiffDaysInDates(birthDay, currentDate);

    return days;
}
int main()
{
    stDate birthDay = readDate();
    stDate currentDate = getSystemDate();

    int ageInDays = countAgeInDays(birthDay, currentDate);

    cout << "Your age in days is " << ageInDays << " days\n";

    return 0;
}