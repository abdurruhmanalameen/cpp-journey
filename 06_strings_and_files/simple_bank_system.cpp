#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const string fileName = "clientsRecords.txt";

void bankSystem();
void transactions();

enum enMainChoices
{
    Show = 1,
    Add,
    Delete,
    Update,
    Find,
    Transactions,
    Exit
};
enum enTransactionsChoices
{
    Deposit = 1,
    Withdraw,
    TotalBalances,
    MainMenu
};
struct stClientInfo
{
    string accountNumber;
    string PINcode;
    string name;
    string phone;
    double accountBalance;
    bool markToDelete = false;
};
string readAccountNumber(string message)
{
    string accountNumber;

    cout << message << endl;
    cin >> accountNumber;

    return accountNumber;
}
stClientInfo updateClientData(string accountNumber)
{
    stClientInfo clientData;

    clientData.accountNumber = accountNumber;

    cout << "Please enter client data\n\n";

    cout << "Enter PIN code: ";
    getline(cin >> ws, clientData.PINcode);

    cout << "Enter name: ";
    getline(cin, clientData.name);

    cout << "Enter Phone: ";
    getline(cin, clientData.phone);

    cout << "Enter account balance: ";
    cin >> clientData.accountBalance;

    return clientData;
}
void printClientRecord(stClientInfo clientData)
{
    cout << "|" << left << setw(15) << clientData.accountNumber
         << "|" << left << setw(9) << clientData.PINcode
         << "|" << left << setw(25) << clientData.name
         << "|" << left << setw(10) << clientData.phone
         << "|" << left << setw(9) << clientData.accountBalance
         << "\n";
}
void printClientBalance(stClientInfo clientData)
{
    cout << "|" << left << setw(15) << clientData.accountNumber
         << "|" << left << setw(25) << clientData.name
         << "|" << left << setw(9) << clientData.accountBalance
         << "\n";
}
void printAllClientsData(vector<stClientInfo> &vClients)
{
    system("clear");
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
void printClientInfo(stClientInfo client)
{
    cout << "Client Info:\n\n"
         << "Account Number: " << client.accountNumber << endl
         << "PIN Code: " << client.PINcode << endl
         << "Name: " << client.name << endl
         << "Phone: " << client.phone << endl
         << "Account Balance: " << client.accountBalance << endl;
}
bool uniqueAccountNumber(vector<stClientInfo> &vClients, string accountNumber)
{
    for (int i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNumber == accountNumber)
        {
            return false;
        }
    }

    return true;
}
stClientInfo readClientData(vector<stClientInfo> vClients)
{
    stClientInfo clientData;
    int counter = 0;

    cout << "Please enter client data\n\n";

    cout << "Enter account number: ";
    getline(cin >> ws, clientData.accountNumber);

    while (!uniqueAccountNumber(vClients, clientData.accountNumber))
    {
        cout << "Sorry the client is already exists" << endl
             << "Enter another account number: ";
        getline(cin >> ws, clientData.accountNumber);
    }

    cout << "Enter PIN code: ";
    getline(cin, clientData.PINcode);

    cout << "Enter name: ";
    getline(cin, clientData.name);

    cout << "Enter Phone: ";
    getline(cin, clientData.phone);

    cout << "Enter account balance: ";
    cin >> clientData.accountBalance;

    return clientData;
}
string convertRecordToLine(stClientInfo clientData, string delim = "***")
{
    string oneLine = "";

    oneLine += clientData.accountNumber + delim;
    oneLine += clientData.PINcode + delim;
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
void addClient(vector<stClientInfo> &vClients)
{
    stClientInfo clientData = readClientData(vClients);
    string data = convertRecordToLine(clientData);

    uploadDataToFile(fileName, data);
}
void addClients(vector<stClientInfo> &vClients)
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Add new client screen \n"
         << "====================================================\n\n";
    char newClient = 'Y';

    do
    {
        system("clear");
        cout << "Adding new client\n\n";

        addClient(vClients);

        cout << "Client added successfully, Do you want to add more clients? Y/N \n";
        cin >> newClient;

    } while (toupper(newClient) == 'Y');
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
        client.accountBalance = stod(vData[4]);
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
void reWriteFile(string fileName, vector<stClientInfo> &vClients)
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
void updateRecordFromFile()
{
    system("clear");
    cout << "====================================================" << endl
         << "              Update client data screen\n"
         << "====================================================\n\n";
    string accountNumber = readAccountNumber("Enter the account number to Update: ");
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);
    stClientInfo client;
    char toUpdate = 'N';

    if (searchAccountByAccountNumberInVector(vClients, accountNumber, client))
    {
        printClientInfo(client);

        cout << "\nAre you sure to update this client? Y/N\n";
        cin >> toUpdate;

        if (toupper(toUpdate) == 'Y')
        {
            for (stClientInfo &C : vClients)
            {
                if (C.accountNumber == accountNumber)
                {
                    C = updateClientData(accountNumber);
                    break;
                }
            }

            reWriteFile(fileName, vClients);

            cout << "\nClient Updated successfully\n";
        }
    }
}
void deleteRecordFromFile()
{
    system("clear");
    cout << "====================================================" << endl
         << "                Delete client screen\n"
         << "====================================================\n\n";
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
void showMainScreen()
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Main Menu Screen\n"
         << "====================================================\n\n"
         << "              [1] Show Client List" << endl
         << "              [2] Add New Client" << endl
         << "              [3] Delete Client" << endl
         << "              [4] Update Client Info" << endl
         << "              [5] Find Client" << endl
         << "              [6] Transactions" << endl
         << "              [7] Exit" << endl
         << "====================================================\n"
         << "Choose what do you want to do? [1 to 7]? ";
}
void showTransactionScreen()
{
    system("clear");
    cout << "====================================================" << endl
         << "              transaction Menu Screen\n"
         << "====================================================\n\n"
         << "              [1] Deposit" << endl
         << "              [2] Withdraw" << endl
         << "              [3] Total balances" << endl
         << "              [4] Main menu" << endl
         << "====================================================\n"
         << "Choose what do you want to do? [1 to 4]? ";
}
void showEndScreen()
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Program Ends :-)\n"
         << "====================================================\n\n";
}
void deposit(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    string accountNumber;
    double amount = 0;
    char deposit = 'N';

    system("clear");
    cout << "====================================================" << endl
         << "                  Deposit screen \n"
         << "====================================================\n\n"
         << "Please enter accountNumber? ";
    cin >> accountNumber;

    while (uniqueAccountNumber(vClients, accountNumber))
    {
        cout << "\nSorry the client with [" << accountNumber << "] doesn't exist" << endl
             << "Enter another account number: ";
        cin >> accountNumber;
    }
    if (searchAccountByAccountNumberInVector(vClients, accountNumber, client))
    {
        printClientInfo(client);

        cout << "\nPlease enter deposit amount: ";
        cin >> amount;

        cout << "\nAre you sure to perform this transaction? Y/N ";
        cin >> deposit;

        if (toupper(deposit) == 'Y')
        {
            for (stClientInfo &C : vClients)
            {
                if (C.accountNumber == accountNumber)
                {
                    C.accountBalance += amount;
                    reWriteFile(fileName, vClients);
                    cout << "\nAmount updated successfully\nNew balance: " << C.accountBalance << endl;

                    break;
                }
            }
        }
    }
}
void withdraw(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    string accountNumber;
    double amount = 0;
    char withdraw = 'N';

    system("clear");
    cout << "====================================================" << endl
         << "                  Withdraw screen \n"
         << "====================================================\n\n"
         << "Please enter account number: ";
    cin >> accountNumber;

    while (uniqueAccountNumber(vClients, accountNumber))
    {
        cout << "\nSorry the client with [" << accountNumber << "] doesn't exist" << endl
             << "Enter another account number: ";
        cin >> accountNumber;
    }
    if (searchAccountByAccountNumberInVector(vClients, accountNumber, client))
    {
        printClientInfo(client);

        cout << "\nPlease enter withdraw amount: ";
        cin >> amount;

        while (amount > client.accountBalance)
        {
            cout << "\nAmount exceeds the balance, you can withdraw up to: " << client.accountBalance << endl;
            cout << "please enter withraw amount: ";
            cin >> amount;
        }

        cout << "\nAre you sure to perform this transaction? Y/N ";
        cin >> withdraw;

        if (toupper(withdraw) == 'Y')
        {
            for (stClientInfo &C : vClients)
            {
                if (C.accountNumber == accountNumber)
                {
                    C.accountBalance -= amount;
                    reWriteFile(fileName, vClients);

                    cout << "\nAmount updated successfully\nNew balance: " << C.accountBalance << endl;

                    break;
                }
            }
        }
    }
}
void totalBalances(vector<stClientInfo> &vClients)
{
    double total = 0;

    system("clear");
    cout << "                        Balances List (" << vClients.size() << ") Client(s)\n";
    cout << "_________________________________________________________________________\n\n";
    cout << "|Account Number |Client Name              |Balance  \n";
    cout << "_________________________________________________________________________\n\n";

    for (int i = 0; i < vClients.size(); i++)
    {
        printClientBalance(vClients[i]);
        total += vClients[i].accountBalance;
    }

    cout << "\n\t Total balances: " << total << endl;
    cout << "\n_________________________________________________________________________\n";
}
void goBackMainMenu()
{
    cout << "\nPress Enter to go back to main menu...";
    cin.ignore();
    cin.get();
    bankSystem();
}
void goBackTransactionsMenu()
{
    cout << "\nPress Enter to go back to transactions menu...";
    cin.ignore();
    cin.get();
    transactions();
}
void findClient(vector<stClientInfo> &vClients)
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Find client screen\n"
         << "====================================================\n\n";
    string accountNumber = readAccountNumber("Enter account number to search: ");
    stClientInfo client;
    if (searchAccountByAccountNumberInVector(vClients, accountNumber, client))
    {
        printClientInfo(client);
    }
    else
    {
        cout << "Client with account Number " << accountNumber << " Not found!\n";
    }
}
void bankSystem()
{
    short choice;
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    showMainScreen();
    cin >> choice;

    switch (enMainChoices(choice))
    {
    case enMainChoices::Show:
    {
        printAllClientsData(vClients);
        goBackMainMenu();

        break;
    }
    case enMainChoices::Add:
    {
        addClients(vClients);
        goBackMainMenu();

        break;
    }
    case enMainChoices::Delete:
    {
        deleteRecordFromFile();
        goBackMainMenu();

        break;
    }
    case enMainChoices::Update:
    {
        updateRecordFromFile();
        goBackMainMenu();

        break;
    }
    case enMainChoices::Find:
    {
        findClient(vClients);
        goBackMainMenu();

        break;
    }
    case enMainChoices::Transactions:
    {
        transactions();

        break;
    }
    default:
    {
        showEndScreen();

        break;
    }
    }
}
void transactions()
{
    short choice;
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    showTransactionScreen();
    cin >> choice;

    switch (enTransactionsChoices(choice))
    {
    case enTransactionsChoices::Deposit:
    {
        deposit(vClients);
        goBackTransactionsMenu();

        break;
    }
    case enTransactionsChoices::Withdraw:
    {
        withdraw(vClients);
        goBackTransactionsMenu();

        break;
    }
    case enTransactionsChoices::TotalBalances:
    {
        totalBalances(vClients);
        goBackTransactionsMenu();

        break;
    }
    default:
    {
        bankSystem();

        break;
    }
    }
}
int main()
{
    bankSystem();

    return 0;
}
