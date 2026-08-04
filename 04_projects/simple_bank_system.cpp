#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

const string fileName = "clientsRecords.txt";
const string usersFileName = "users.txt";

void bankSystem();
void transactions();
void manageUsers();
void login();

enum enMainChoices
{
    Show = 1,
    Add,
    Delete,
    Update,
    Find,
    Transactions,
    ManageUsers,
    Logout
};
enum enTransactionsChoices
{
    Deposit = 1,
    Withdraw,
    TotalBalances,
    MainMenu
};
enum enManageUsersChoices
{
    ListUsers = 1,
    AddNewUser,
    DeleteUser,
    FindUser,
    UpdateUser,
    GoBackMainMenu
};
enum enPermissions
{
    PFullAccess = -1,
    PShowClients = 1,
    PAddClient = 2,
    PDeleteClient = 4,
    PUpdateClients = 8,
    PFindClient = 16,
    PTransactions = 32,
    PManageUsers = 64
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
struct stUserInfo
{
    string username;
    string password;
    short permissions = 0;
    bool markToDelete = false;
};

stUserInfo currentUser;

string readAccountNumber(string message)
{
    string accountNumber;

    cout << message << endl;
    cin >> accountNumber;

    return accountNumber;
}
string readUsername(string message)
{
    string username;

    cout << message << endl;
    cin >> username;

    return username;
}
stUserInfo permissions(stUserInfo &userData)
{
    char answer = 'N';

    cout << "\nDo you want to give full access? Y/N\n";
    cin >> answer;

    if (toupper(answer) == 'Y')
    {
        userData.permissions = PFullAccess;
    }
    else
    {
        cout << "Do you want to give access to:\n";
        cout << "Show client list? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PShowClients;
        }

        cout << "Add new client? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PAddClient;
        }

        cout << "Delete client? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PDeleteClient;
        }

        cout << "Update client? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PUpdateClients;
        }

        cout << "Find client? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PFindClient;
        }

        cout << "Transactions? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PTransactions;
        }

        cout << "Manage users? Y/N\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            userData.permissions |= PManageUsers;
        }
    }

    return userData;
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
stUserInfo updateUserData(string username)
{
    stUserInfo userData;

    userData.username = username;

    cout << "Please enter user data\n\n";

    cout << "Enter password: ";
    getline(cin >> ws, userData.password);

    userData = permissions(userData);

    return userData;
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
void printUserRecord(stUserInfo userData)
{
    cout << "|" << left << setw(25) << userData.username
         << "|" << left << setw(9) << userData.password
         << "|" << left << setw(12) << userData.permissions
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
void listAllUsers(vector<stUserInfo> &vUsers)
{
    system("clear");
    cout << "                        Client List (" << vUsers.size() << ") Client(s)\n";
    cout << "_________________________________________________________________________\n\n";
    cout << "|User Name                |Password |Permissions\n";
    cout << "_________________________________________________________________________\n\n";

    for (int i = 0; i < vUsers.size(); i++)
    {
        printUserRecord(vUsers[i]);
    }

    cout << "\n_________________________________________________________________________\n";
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
void printUserInfo(stUserInfo user)
{
    cout << "\nThe following are the user deltails:\n"
         << "\n-----------------------------------\n"
         << "User Info:\n\n"
         << "Username: " << user.username << endl
         << "Password: " << user.password << endl
         << "Permissions: " << user.permissions << endl
         << "-----------------------------------\n";
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
bool uniqueusername(vector<stUserInfo> &vUsers, string username)
{
    for (int i = 0; i < vUsers.size(); i++)
    {
        if (vUsers[i].username == username)
        {
            return false;
        }
    }

    return true;
}
stClientInfo readClientData(vector<stClientInfo> &vClients)
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
stUserInfo readUserData(vector<stUserInfo> &vUsers)
{
    stUserInfo userData;
    int counter = 0;

    cout << "Please enter user data\n\n";

    cout << "Enter user name: ";
    getline(cin >> ws, userData.username);

    while (!uniqueusername(vUsers, userData.username))
    {
        cout << "Sorry the user is already exists" << endl
             << "Enter another user name: ";
        getline(cin >> ws, userData.username);
    }

    cout << "Enter password: ";
    getline(cin, userData.password);

    userData = permissions(userData);

    return userData;
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
string convertRecordToLine(stUserInfo userData, string delim = "#//#")
{
    string oneLine = "";

    oneLine += userData.username + delim;
    oneLine += userData.password + delim;
    oneLine += to_string(userData.permissions);

    return oneLine;
}
void uploadDataToFile(string fileN, string data)
{
    fstream fileManager;

    fileManager.open(fileN, ios::out | ios::app);

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
void addUser(vector<stUserInfo> &vUsers)
{
    stUserInfo userData = readUserData(vUsers);
    string data = convertRecordToLine(userData);

    uploadDataToFile(usersFileName, data);
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
        cout << "Adding new client\n\n";

        addClient(vClients);

        cout << "Client added successfully, Do you want to add more clients? Y/N \n";
        cin >> newClient;

        system("clear");

    } while (toupper(newClient) == 'Y');
}
void addUsers(vector<stUserInfo> &vUser)
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Add new user screen \n"
         << "====================================================\n\n";
    char newUser = 'Y';

    do
    {
        cout << "Adding new user\n\n";

        addUser(vUser);

        cout << "user added successfully, Do you want to add more users? Y/N \n";
        cin >> newUser;

        system("clear");

    } while (toupper(newUser) == 'Y');
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
stUserInfo convertLineToRecord2(vector<string> vData)
{
    stUserInfo user;

    if (vData.size() >= 3)
    {
        user.username = vData[0];
        user.password = vData[1];
        user.permissions = stoi(vData[2]);
    }

    return user;
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
vector<stUserInfo> loadUsersDataFromFile(string usersFileName, string delim = "#//#")
{
    fstream fileManager;
    vector<string> vData;
    vector<stUserInfo> vUsers;
    stUserInfo user;

    fileManager.open(usersFileName, ios::in);

    if (fileManager.is_open())
    {
        string line;

        while (getline(fileManager, line))
        {
            vData = separateStringWords(line, delim);
            user = convertLineToRecord2(vData);
            vUsers.push_back(user);
        }

        fileManager.close();
    }

    return vUsers;
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

    cout << "\nUser with account number " << accountNumber << " not found!\n";

    return false;
}
bool searchUserByusernameInVector(vector<stUserInfo> &vUsers, string username, stUserInfo &user)
{
    for (stUserInfo &U : vUsers)
    {
        if (U.username == username)
        {
            user = U;
            return true;
        }
    }

    cout << "\nUser with username " << username << " not found!\n";

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
void markToDelete(vector<stUserInfo> &vUsers, string username)
{
    for (stUserInfo &U : vUsers)
        if (U.username == username)
        {
            U.markToDelete = true;
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
void reWriteFile(string usersFileName, vector<stUserInfo> &vUsers)
{
    fstream fileManager;

    fileManager.open(usersFileName, ios::out);

    if (fileManager.is_open())
    {
        string line;

        for (stUserInfo user : vUsers)
        {
            if (!user.markToDelete)
            {
                line = convertRecordToLine(user);
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
void updateUserFromFile()
{
    system("clear");
    cout << "====================================================" << endl
         << "              Update user data screen\n"
         << "====================================================\n\n";
    string username = readUsername("Enter the username to Update: ");
    vector<stUserInfo> vUsers = loadUsersDataFromFile(usersFileName);
    stUserInfo user;
    char toUpdate = 'N';

    if (searchUserByusernameInVector(vUsers, username, user))
    {
        printUserInfo(user);

        cout << "\nAre you sure to update this user? Y/N\n";
        cin >> toUpdate;

        if (toupper(toUpdate) == 'Y')
        {
            for (stUserInfo &U : vUsers)
            {
                if (U.username == username)
                {
                    U = updateUserData(username);
                    break;
                }
            }

            reWriteFile(usersFileName, vUsers);

            cout << "\nUser updated successfully\n";
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
void deleteUserFromFile()
{
    system("clear");
    cout << "====================================================" << endl
         << "                Delete user screen\n"
         << "====================================================\n\n";
    string username = readAccountNumber("Enter username to delete: ");
    vector<stUserInfo> vUsers = loadUsersDataFromFile(usersFileName);
    stUserInfo user;
    char toDelete = 'N';

    if (username == "Admin")
    {
        cout << "\nYou can't delete the Admin!\n";
    }
    else if (searchUserByusernameInVector(vUsers, username, user))
    {
        printUserInfo(user);

        cout << "\nAre you sure to delete this user? Y/N\n";
        cin >> toDelete;

        if (toupper(toDelete) == 'Y')
        {
            markToDelete(vUsers, username);

            reWriteFile(usersFileName, vUsers);

            vUsers = loadUsersDataFromFile(usersFileName);

            cout << "\nUser deleted successfully\n";
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
         << "              [7] Manage Users" << endl
         << "              [8] Logout" << endl
         << "====================================================\n"
         << "Choose what do you want to do? [1 to 8]? ";
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
void showManageUsersScreen()
{
    system("clear");
    cout << "====================================================" << endl
         << "              Manage Users Screen\n"
         << "====================================================\n\n"
         << "              [1] List users" << endl
         << "              [2] Add a new user" << endl
         << "              [3] Delete user" << endl
         << "              [4] Find user" << endl
         << "              [5] Update user" << endl
         << "              [6] Go back to main menu" << endl
         << "====================================================\n"
         << "Choose what do you want to do? [1 to 6]? ";
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
void goBackManageUsersMenu()
{
    cout << "\nPress Enter to go back to manage users menu...";
    cin.ignore();
    cin.get();
    manageUsers();
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
}
void findUser(vector<stUserInfo> &vUsers)
{
    system("clear");
    cout << "====================================================" << endl
         << "                  Find client screen\n"
         << "====================================================\n\n";
    string username = readUsername("Enter username to search: ");
    stUserInfo user;
    if (searchUserByusernameInVector(vUsers, username, user))
    {
        printUserInfo(user);
    }
}
bool havePermission(enMainChoices choice)
{

    if (currentUser.permissions == PFullAccess)
    {
        return true;
    }

        switch (choice)
    {
    case enMainChoices::Show:
    {
        return currentUser.permissions & PShowClients;
    }
    case enMainChoices::Add:
    {
        return currentUser.permissions & PAddClient;
    }
    case enMainChoices::Delete:
    {
        return currentUser.permissions & PDeleteClient;
    }
    case enMainChoices::Update:
    {
        return currentUser.permissions & PUpdateClients;
    }
    case enMainChoices::Find:
    {
        return currentUser.permissions & PFindClient;
    }
    case enMainChoices::Transactions:
    {
        return currentUser.permissions & PTransactions;
    }
    case enMainChoices::ManageUsers:
    {
        return currentUser.permissions & PManageUsers;
    }
    case enMainChoices::Logout:
    {
        return true;
    }
    }

    return false;
}
void bankSystem()
{
    short choice;
    vector<stClientInfo> vClients = loadClientsDataFromFile(fileName);

    showMainScreen();
    cin >> choice;

    if (havePermission(enMainChoices(choice)))
    {
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
        case enMainChoices::ManageUsers:
        {
            manageUsers();

            break;
        }
        case enMainChoices::Logout:
        {
            login();
        }
        }
    }
    else
    {
        system("clear");

        cout << "\n-----------------------------------------------\n"
             << "Access denied!\n"
             << "\nSorry you don't have permission to do that\n"
             << "Contact with your admin\n"
             << "\n-----------------------------------------------\n";

        goBackMainMenu();
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
void manageUsers()
{
    short choice;
    vector<stUserInfo> vUsers = loadUsersDataFromFile(usersFileName);

    showManageUsersScreen();

    cin >> choice;

    switch (enManageUsersChoices(choice))
    {
    case enManageUsersChoices::ListUsers:
    {
        listAllUsers(vUsers);
        goBackManageUsersMenu();

        break;
    }
    case enManageUsersChoices::AddNewUser:
    {
        addUsers(vUsers);
        goBackManageUsersMenu();

        break;
    }
    case enManageUsersChoices::DeleteUser:
    {
        deleteUserFromFile();
        goBackManageUsersMenu();

        break;
    }
    case enManageUsersChoices::FindUser:
    {
        findUser(vUsers);
        goBackManageUsersMenu();

        break;
    }
    case enManageUsersChoices::UpdateUser:
    {
        updateUserFromFile();
        goBackManageUsersMenu();

        break;
    }
    default:
    {
        bankSystem();

        break;
    }
    }
}
bool searchUserByUsernameAndPassword(string username, string password)
{
    vector<stUserInfo> vUsers = loadUsersDataFromFile(usersFileName);

    for (int i = 0; i < vUsers.size(); i++)
    {
        if (username == vUsers[i].username && password == vUsers[i].password)
        {
            currentUser = vUsers[i];
            bankSystem();

            return true;
        }
    }

    return false;
}
void login()
{
    string username, password;

    vector<stUserInfo> vUsers = loadUsersDataFromFile(usersFileName);

    bool loginFailed = false;

    do
    {
        system("clear");
        cout << "====================================================" << endl
             << "                  Login Screen\n"
             << "====================================================\n\n";

        if (loginFailed)
        {
            cout << "Invalid username/password!\n\n";
        }

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        if (!searchUserByUsernameAndPassword(username, password))
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
