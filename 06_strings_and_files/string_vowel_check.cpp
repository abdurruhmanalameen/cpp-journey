#include <iostream>
#include <string>
using namespace std;

char readChar(string message)
{
    char c;
    cout << message << endl;
    cin >> c;

    return c;
}
bool isVowelLetter(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
}
int main()
{
    char c = readChar("Enter a character: ");

    if (isVowelLetter(c))
    {
        cout << "Yes the letter is a vowel letter.\n";
    }
    else
    {
        cout << "No the letter isn't a vowel letter.\n";
    }
    return 0;
}