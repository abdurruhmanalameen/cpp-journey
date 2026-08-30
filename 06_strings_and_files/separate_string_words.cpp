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
void separateStringWords(string txt)
{
    string delim = " ";
    short pos = 0;
    string word;

    cout << "Words of your string:\n";

    while ((pos = txt.find(delim)) != std::string::npos)
    {
        word = txt.substr(0, pos);

        if (word != "")
        {
            cout << word << endl;
        }

        txt.erase(0, pos + delim.length());
    }

    if (txt != "")
    {
        cout << txt << endl;
    }
}

int main()
{
    string txt = readString("Please enter your string: ");

    separateStringWords(txt);

    return 0;
}