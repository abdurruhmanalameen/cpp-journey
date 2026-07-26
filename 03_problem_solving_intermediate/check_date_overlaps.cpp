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
bool isDate1EqualDate2(stDate date1, stDate date2)
{
    return date1.year == date2.year ? date1.month == date2.month ? date1.day == date2.day : false : false;
}
bool isDate1BeforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : (date1.year == date2.year) ? (date1.month < date2.month) ? true : (date1.month == date2.month) ? (date1.day < date2.day)
                                                                                                                                             : false
                                                                         : false;
}
bool isDate1AfterDate2(stDate date1, stDate date2)
{
    return (!isDate1BeforeDate2(date1, date2) && (!isDate1EqualDate2(date1, date2)));
}
enCompare compareDates(stDate date1, stDate date2)
{
    if (isDate1BeforeDate2(date1, date2))
    {
        return enCompare::before;
    }
    else if (isDate1EqualDate2(date1, date2))
    {
        return enCompare::equal;
    }
    else
    {
        return enCompare::after;
    }
}
bool checkDatesOverlaps(stDatePeriod period1, stDatePeriod period2)
{
    if (compareDates(period2.startDate, period1.endDate) == enCompare::after || compareDates(period2.endDate, period1.startDate) == enCompare::before)
    {
        return false;
    }

    return true;
}
int main()
{

    cout << "Enter period 1\n";
    cout << "Enter start date\n";
    stDatePeriod period1;
    period1.startDate = readDate();

    cout << "\nEnter end date\n";
    period1.endDate = readDate();

    cout << "\n\nEnter period 2\n";
    cout << "Enter start date\n";
    stDatePeriod period2;
    period2.startDate = readDate();

    cout << "\nEnter end date\n";
    period2.endDate = readDate();

    if (checkDatesOverlaps(period1, period2))
    {
        cout << "\nYes periods overlap\n";
    }
    else
    {
        cout << "\nNo periods don't overlap\n";
    }

    return 0;
}