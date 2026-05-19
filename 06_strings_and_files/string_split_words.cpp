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
vector<string> separateStringWords(string txt, string delim)
{
    vector<string> vWords;
    short pos = 0;
    string word;

    while ((pos = txt.find(delim)) != std::string::npos)
    {
        word = txt.substr(0, pos);

        if (word != "")
        {
            vWords.push_back(word);
        }

        txt.erase(0, pos + delim.length());
    }

    if (txt != "")
    {
        vWords.push_back(txt);
    }

    return vWords;
}

int main()
{
    string txt = readString("Please enter your string: ");
    vector<string> vWords = separateStringWords(txt, " ");

    cout << "Tokens = " << vWords.size() << endl;
    for (string &i : vWords)
    {
        cout << i << endl;
    }

    return 0;
}