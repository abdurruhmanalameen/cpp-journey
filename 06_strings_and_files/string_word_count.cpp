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
int countStringWords(string txt)
{
    string delim = " ";
    short pos = 0;
    string word;
    int count = 0;

    cout << "Words of your string:\n";

    while ((pos = txt.find(delim)) != std::string::npos)
    {
        word = txt.substr(0, pos);

        if (word != "")
        {
            count++;
        }

        txt.erase(0, pos + delim.length());
    }

    if (txt != "")
    {
        count++;
    }

    return count;
}

int main()
{
    string txt = readString("Please enter your string: ");

    int count = countStringWords(txt);

    cout << "The number of words in your string is: " << count << endl;

    return 0;
}