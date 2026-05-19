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
int countLetter(string s, char c)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }

    return count;
}
int main()
{
    string s = readString("Enter a string: ");
    char c = readChar("Enter a character: ");

    cout << "Letter " << c << " count = " << countLetter(s, c) << endl;

    return 0;
}