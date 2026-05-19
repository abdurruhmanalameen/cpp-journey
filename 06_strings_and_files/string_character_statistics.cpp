#include <iostream>
#include <string>
using namespace std;

struct stStringInfo
{
    int stringLength = 0;
    int smallLetter = 0;
    int capitalLetter = 0;
};

string readString(string message)
{
    string s;
    cout << message << endl;
    getline(cin, s);

    return s;
}
stStringInfo fillStringInfo(string s)
{
    stStringInfo letterInfo;
    letterInfo.stringLength = s.length();

    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            letterInfo.capitalLetter++;
        }
        else
        {
            if (s[i] != ' ')
            {
                letterInfo.smallLetter++;
            }
        }
    }

    return letterInfo;
}
void printStringInfo(stStringInfo stringInfo)
{
    cout << "String length: " << stringInfo.stringLength << endl;
    cout << "Capital letters count: " << stringInfo.capitalLetter << endl;
    cout << "Small letters count: " << stringInfo.smallLetter << endl;
}
int main()
{
    string s = readString("Enter a string: ");

    printStringInfo(fillStringInfo(s));

    return 0;
}