#include <iostream>
#include <string>
#include <vector>
using namespace std;

string readString(string message)
{
    string txt;
    cout << message << endl;
    getline(cin, txt);

    return txt;
}

string deletePunctuation(string txt)
{
    string txt2 = "";
    for (int i = 0; i < txt.length(); i++)
    {
        if (!ispunct(txt[i]))
        {
            txt2 += txt[i];
        }
    }

    return txt2;
}

int main()
{
    string txt = readString("Enter a string: ");
    cout << "The string: " << txt << endl;

    cout << "The deleted punct text: " << deletePunctuation(txt) << endl;

    return 0;
}