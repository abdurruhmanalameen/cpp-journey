#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string fileName = "Clients Records";

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

    fileManager.open(fileName, ios::in);

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
void printClientRecord(stClientData clientData)
{
    cout << "|" << left << setw(15) << clientData.accountNumber
         << "|" << left << setw(9) << clientData.pinCode
         << "|" << left << setw(25) << clientData.name
         << "|" << left << setw(10) << clientData.phone
         << "|" << left << setw(9) << clientData.accountBalance
         << "\n";
}
void printAllClientsData(vector<stClientData> vClients)
{

    cout << "                        Client List (" << vClients.size() << ") Client(s)\n";
    cout << "_________________________________________________________________________\n\n";
    cout << "|Account Number |Pin Code |Client Name              |Phone     |Balance  \n";
    cout << "_________________________________________________________________________\n\n";

    for (int i = 0; i < vClients.size(); i++)
    {
        printClientRecord(vClients[i]);
    }

    cout << "\n_________________________________________________________________________\n";
}

int main()
{
    vector<stClientData> vClients = loadClientsDataFromFile(fileName);
    printAllClientsData(vClients);

    return 0;
}