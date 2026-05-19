#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string fileName = "Clients Records";

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
    getline(cin >> ws, clientData.accountNumber);

    cout << "Enter PIN code: ";
    getline(cin, clientData.pinCode);

    cout << "Enter name: ";
    getline(cin, clientData.name);

    cout << "Enter Phone: ";
    getline(cin, clientData.phone);

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
    oneLine += clientData.phone + delim;
    oneLine += to_string(clientData.accountBalance);

    return oneLine;
}
void uploadDataToFile(string fileName, string data)
{
    fstream fileManager;

    fileManager.open(fileName, ios::out | ios::app);

    if (fileManager.is_open())
    {

        fileManager << data << endl;

        fileManager.close();
    }
}
void addClient()
{
    stClientData clientData = readClientData();
    string data = convertRecordToLine(clientData);

    uploadDataToFile(fileName, data);
}
void addClients()
{
    char newClient = 'Y';

    do
    {
        system("clear");
        cout << "Adding new client\n\n";

        addClient();

        cout << "Client added successfully, Do you want to add more clients? Y/N \n";
        cin >> newClient;

    } while (toupper(newClient) == 'Y');
}
int main()
{
    addClients();

    return 0;
}