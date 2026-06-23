#include <iostream>
#include <iomanip>
using namespace std;

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
string getMonthName(int monthNumber)
{
    string monthsNames[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "sep", "Oct", "Nov", "Dec"};

    return monthsNames[monthNumber];
}
int getFirstDay(int year, int month)
{
    int day = 1;
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;
    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
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
void drawMonthCalender(int year, int month)
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
void drawYearCalender(int year)
{
    cout << "\n_______________________________________\n";
    cout << "            Calender - " << year << endl;
    cout << "_______________________________________\n";

    for (int i = 1; i < 13; i++)
    {
        drawMonthCalender(year, i);
    }
}
int main()
{
    int year = readYear();

    drawYearCalender(year);

    return 0;
}