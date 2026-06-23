#include <iostream>
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
int readDay()
{
    int day;

    cout << "Enter the day: ";
    cin >> day;

    return day;
}
string getDayName(int dayNumber)
{
    string daysNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return daysNames[dayNumber];
}
void getNameOfDay(int year, int month, int day)
{
    cout << "Date: " << day << "/" << month << "/" << year << endl;
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;
    int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    cout << "Day order: " << d << endl;
    cout << "Day name: " << getDayName(d) << endl;
}

int main()
{
    int year = readYear();
    int month = readMonth();
    int day = readDay();

    getNameOfDay(year, month, day);

    return 0;
}