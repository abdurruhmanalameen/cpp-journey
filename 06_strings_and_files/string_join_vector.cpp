#include <iostream>
#include <vector>
#include <string>
using namespace std;

string joinString(vector<string> vString, string delim)
{
    string s;

    for (string &i : vString)
    {
        s += i + delim;
    }

    return s.substr(0, s.length() - delim.length());
}
int main()
{
    vector<string> vString = {"Khalid", "Ahmad", "Yassir"};

    cout << "Vector after joining:\n";
    cout << joinString(vString, "-") << endl;

    return 0;
}