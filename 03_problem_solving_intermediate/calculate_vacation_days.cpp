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
short getOrderOfDay(stDate date)
{
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + (12 * a) - 2;
    int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}
string getDayName(stDate date)
{
    short dayNumber = getOrderOfDay(date);

    string daysNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return daysNames[dayNumber];
}
bool isBusinessDay(stDate date)
{
    short dayOrder = getOrderOfDay(date);

    if (dayOrder == 6 || dayOrder == 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

short countVacationDays(stDate date1, stDate date2)
{
    short daysCounter = 0;

    while (isDate1BeforeDate2(date1, date2))
    {
        if (isBusinessDay(date1))
        {
            daysCounter++;
        }

        date1 = addADayToDate(date1);
    }

    return daysCounter;
}

int main()
{
    cout << "Vacation starts:";
    stDate date1 = readDate();

    cout << "\nVacation ends:";
    stDate date2 = readDate();

    cout << "\nVacation from: " << getDayName(date1) << ", " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    cout << "Vacation to: " << getDayName(date2) << ", " << date2.day << "/" << date2.month << "/" << date2.year << endl;

    cout << "\n\nActual Vacation days is: " << countVacationDays(date1, date2) << endl;

    return 0;
}