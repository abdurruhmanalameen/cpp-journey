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

string joinString(string arr[50], int arrLength, string delim)
{
    string s;

    for (int i = 0; i < arrLength; i++)
    {
        s += arr[i] + delim;
    }

    return s.substr(0, s.length() - delim.length());
}
int main()
{
    vector<string> vString = {"Khalid", "Ahmad", "Yassir"};

    string arr[50] = {"Obama", "Trump", "Abraham"};
    int arrLength = 3;

    cout << "Vector after joining:\n";
    cout << joinString(vString, "###") << endl;

    cout << "Array after joining:\n";
    cout << joinString(arr, arrLength, "***") << endl;

    return 0;
}