#include <iostream>
using namespace std;

struct stDate
{
    short day;
    short month;
    short year;
};
stDate readDate()
{
    stDate date;

    cout << "\nEnter the day: ";
    cin >> date.day;

    cout << "Enter the month: ";
    cin >> date.month;

    cout << "Enter the year: ";
    cin >> date.year;

    return date;
}
bool isDate1BeforeDate2(stDate dateOne, stDate dateTwo)
{
    return (dateOne.year < dateTwo.year) ? true : (dateOne.year == dateTwo.year) ? (dateOne.month < dateTwo.month) ? true : (dateOne.month == dateTwo.month) ? (dateOne.day < dateTwo.day)
                                                                                                                                                             : false
                                                                                 : false;
}
int main()
{
    stDate dateOne = readDate();
    stDate dateTwo = readDate();

    if (isDate1BeforeDate2(dateOne, dateTwo))
    {
        cout << "\nYes date 1 is before date 2\n";
    }
    else
    {
        cout << "\nNo date 1 is not before date 2\n";
    }

    return 0;
}