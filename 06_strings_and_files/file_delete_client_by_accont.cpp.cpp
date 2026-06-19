#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const string fileName = "clientsRecords.txt";

struct stClientInfo
{
    string accountNumber;
    string PINcode;
    string name;
    string phone;
    double acountBalance;
    bool markToDelete = false;
};
string readAccountNumber(string message)
{
    string accountNumber;

    cout << message << endl;
    cin >> accountNumber;

    return accountNumber;
}
void printClientInfo(stClientInfo client)
{
    cout << "Client Info:\n\n"
         << "Account Number: " << client.accountNumber << endl
         << "PIN Code: " << client.PINcode << endl
         << "Name: " << client.name << endl
         << "Phone: " << client.phone << endl
         << "Account Balance: " << client.acountBalance << endl;
}
vector<string> separateStringWords(string line, string delim)
{
    vector<string> vWords;
    short pos = 0;
    string word = "";

    while ((pos = line.find(delim)) != std::string::npos)
    {
        word = line.substr(0, pos);

        if (word != "")
        {
            vWords.push_back(word);
        }

        line.erase(0, pos + delim.length());
    }

    if (line != "")
    {
        vWords.push_back(line);
    }

    return vWords;
}
stClientInfo convertLineToRecord(vector<string> vData)
{
    stClientInfo client;

    if (vData.size() >= 5)
    {
        client.accountNumber = vData[0];
        client.PINcode = vData[1];
        client.name = vData[2];
        client.phone = vData[3];
        client.acountBalance = stod(vData[4]);
    }

    return client;
}
vector<stClientInfo> loadClientsDataFromFile(string fileName, string delim = "***")
{
    fstream fileManager;
    vector<string> vData;
    vector<stClientInfo> vClients;
    stClientInfo client;

    fileManager.open(fileName, ios::in);

    if (fileManager.is_open())
    {
        string line;

        while (getline(fileManager, line))
        {
            vData = separateStringWords(line, delim);
            client = convertLineToRecord(vData);
            vClients.push_back(client);
        }

        fileManager.close();
    }

    return vClients;
}
bool searchAccountByAccountNumberInVector(vector<stClientInfo> &vClients, string accountNumber, stClientInfo &client)
{
    for (stClientInfo &C : vClients)
    {
        if (C.accountNumber == accountNumber)
        {
            client = C;
            return true;
        }
    }

    return false;
}
void markToDelete(vector<stClientInfo> &vClients, string accountNumber)
{
    for (stClientInfo &C : vClients)
        if (C.accountNumber == accountNumber)
        {
            C.markToDelete = true;
        }
}
string convertRecordToLine(stClientInfo client, string delim = "***")
{
    string line = "";

    line += client.accountNumber + delim;
    line += client.PINcode + delim;
    line += client.name + delim;
    line += client.phone + delim;
    line += to_string(client.acountBalance);

    return line;
}
void reWriteFile(string fileName, vector<stClientInfo> vClients)
{
    fstream fileManager;

    fileManager.open(fileName, ios::out);

    if (fileManager.is_open())
    {
        string line;

        for (stClientInfo client : vClients)
        {
            if (!client.markToDelete)
            {
                line = convertRecordToLine(client);
                fileManager << line << endl;
            }
        }

        fileManager.close();
    }
}
void deleteRecordFromFile()
{
    string accountNumber = readAccountNumber("Enter the account number to delete: ");
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);
    stClientInfo client;
    char toDelete = 'N';

    if (searchAccountByAccountNumberInVector(vClients, accountNumber, client))
    {
        printClientInfo(client);

        cout << "\nAre you sure to delete this client? Y/N\n";
        cin >> toDelete;

        if (toupper(toDelete) == 'Y')
        {
            markToDelete(vClients, accountNumber);

            reWriteFile(fileName, vClients);

            vClients = loadClientsDataFromFile(fileName);

            cout << "\nClient deleted successfully\n";
        }
    }
}

int main()
{
    deleteRecordFromFile();

    return 0;
}