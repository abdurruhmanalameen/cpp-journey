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
void getFirstLettersOfString(string txt)
{
    bool isFirstLetter = true;

    for (int i = 0; i < txt.length(); i++)
    {
        if (txt.at(i) != ' ' && isFirstLetter)
        {
            cout << txt.at(i) << endl;
        }
        isFirstLetter = (txt.at(i) == ' ' ? true : false);
    }
}

int main()
{
    string txt = readString("Please enter your string: ");

    getFirstLettersOfString(txt);

    return 0;
}