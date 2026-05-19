#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string fileName = "Clients Records";

string readAccountNumber(string message)
{
    string accountNumber;

    cout << message << endl;
    getline(cin, accountNumber);

    return accountNumber;
}
struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markAsDeleted = false;
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
stClientData convertLineToRecord(string lineRecord, string delim = "***")
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
vector<stClientData> loadClientsDataFromFile(string fileName)
{
    stClientData clientData;
    fstream fileManager;
    vector<stClientData> vClients;

    if (fileManager.is_open())
    {
        string line;
        while (getline(fileManager, line))
        {
            clientData = convertLineToRecord(line);
            vClients.push_back(clientData);
        }

        fileManager.close();
    }

    return vClients;
}
void printClientInfo(stClientData client)
{
    cout << "The Following are the client details:\n\n";
    cout << "Account Number: " << client.accountNumber << endl;
    cout << "PIN Code: " << client.pinCode << endl;
    cout << "Name: " << client.name << endl;
    cout << "Phone: " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;
}
bool searchAccountByAccountNumberInVector(vector<stClientData> vClients, string accountNumber, stClientData &client)
{
    for (stClientData &C : vClients)
    {
        if (C.accountNumber == accountNumber)
        {
            client = C;
            return true;
        }
    }

    return false;
}
void markToDelete(stClientData client)
{
}
void deleteRecordFromFile(string fileName, vector<stClientData> vClients, stClientData accountNumber)
{
    stClientData client;
    if (searchAccountByAccountNumberInVector(vClients, accountNumber.accountNumber, client))
    {
        printClientInfo(client);
        char deleteOrNot = 'n';

        cout << "Are you sure to delete this client? Y/N";
        cin >> deleteOrNot;

        if (toupper(deleteOrNot) == 'Y')
        {
        }
    }
}
int main()
{
    string accountNumber = readAccountNumber("Please enter the account number: ");
    vector<stClientData> vClients = loadClientsDataFromFile(fileName);

    return 0;
}