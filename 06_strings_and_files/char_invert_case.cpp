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
char invertChar(char c)
{
    return isupper(c) ? tolower(c) : toupper(c);
}
int main()
{
    char c = readChar("Enter a char: ");
    cout << invertChar(c) << endl;

    return 0;
}