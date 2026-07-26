#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
    string date;

    cout << "Please enter a date: ";
    getline(cin, date);

    return date;
}
struct stDate
{
    int day = 0;
    int month = 0;
    int year = 0;
};

vector<string> separateStringWords(string line, string delim)
{
    vector<string> vWords;
    short pos = 0;
    string word = "";

    while ((pos = line.find(delim)) != std::string::npos)
    {
        word = line.substr(0, pos);

        if (word != "")
        {
            vWords.push_back(word);
        }

        line.erase(0, pos + delim.length());
    }

    if (line != "")
    {
        vWords.push_back(line);
    }

    return vWords;
}
stDate convertStringToDate(string sDate)
{
    vector<string> vDate = separateStringWords(sDate, "/");
    stDate date;

    date.day = stoi(vDate[0]);
    date.month = stoi(vDate[1]);
    date.year = stoi(vDate[2]);

    return date;
}
string convertDateToString(stDate date)
{
    string sDate = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);

    return sDate;
}
int main()
{
    string txt = readString();
    stDate date = convertStringToDate(txt);
    string sDate = convertDateToString(date);

    cout << "\nA date format: " << date.day << "/" << date.month << "/" << date.year << endl;

    cout << "\nA string format: " << sDate << endl;

    return 0;
}