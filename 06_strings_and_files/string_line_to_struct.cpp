#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};
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
stClientData convertLineToRecord(string lineRecord, string delim = "#//#")
{
    stClientData clientData;
    vector<string> vString = separateStringWords(lineRecord, delim);

    clientData.accountNumber = vString[0];
    clientData.pinCode = vString[1];
    clientData.name = vString[2];
    clientData.phone = vString[3];
    clientData.accountBalance = stod(vString[4]);

    return clientData;
}
void printRecordInfo(stClientData clientData)
{
    cout << "Account Number: " << clientData.accountNumber << endl;
    cout << "PIN Code: " << clientData.pinCode << endl;
    cout << "Name: " << clientData.name << endl;
    cout << "Phone: " << clientData.phone << endl;
    cout << "Account Balance: " << clientData.accountBalance << endl;
}
int main()
{
    string lineRecord = "A158#//#1234#//#Abdurruhman Alameen#//#0911998844#//#503832.3";
    stClientData clientData = convertLineToRecord(lineRecord);
    printRecordInfo(clientData);

    return 0;
}