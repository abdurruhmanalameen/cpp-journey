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

string trimLeft(string txt)
{

    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] != ' ')
        {
            return txt.substr(i, txt.length() - i);
        }
    }

    return "";
}
string trimRight(string txt)
{
    for (int i = txt.length() - 1; i >= 0; i--)
    {
        if (txt[i] != ' ')
        {
            return txt.substr(0, i + 1);
        }
    }

    return "";
}

string trim(string txt)
{
    return trimLeft(trimRight(txt));
}

int main()
{
    // string txt = readString("Enter Your string: ");

    cout << "Left Trimmed text: [" << trimLeft("     Abdo") << "]\n";

    cout << "Right Trimmed text: [" << trimRight("Abdo     ") << "]\n";

    cout << "Full Trim: [" << trim("   Abdo   ") << "]\n";

    return 0;
}