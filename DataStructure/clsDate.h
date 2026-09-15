#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
// #include "clsString.h"
#include <ctime>
#include <chrono>
using namespace std;

class clsDate
{
private:
    int _day = 1;
    int _month = 1;
    int _year = 2026;

public:
    static bool checkLeapYearOrNot(int year)
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
    static int numberOfDaysInMonth(int year, int month)
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
    static int numberOfDaysInYear(int year)
    {
        return (checkLeapYearOrNot(year) ? 366 : 365);
    }
    static int getDayOrderInYear(int day, int month, int year)
    {
        int daysInYear = numberOfDaysInYear(year);
        int orderOfTheDay = 0;

        for (int i = 1; i < month; i++)
        {
            orderOfTheDay += numberOfDaysInMonth(year, i);
        }

        orderOfTheDay += day;

        return orderOfTheDay;
    }
    clsDate()
    {
        time_t t = time(0);
        tm *now = localtime(&t);

        _year = now->tm_year + 1900;
        _month = now->tm_mon + 1;
        _day = now->tm_mday;
    }
    clsDate(int day, int month, int year)
    {
        _day = day;
        _month = month;
        _year = year;
    }
    clsDate(int orderOfDay, int year)
    {
        *this = GetDateFromDayOrderInYear(orderOfDay, year);
    }

    bool checkLeapYearOrNot()
    {
        return checkLeapYearOrNot(_year);
    }
    static string getMonthName(int monthNumber)
    {
        string monthsNames[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "sep", "Oct", "Nov", "Dec"};

        return monthsNames[monthNumber];
    }
    static int getFirstDay(int year, int month)
    {
        int day = 1;
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + (12 * a) - 2;
        int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }
    int getFirstDay()
    {
        return getFirstDay(_year, _month);
    }
    int numberOfDaysInMonth()
    {
        return numberOfDaysInMonth(_year, _month);
    }
    static void drawMonthCalender(int year, int month)
    {
        int daysInMonth = numberOfDaysInMonth(year, month);
        int firstDay = getFirstDay(year, month);

        cout << "__________________" << getMonthName(month) << "__________________\n\n";
        cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat\n";

        for (int j = 0; j < firstDay; j++)
        {
            cout << "      ";
        }
        for (int i = 1; i <= daysInMonth; i++)
        {
            cout << setw(3) << i << "   ";
            if ((i + firstDay) % 7 == 0)
            {
                cout << "\n";
            }
        }

        cout << "\n_______________________________________\n\n";
    }
    void drawMonthCalender()
    {
        drawMonthCalender(_year, _month);
    }
    int numberOfDaysInYear()
    {
        return numberOfDaysInYear(_year);
    }
    int getDayOrderInYear()
    {
        return getDayOrderInYear(_day, _month, _year);
    }
    static clsDate addDaysToTheDate(int addedDays, clsDate &date)
    {
        int RemainingDays = addedDays + getDayOrderInYear(date._day, date._month, date._year);
        short MonthDays = 0;

        date._month = 1;

        while (true)
        {
            MonthDays = numberOfDaysInMonth(date._year, date._month);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                date._month++;

                if (date._month > 12)
                {
                    date._month = 1;
                    date._year++;
                }
            }
            else
            {
                date._day = RemainingDays;
                break;
            }
        }

        return date;
    }
    void addDaysToTheDate(int addedDays)
    {
        addDaysToTheDate(addedDays, *this);
    }
    static bool isLastDayInMonth(clsDate date)
    {
        return date._day == numberOfDaysInMonth(date._year, date._month);
    }
    bool isLastDayInMonth()
    {
        return isLastDayInMonth(*this);
    }
    static bool isLastMonthInYear(clsDate date)
    {
        return date._month == 12;
    }
    bool isLastMonthInYear()
    {
        return isLastMonthInYear(*this);
    }
    static clsDate addADayToDate(clsDate &date)
    {
        if (isLastDayInMonth(date))
        {
            if (isLastMonthInYear(date))
            {
                date._year++;
                date._month = 1;
                date._day = 1;
            }
            else
            {
                date._month++;
                date._day = 1;
            }
        }
        else
        {
            date._day++;
        }

        return date;
    }
    void addADayToDate()
    {
        addADayToDate(*this);
    }
    enum enCompare
    {
        before = -1,
        equal = 0,
        after = 1
    };
    static enCompare compareDates(clsDate date1, clsDate date2)
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
    static bool isDate1AfterDate2(clsDate date1, clsDate date2)
    {
        return (!isDate1BeforeDate2(date1, date2) && (!isDate1EqualDate2(date1, date2)));
    }
    bool isDate1AfterDate2(clsDate date2)
    {
        return isDate1AfterDate2(*this, date2);
    }
    static bool isDate1BeforeDate2(clsDate dateOne, clsDate dateTwo)
    {
        return (dateOne._year < dateTwo._year) ? true : (dateOne._year == dateTwo._year) ? (dateOne._month < dateTwo._month) ? true : (dateOne._month == dateTwo._month) ? (dateOne._day < dateTwo._day)
                                                                                                                                                                         : false
                                                                                         : false;
    }
    bool isDate1BeforeDate2(clsDate date2)
    {
        return isDate1BeforeDate2(*this, date2);
    }
    static int countDiffDaysInDates(clsDate date1, clsDate date2, bool includeEndDay = false)
    {
        int days = 0;

        while (isDate1BeforeDate2(date1, date2))
        {
            date1 = addADayToDate(date1);
            days++;
        }

        return includeEndDay ? ++days : days;
    }
    int countDiffDaysInDates(clsDate date2, bool includeEndDay = false)
    {
        return countDiffDaysInDates(*this, date2, includeEndDay);
    }
    static clsDate getSystemDate()
    {
        clsDate date;
        time_t t = time(0);
        tm *now = localtime(&t);

        date._year = now->tm_year + 1900;
        date._month = now->tm_mon + 1;
        date._day = now->tm_mday;

        return date;
    }
    static int countAgeInDays(clsDate birthday)
    {
        clsDate currentDate = getSystemDate();
        int days = countDiffDaysInDates(birthday, currentDate);

        return days;
    }
    static short getOrderOfDay(clsDate date)
    {
        int a = (14 - date._month) / 12;
        int y = date._year - a;
        int m = date._month + (12 * a) - 2;
        int d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }
    short getOrderOfDay()
    {
        return getOrderOfDay(*this);
    }
    static string getDayName(clsDate date)
    {
        short dayNumber = getOrderOfDay(date);

        string daysNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

        return daysNames[dayNumber];
    }
    string getDayName()
    {
        return getDayName(*this);
    }
    static bool isBusinessDay(clsDate date)
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
    bool isBusinessDay()
    {
        return isBusinessDay(*this);
    }
    static bool isWeekEnd(clsDate date)
    {
        short dayOrder = getOrderOfDay(date);

        if (dayOrder == 6 || dayOrder == 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isWeekEnd()
    {
        return isWeekEnd(*this);
    }
    static clsDate returnDateFromVacation(clsDate date, short vacationDays)
    {
        for (int i = 0; i < vacationDays; i++)
        {
            if (isWeekEnd(date))
            {
                vacationDays++;
            }

            date = addADayToDate(date);
        }

        return date;
    }
    clsDate returnDateFromVacation(short vacationDays)
    {
        return returnDateFromVacation(*this, vacationDays);
    }
    static short countVacationDays(clsDate date1, clsDate date2)
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
    short countVacationDays(clsDate date2)
    {
        return countVacationDays(*this, date2);
    }
    static string replaceWordsBuildFunction(string txt, string toReplace, string replaceTo)
    {
        short pos = txt.find(toReplace);

        while (pos != std::string::npos)
        {
            txt = txt.replace(pos, toReplace.length(), replaceTo);
            pos = txt.find(toReplace);
        }

        return txt;
    }
    static void printDifferentFormatsOfDate(clsDate date, string format)
    {
        format = replaceWordsBuildFunction(format, "dd", to_string(date._day));
        format = replaceWordsBuildFunction(format, "mm", to_string(date._month));
        format = replaceWordsBuildFunction(format, "yyyy", to_string(date._year));

        cout << endl
             << format << endl;
    }
    static string printCurrentTime()
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        stringstream ss;
        ss << put_time(localtime(&currentTime), "%H:%M:%S");

        return ss.str();
    }
    static void print(clsDate date)
    {
        cout << date._day << "/" << date._month << "/" << date._year;
    }
    void print()
    {
        print(*this);
    }
    void printDifferentFormatsOfDate(string format)
    {
        printDifferentFormatsOfDate(*this, format);
    }
    static string convertDateToString(clsDate date)
    {
        string sDate = to_string(date._day) + "/" + to_string(date._month) + "/" + to_string(date._year);

        return sDate;
    }
    string convertDateToString()
    {
        return convertDateToString(*this);
    }
    static int numberOfHoursInMonth(int year, int month)
    {
        return (24 * numberOfDaysInMonth(year, month));
    }
    int numberOfHoursInMonth()
    {
        return numberOfHoursInMonth(_year, _month);
    }
    static int numberOfMinutesInMonth(int year, int month)
    {
        return (60 * numberOfHoursInMonth(year, month));
    }
    int numberOfMinutesInMonth()
    {
        return numberOfMinutesInMonth(_year, _month);
    }
    static int numberOfSecondsInMonth(int year, int month)
    {
        return (60 * numberOfMinutesInMonth(year, month));
    }
    int numberOfSecondsInMonth()
    {
        return numberOfSecondsInMonth(_year, _month);
    }
    static bool isDate1EqualDate2(clsDate dateOne, clsDate dateTwo)
    {
        return dateOne._year == dateTwo._year ? dateOne._month == dateTwo._month ? dateOne._day == dateTwo._day : false : false;
    }
    bool isDate1EqualDate2(clsDate date2)
    {
        return isDate1EqualDate2(*this, date2);
    }
    static void drawYearCalender(int year)
    {
        cout << "\n_______________________________________\n";
        cout << "            Calender - " << year << endl;
        cout << "_______________________________________\n";

        for (int i = 1; i < 13; i++)
        {
            drawMonthCalender(year, i);
        }
    }
    void drawYearCalender()
    {
        drawYearCalender(_year);
    }
    static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
    {
        clsDate Date;
        short RemainingDays = DayOrderInYear;
        short MonthDays = 0;
        Date._year = Year;
        Date._month = 1;

        while (true)
        {
            MonthDays = numberOfDaysInMonth(Year, Date._month);

            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date._month++;
            }
            else
            {
                Date._day = RemainingDays;
                break;
            }
        }

        return Date;
    }
    clsDate GetDateFromDayOrderInYear()
    {
        short dayOrderInYear = getDayOrderInYear(_day, _month, _year);

        return GetDateFromDayOrderInYear(dayOrderInYear, _year);
    }
    static bool dateValidation(clsDate date)
    {
        if (date._month >= 1 && date._month <= 12)
        {
            if (date._day >= 1 && date._day <= numberOfDaysInMonth(date._year, date._month))
            {
                return true;
            }
        }

        return false;
    }
    bool dateValidation()
    {
        return dateValidation(*this);
    }
    static void swapDates(clsDate &date1, clsDate &date2)
    {
        clsDate tempDate;

        tempDate._day = date1._day;
        tempDate._month = date1._month;
        tempDate._year = date1._year;

        date1._day = date2._day;
        date1._month = date2._month;
        date1._year = date2._year;

        date2._day = tempDate._day;
        date2._month = tempDate._month;
        date2._year = tempDate._year;
    }
};