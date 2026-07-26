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
enum enCompare
{
    before = -1,
    equal = 0,
    after = 1
};
struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};
struct stDatePeriod
{
    stDate startDate;
    stDate endDate;
};
stDate readDate()
{
    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
}
bool isDate1BeforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : (date1.year == date2.year) ? (date1.month < date2.month) ? true : (date1.month == date2.month) ? (date1.day < date2.day)
                                                                                                                                             : false
                                                                         : false;
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
int calculatePeriodDays(stDatePeriod period, bool includingEndDay = false)
{
    int counter = 0;

    while (isDate1BeforeDate2(period.startDate, period.endDate))
    {
        period.startDate = addADayToDate(period.startDate);
        counter++;
    }

    if (includingEndDay)
    {
        counter++;
    }

    return counter;
}

int main()
{

    cout << "Enter period\n";
    cout << "Enter start date\n";
    stDatePeriod period;
    period.startDate = readDate();

    cout << "\nEnter end date\n";
    period.endDate = readDate();

    cout << "\nPeriod length is: " << calculatePeriodDays(period) << endl;
    cout << "Period length (including end day) is: " << calculatePeriodDays(period, true) << endl;

    return 0;
}