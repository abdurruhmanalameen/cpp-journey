#include <iostream>
using namespace std;

// #41
float readPositiveNumber(string message)
{
    float number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}
float hoursToDays(float numberOfHours)
{
    return numberOfHours / 24;
}
float hoursToWeeks(float numberOfHours)
{
    return numberOfHours / 7 / 24;
}
float daysToWeeks(float numberOfDays)
{
    return numberOfDays / 7;
}
// #42
struct stTaskDuration
{
    int days, hours, minutes, seconds;
};
stTaskDuration readTaskDuration()
{
    stTaskDuration taskDuration;
    taskDuration.days = readPositiveNumber("Enter total days: ");
    taskDuration.hours = readPositiveNumber("Enter total hours: ");
    taskDuration.minutes = readPositiveNumber("Enter total minutes: ");
    taskDuration.seconds = readPositiveNumber("Enter total seconds: ");

    return taskDuration;
}
int taskDurationInSeconds(stTaskDuration taskDuration)
{
    int totalTaskDurationInSeconds = taskDuration.days * 24 * 60 * 60 + taskDuration.hours * 60 * 60 + taskDuration.minutes * 60 + taskDuration.seconds;

    return totalTaskDurationInSeconds;
}
// #43
struct strTaskDuration
{
    int numberOfDays, numberOfHours, numberOfMinutes, numberOfSeconds;
};
strTaskDuration secondsToTaskDuration(int totalSeconds)
{
    strTaskDuration taskDuration;
    const int secondsPerDay = 24 * 60 * 60;
    const int secondsPerHour = 60 * 60;
    const int secondsPerMinute = 60;

    taskDuration.numberOfDays = totalSeconds / secondsPerDay;
    int remainder = totalSeconds % secondsPerDay;
    taskDuration.numberOfHours = remainder / secondsPerHour;
    remainder = remainder % secondsPerHour;
    taskDuration.numberOfMinutes = remainder / secondsPerMinute;
    remainder = remainder % secondsPerMinute;
    taskDuration.numberOfSeconds = remainder;

    return taskDuration;
}
void printTaskDuration(strTaskDuration taskDuration)
{
    cout << "Task Duration = " << "\n"
         << taskDuration.numberOfDays << ":"
         << taskDuration.numberOfHours << ":"
         << taskDuration.numberOfMinutes << ":"
         << taskDuration.numberOfSeconds << "\n";
}
// #44
enum enDayOfWeek
{
    sat = 1,
    sun,
    mon,
    tue,
    wed,
    thu,
    fri
};
int readNumberInRange(string message, int from, int to)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < from || number > to);

    return number;
}
enDayOfWeek readDayOfWeek()
{
    return (enDayOfWeek)readNumberInRange("choose a day between 1 & 7: ", 1, 7);
}
string getDayOfWeek(enDayOfWeek day)
{
    switch (day)
    {
    case enDayOfWeek::sat:
        return "Saturday";
    case enDayOfWeek::sun:
        return "Sunday";
    case enDayOfWeek::mon:
        return "Monday";
    case enDayOfWeek::tue:
        return "Tuesday";
    case enDayOfWeek::wed:
        return "Wednsday";
    case enDayOfWeek::thu:
        return "Thursday";
    case enDayOfWeek::fri:
        return "Friday";
    default:
        return "Wrong day!";
    }
}
// #44
enum enMonthsOfYear
{
    Jan = 1,
    Feb,
    Mar,
    Abr,
    May,
    Jun,
    Jul,
    Aug,
    Seb,
    Oct,
    Nov,
    Dec
};
enMonthsOfYear readMonthOfYear()
{
    return (enMonthsOfYear)readNumberInRange("choose a month between 1 & 12: ", 1, 12);
}
string getMonthOfYear(enMonthsOfYear Month)
{
    switch (Month)
    {
    case enMonthsOfYear::Jan:
        return "January";
    case enMonthsOfYear::Feb:
        return "Feberuary";
    case enMonthsOfYear::Mar:
        return "Mars";
    case enMonthsOfYear::Abr:
        return "Abril";  
    case enMonthsOfYear::May:
        return "May"; 
    case enMonthsOfYear::Jun:
        return "June"; 
    case enMonthsOfYear::Jul:
        return "July";
    case enMonthsOfYear::Aug:
        return "August";
    case enMonthsOfYear::Seb:
        return "September";
    case enMonthsOfYear::Oct:
        return "October";
    case enMonthsOfYear::Nov:
        return "November";
    case enMonthsOfYear::Dec:
        return "December";
    default:
        return "Wrong Month!";
    }
}

int main()
{
    // #41
    /*float totalHours = readPositiveNumber("Enter total Hours: ");
    float totalDays = hoursToDays(totalHours);
    float totalWeeks = hoursToWeeks(totalHours);

    cout << "Total Hours = " << totalHours << endl;
    cout << "Total Days = " << totalDays << endl;
    cout << "Total Weeks = " << totalWeeks << endl;
    cout << "Total Weeks 2 = " << daysToWeeks(14) << endl;*/
    // #42
    /*int taskDurationInSecond = taskDurationInSeconds(readTaskDuration());
    cout << endl << "Task duration in seconds: " << taskDurationInSecond << endl;*/
    // #43
    /*int totalSeconds = (int)readPositiveNumber("Enter total seconds: ");
    printTaskDuration(secondsToTaskDuration(totalSeconds));*/
    // #44
    // cout << getDayOfWeek(readDayOfWeek()) << endl;
    // #45
    cout << getMonthOfYear(readMonthOfYear()) << endl;
    return 0;
}