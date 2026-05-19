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

stClientData readClientData()
{
    stClientData clientData;
    cout << "Please enter client data\n\n";

    cout << "Enter account number: ";
    cin >> clientData.accountNumber;

    cout << "Enter PIN code: ";
    cin >> clientData.pinCode;

    cout << "Enter name: ";
    cin >> clientData.name;

    cout << "Enter account balance: ";
    cin >> clientData.accountBalance;

    return clientData;
}
string convertRecordToLine(stClientData clientData, string delim = "***")
{
    string oneLine = "";

    oneLine += clientData.accountNumber + delim;
    oneLine += clientData.pinCode + delim;
    oneLine += clientData.name + delim;
    oneLine += to_string(clientData.accountBalance);

    return oneLine;
}
int main()
{
    stClientData clientData = readClientData();

    cout << "Client record for saving is:\n"
         << convertRecordToLine(clientData) << endl;

    return 0;
}