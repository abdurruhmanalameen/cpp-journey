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
void convertFirstLettersToLower(string &txt)
{
    bool isFirstLetter = true;

    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] != ' ' && isFirstLetter)
        {
            txt[i] = tolower(txt[i]);
        }
        isFirstLetter = (txt[i] == ' ' ? true : false);
    }
    cout << txt << endl;
}

int main()
{
    string txt = readString("Please enter your string: ");

    convertFirstLettersToLower(txt);

    return 0;
}