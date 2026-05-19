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
string trimRight(string txt)
{
    for (int i = txt.length() - 1; i >= 0; i--)
    {
        if (txt[i] != ' ')
        {
            // abody     .
            return txt.substr(0, i + 1);
        }
    }

    return "";
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
string reverseWordsInString(string txt)
{
    string reversedS = "";
    vector<string> vString = separateStringWords(txt, " ");
    vector<string>::iterator iter = vString.end();

    while (iter != vString.begin())
    {
        iter--;
        reversedS += *iter + " ";
    }

    return trimRight(reversedS);
}
int main()
{
    string s = "Abdurruhman Alameen Abody";

    cout << "String: " << s << endl;
    cout << "Reversed String: " << endl
         << reverseWordsInString(s) << endl;

    return 0;
}