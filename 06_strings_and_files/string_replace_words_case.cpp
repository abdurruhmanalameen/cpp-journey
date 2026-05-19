#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString(string message)
{
    string txt;
    cout << message << endl;
    getline(cin, txt);

    return txt;
}
vector<string> separateStringWords(string txt, string delim)
{
    vector<string> vWords;
    short pos = 0;
    string word;

    while ((pos = txt.find(delim)) != std::string::npos)
    {
        word = txt.substr(0, pos);

        if (word != "")
        {
            vWords.push_back(word);
        }

        txt.erase(0, pos + delim.length());
    }

    if (txt != "")
    {
        vWords.push_back(txt);
    }

    return vWords;
}
string trimRight(string txt)
{
    for (int i = txt.length() - 1; i >= 0; i--)
    {
        if (txt[i] != ' ')
        {
            // abody     .
            return txt.substr(0, i + 1);
        }
    }

    return "";
}
string convertAllLettersToLower(string txt)
{
    for (int i = 0; i < txt.length(); i++)
    {
        txt[i] = tolower(txt[i]);
    }

    return txt;
}
string replaceWords(string txt, string toReplace, string replaceTo, bool isMatchCase)
{
    string txt2 = "";
    vector<string> vString = separateStringWords(txt, " ");

    for (string &i : vString)
    {
        if (isMatchCase)
        {
            if (i == toReplace)
            {
                i = replaceTo;
            }
        }
        else
        {
            if (convertAllLettersToLower(i) == convertAllLettersToLower(toReplace))
            {
                i = replaceTo;
            }
        }
        txt2 += i + " ";
    }

    return trimRight(txt2);
}

int main()
{
    string txt = "Jordan is a nice country, Welcome to Jordan";
    cout << "The string: " << txt << endl;

    string toReplace = readString("What do you want to replace? ");
    string replaceTo = readString("To what you want to replace it?: ");
    cout << "Do you want it to be match cases? [1]Yes [0]No" << endl;
    bool matchCases;
    cin >> matchCases;

    cout << endl
         << "The replaced string: " << endl
         << replaceWords(txt, toReplace, replaceTo, matchCases) << endl;

    return 0;
}