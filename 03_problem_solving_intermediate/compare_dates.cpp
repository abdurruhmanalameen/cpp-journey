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
short readVacationDays()
{
    short vacationDays;

    cout << "\nEnter vacation days: ";
    cin >> vacationDays;

    return vacationDays;
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
int main()
{
    cout << "Enter date1: ";
    stDate date1 = readDate();
    cout << "\nEnter date2: ";
    stDate date2 = readDate();

    enCompare compare = compareDates(date1, date2);

    cout << "Compare Result = " << compare << endl;

    return 0;
}