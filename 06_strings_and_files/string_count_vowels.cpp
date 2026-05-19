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
bool isVowelLetter(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
}
int countVowel(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowelLetter(s[i]))
        {
            count++;
        }
    }

    return count;
}
int main()
{
    string s = readString("Enter a string: ");

    cout << "Number of vowels is: " << countVowel(s) << endl;

    return 0;
}