#include <iostream>
#include <string>
using namespace std;

string readString(string message)
{
    string s;
    cout << message << endl;
    getline(cin, s);

    return s;
}
char invertChar(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
string invertString(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = invertChar(s[i]);
    }

    return s;
}
int main()
{
    string s = readString("Enter a string: ");

    cout << endl
         << invertString(s) << endl;

    return 0;
}