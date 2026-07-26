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
bool checkDateWithinAPeriod(stDatePeriod period, stDate date)
{
    if (isDate1BeforeDate2(period.startDate, date) && isDate1BeforeDate2(date, period.endDate))
    {
        return true;
    }

    return false;
}

int main()
{

    cout << "Enter period\n";
    cout << "Enter start date\n";
    stDatePeriod period;
    period.startDate = readDate();

    cout << "\nEnter end date\n";
    period.endDate = readDate();

    cout << "\nEnter a date to check:\n";
    stDate date = readDate();

    if (checkDateWithinAPeriod(period, date))
    {
        cout << "\nYes the date within the period\n";
    }
    else
    {
        cout << "\nNo the date is not within the period\n";
    }

    return 0;
}