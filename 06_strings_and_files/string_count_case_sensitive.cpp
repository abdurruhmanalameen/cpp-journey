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
char readChar(string message)
{
    char c;
    cout << message << endl;
    cin >> c;

    return c;
}
char invertChar(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
int CounterLetter(string s, char c, bool matchCase = true)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (matchCase)
        {
            if (s[i] == c)
            {
                count++;
            }
        }
        else
        {
            if (tolower(s[i]) == tolower(c))
            {
                count++;
            }
        }
    }

    return count;
}
int main()
{
    string s = readString("Enter a string: ");
    char c = readChar("Enter a character: ");

    cout << "Letter " << c << " count = " << CounterLetter(s, c) << endl;
    cout << "Letter " << c << " or " << invertChar(c) << " count = " << CounterLetter(s, c, false) << endl;

    return 0;
}