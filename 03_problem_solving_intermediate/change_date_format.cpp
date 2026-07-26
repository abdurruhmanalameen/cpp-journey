#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString()
{
    string date;

    cout << "Please enter a date dd/mm/yyyy? ";
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
string replaceWordsBuildFunction(string txt, string toReplace, string replaceTo)
{
    short pos = txt.find(toReplace);

    while (pos != std::string::npos)
    {
        txt = txt.replace(pos, toReplace.length(), replaceTo);
        pos = txt.find(toReplace);
    }

    return txt;
}
void printDifferentFormatsOfDate(stDate date, string format)
{
    format = replaceWordsBuildFunction(format, "dd", to_string(date.day));
    format = replaceWordsBuildFunction(format, "mm", to_string(date.month));
    format = replaceWordsBuildFunction(format, "yyyy", to_string(date.year));

    cout << endl
         << format << endl;
}

int main()
{
    string txt = readString();
    stDate date = convertStringToDate(txt);

    printDifferentFormatsOfDate(date, "dd/mm/yyyy");
    printDifferentFormatsOfDate(date, "mm/dd/yyyy");
    printDifferentFormatsOfDate(date, "yyyy/mm/yyyy");
    printDifferentFormatsOfDate(date, "dd-mm-yyyy");
    printDifferentFormatsOfDate(date, "Day:dd, Month:mm, Year:yyyy");

    return 0;
}