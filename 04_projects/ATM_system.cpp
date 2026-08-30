#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const string fileName = "clientsRecords.txt";
void ATMsystem();
void login();
void goBackMainMenu();

enum enATMchoices
{
    QuickWithdraw = 1,
    NormalWithdraw,
    Deposit,
    CheckBalance,
    Logout
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

stClientInfo currentClient;

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

    cout << "\nUser with account number " << accountNumber << " not found!\n";

    return false;
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
bool searchClientByAccountNumberAndPIN(string accountNumber, string PIN, stClientInfo &client)
{
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    for (int i = 0; i < vClients.size(); i++)
    {
        if (accountNumber == vClients[i].accountNumber && PIN == vClients[i].PINcode)
        {
            client = vClients[i];
            ATMsystem();

            return true;
        }
    }

    return false;
}
void printClientInfo(stClientInfo client)
{
    cout << "\nThe following are the client deltails:\n"
         << "\n-----------------------------------\n"
         << "Client Info:\n\n"
         << "Account Number: " << client.accountNumber << endl
         << "PIN Code: " << client.PINcode << endl
         << "Name: " << client.name << endl
         << "Phone: " << client.phone << endl
         << "Account Balance: " << client.accountBalance << endl
         << "-----------------------------------\n";
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
void deposit(vector<stClientInfo> &vClients)
{
    double amount = 0;
    char deposit = 'N';

    system("clear");
    cout << "====================================================" << endl
         << "                  Deposit screen \n"
         << "====================================================\n";

    while (amount <= 0)
    {
        cout << "\nPlease enter deposit amount: ";
        cin >> amount;
    }

    cout << "\nAre you sure to perform this transaction? Y/N ";
    cin >> deposit;

    if (toupper(deposit) == 'Y')
    {
        for (int i = 0; i < vClients.size(); i++)
        {
            if (vClients[i].accountNumber == currentClient.accountNumber)
            {
                vClients[i].accountBalance += amount;
                currentClient.accountBalance = vClients[i].accountBalance;

                break;
            }
        }

        reWriteFile(fileName, vClients);
        cout << "\nAmount updated successfully\nNew balance: " << currentClient.accountBalance << endl;
    }
}
void withdraw(vector<stClientInfo> &vClients)
{
    char withdraw = 'N';
    double amount = 0;

    system("clear");
    cout << "====================================================" << endl
         << "             Normal Withdraw screen \n"
         << "====================================================\n";

    cout << "\nPlease enter an amount multiple of 5's?\n";
    cin >> amount;

    while (int(amount) % 5 != 0)
    {
        cout << "\nAmount is not multiple 5's, try again" << endl;
        cout << "Please enter withraw amount: ";
        cin >> amount;
    }
    while (amount > currentClient.accountBalance)
    {
        cout << "\nAmount exceeds the balance, you can withdraw up to: " << currentClient.accountBalance << endl;
        cout << "please enter withraw amount: ";
        cin >> amount;
    }

    cout << "\nAre you sure to perform this transaction? Y/N ";
    cin >> withdraw;

    if (toupper(withdraw) == 'Y')
    {
        for (int i = 0; i < vClients.size(); i++)
        {
            if (vClients[i].accountNumber == currentClient.accountNumber)
            {
                vClients[i].accountBalance -= amount;
                currentClient.accountBalance = vClients[i].accountBalance;

                break;
            }
        }
        reWriteFile(fileName, vClients);

        cout << "\nAmount updated successfully\nNew balance: " << currentClient.accountBalance << endl;
    }
}
void checkBalance()
{
    system("clear");
    cout << "====================================================" << endl
         << "              Chick Balance Screen\n"
         << "====================================================\n\n"
         << "You balance is: " << currentClient.accountBalance << endl;

    goBackMainMenu();
}
void goBackMainMenu()
{
    cout << "\nPress Enter to go back to main menu...";
    cin.ignore();
    cin.get();
    ATMsystem();
}
short choiceOfQuickWithdraw()
{
    short choice = 0;

    while (choice < 10 && choice > 0)
    {
        cout << "choose what to do from [1] to [9]?";
        cin >> choice;
    }

    return choice;
}
short getWithdrawAmount(short choice)
{
    switch (choice)
    {
    case 1:
    {
        return 20;
    }
    case 2:
    {
        return 50;
    }
    case 3:
    {
        return 100;
    }
    case 4:
    {
        return 200;
    }
    case 5:
    {
        return 400;
    }
    case 6:
    {
        return 600;
    }
    case 7:
    {
        return 800;
    }
    case 8:
    {
        return 1000;
    }
    default:
    {
        goBackMainMenu();
        return 0;
    }
    }
}
void quickWithdraw(vector<stClientInfo> &vClients)
{
    char withdraw = 'N';
    short choice = choiceOfQuickWithdraw();
    double amount = 0;

    system("clear");
    cout << "====================================================" << endl
         << "             Quick Withdraw screen \n"
         << "====================================================\n";

    cout << "=================================\n"
         << "[1] 20     [2] 50\n"
         << "[3] 100    [4] 200\n"
         << "[5] 400    [6] 600\n"
         << "[7] 800    [8] 1000\n"
         << "[9] Exit\n"
         << "=================================\n"
         << "Your balance is " << currentClient.accountBalance << endl;

    choice = choiceOfQuickWithdraw();

    amount = getWithdrawAmount(choice);

    while (amount > currentClient.accountBalance)
    {
        cout << "\nAmount exceeds the balance, you can withdraw up to: " << currentClient.accountBalance << endl;
        cout << "please enter withraw amount: ";
        cin >> amount;
    }

    cout << "\nAre you sure to perform this transaction? Y/N ";
    cin >> withdraw;

    if (toupper(withdraw) == 'Y')
    {
        for (int i = 0; i < vClients.size(); i++)
        {
            if (vClients[i].accountNumber == currentClient.accountNumber)
            {
                vClients[i].accountBalance -= amount;
                currentClient.accountBalance = vClients[i].accountBalance;

                break;
            }
        }

        reWriteFile(fileName, vClients);

        cout << "\nAmount updated successfully\nNew balance: " << currentClient.accountBalance << endl;
    }
}
void showMainScreen()
{
    system("clear");
    cout << "====================================================" << endl
         << "              ATM Main Menu Screen\n"
         << "====================================================\n"
         << "              [1] Quick Withdraw" << endl
         << "              [2] Normal Withdraw" << endl
         << "              [3] Deposit" << endl
         << "              [4] Check Balance" << endl
         << "              [5] Logout" << endl
         << "====================================================\n"
         << "Choose what do you want to do? [1 to 5]? ";
}
void ATMsystem()
{
    short choice;
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    showMainScreen();
    cin >> choice;

    switch (enATMchoices(choice))
    {
    case QuickWithdraw:
    {
        quickWithdraw(vClients);
        goBackMainMenu();

        break;
    }
    case NormalWithdraw:
    {
        withdraw(vClients);
        goBackMainMenu();

        break;
    }
    case Deposit:
    {
        deposit(vClients);
        goBackMainMenu();

        break;
    }
    case CheckBalance:
    {
        checkBalance();
        goBackMainMenu();

        break;
    }
    case Logout:
    {
        login();
    }
    }
}
void login()
{
    string accountNumber, PIN;

    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    bool loginFailed = false;

    do
    {
        system("clear");
        cout << "====================================================" << endl
             << "                  Login Screen\n"
             << "====================================================\n\n";

        if (loginFailed)
        {
            cout << "Invalid accountNumber/PIN!\n\n";
        }

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter PIN code: ";
        cin >> PIN;

        if (!searchClientByAccountNumberAndPIN(accountNumber, PIN, currentClient))
        {
            loginFailed = true;
        }

    } while (loginFailed);
}
int main()
{
    login();

    return 0;
}