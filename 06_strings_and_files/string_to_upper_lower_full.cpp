#include <iostream>
#include <string>
using namespace std;

string readString(string message)
{
    string txt;
    cout << message << endl;
    getline(cin, txt);

    return txt;
}
void convertAllLettersToLower(string &txt)
{
    string upperTxt = txt;

    for (int i = 0; i < txt.length(); i++)
    {
        txt[i] = tolower(txt[i]);
    }
}
void convertAllLettersToUpper(string &txt)
{
    string upperTxt = txt;

    for (int i = 0; i < txt.length(); i++)
    {
        txt[i] = toupper(txt[i]);
    }
}
int main()
{
    string txt = readString("Please enter your string: ");

    convertAllLettersToUpper(txt);
    cout << "Upper string: " << txt << endl;

    convertAllLettersToLower(txt);
    cout << "Lower string: " << txt << endl;

    return 0;
}