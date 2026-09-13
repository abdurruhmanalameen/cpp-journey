#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "clsDate.h"
#include <chrono>
#include "clsString.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsUtility.h"

using namespace std;

class clsUser : public clsPerson
{
public:
    struct stLoginRegister;
    struct stTransferLog;

private:
    enum enMode
    {
        emptyMode = 0,
        updateMode = 1,
        addNewMode
    };
    enMode _mode;
    string _username;
    string _password;
    int _permissions;
    bool _markToDelete = false;

    static void _reWriteTheFile(vector<clsUser> &vUsers)
    {
        fstream fileManager;

        fileManager.open("users.txt", ios::out);

        if (fileManager.is_open())
        {
            string line;

            for (clsUser &C : vUsers)
            {
                if (!C._markToDelete)
                {
                    line = _convertRecordToLine(C);
                    fileManager << line << endl;
                }
            }

            fileManager.close();
        }
    }
    static string _convertRecordToLine(clsUser userData, string delim = "#//#")
    {
        string oneLine = "";

        oneLine += userData.firstName() + delim;
        oneLine += userData.lastName() + delim;
        oneLine += userData.email() + delim;
        oneLine += userData.phone() + delim;
        oneLine += userData.username() + delim;
        oneLine += clsUtility::encryption(userData.password()) + delim;
        oneLine += to_string(userData.permissions());

        return oneLine;
    }
    static void _saveUserDataToFile(vector<clsUser> &vUsers)
    {
        fstream fileManager;
        string line;

        fileManager.open("users.txt", ios::out);

        if (fileManager.is_open())
        {
            for (clsUser &C : vUsers)
            {
                line = _convertRecordToLine(C);

                fileManager << line << endl;
            }

            fileManager.close();
        }
    }
    static clsUser _convertLineToUserObject(string line, string separator = "#//#")
    {
        vector<string> vUsers = clsString::separateStringWords(line, separator);

        return clsUser(enMode::updateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4], clsUtility::decryption(vUsers[5]), stoi(vUsers[6]));
    }
    static stLoginRegister _convertLoginInfoToStruct(string line, string separator = "#//#")
    {
        vector<string> vUsers = clsString::separateStringWords(line, separator);
        stLoginRegister loginInfo;
        loginInfo.time = vUsers[0];
        loginInfo.username = vUsers[1];
        loginInfo.password = vUsers[2];
        loginInfo.permissions = stoi(vUsers[3]);

        return loginInfo;
    }
    static stTransferLog _convertTransferLogInfoToStruct(string line, string separator = "#//#")
    {
        vector<string> vTransferLogs = clsString::separateStringWords(line, separator);
        stTransferLog transferLog;

        transferLog.time = vTransferLogs[0];
        transferLog.sourceAccountNumber = vTransferLogs[1];
        transferLog.destinationAccountNumber = vTransferLogs[2];
        transferLog.amount = stod(vTransferLogs[3]);
        transferLog.sourceBalance = stod(vTransferLogs[4]);
        transferLog.destinationBalance = stod(vTransferLogs[5]);
        transferLog.username = vTransferLogs[6];

        return transferLog;
    }
    static void _addAlineToFile(string line)
    {
        fstream fileManager;

        fileManager.open("users.txt", ios::out | ios::app);

        if (fileManager.is_open())
        {
            fileManager << line << endl;

            fileManager.close();
        }
    }
    static clsUser _getEmptyUserObject()
    {
        return clsUser(emptyMode, "", "", "", "", "", "", 0);
    }
    static vector<clsUser> _loadUsersDataFromFile()
    {
        fstream fileManager;
        vector<clsUser> vUsers;

        fileManager.open("users.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsUser user = _convertLineToUserObject(line);
                vUsers.push_back(user);
            }

            fileManager.close();
        }

        return vUsers;
    }
    static vector<stLoginRegister> _loadLoginRegisterListFromFile()
    {
        fstream fileManager;
        vector<stLoginRegister> vloginInfo;

        fileManager.open("loginRegister.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                stLoginRegister loginInfo = _convertLoginInfoToStruct(line);
                vloginInfo.push_back(loginInfo);
            }

            fileManager.close();
        }

        return vloginInfo;
    }
    static vector<stTransferLog> _loadTransferLogListFromFile()
    {
        fstream fileManager;
        vector<stTransferLog> vTransferLogInfo;

        fileManager.open("transferLog.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                stTransferLog transferLogInfo = _convertTransferLogInfoToStruct(line);
                vTransferLogInfo.push_back(transferLogInfo);
            }

            fileManager.close();
        }

        return vTransferLogInfo;
    }
    void _update()
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &C : vUsers)
        {
            if (C.username() == username())
            {
                C = *this;
                break;
            }
        }

        _saveUserDataToFile(vUsers);
    }
    void _addNew()
    {
        _addAlineToFile(_convertRecordToLine(*this));
    }
    string _prepareLoginUser(string delim = "#//#")
    {
        string line = "";

        line += clsDate::convertDateToString(clsDate());
        line += " - ";
        line += clsDate::printCurrentTime() + delim;
        line += _username + delim;
        line += clsUtility::encryption(_password) + delim;
        line += to_string(_permissions);

        return line;
    }
    string _prepareTransferLogs(clsBankClient fromClient, clsBankClient toClient, double amount, string delim = "#//#")
    {
        string line = "";

        line += clsDate::convertDateToString(clsDate());
        line += " - ";
        line += clsDate::printCurrentTime() + delim;
        line += fromClient.accountNumber() + delim;
        line += toClient.accountNumber() + delim;
        line += to_string(amount) + delim;
        line += to_string(fromClient.accountBalance()) + delim;
        line += to_string(toClient.accountBalance()) + delim;
        line += _username;

        return line;
    }

public:
    struct stLoginRegister
    {
        string time;
        string username;
        string password;
        int permissions;
    };
    struct stTransferLog
    {
        string time;
        string sourceAccountNumber;
        string destinationAccountNumber;
        double amount;
        double sourceBalance;
        double destinationBalance;
        string username;
    };
    clsUser(enMode mode, string firstName, string lastName, string email, string phone, string username, string password, int permissions) : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _username = username;
        _password = password;
        _permissions = permissions;
    }

    enum enPermissions
    {
        PFullAccess = -1,
        PShowClients = 1,
        PAddClient = 2,
        PDeleteClient = 4,
        PUpdateClient = 8,
        PFindClient = 16,
        PTransactions = 32,
        PManageUsers = 64,
        PLoginRegister = 123
    };
    bool isEmpty()
    {
        return _mode == emptyMode;
    }
    string username()
    {
        return _username;
    }
    string password()
    {
        return _password;
    }
    int permissions()
    {
        return _permissions;
    }

    void setUsername(string username)
    {
        _username = username;
    }
    void setPassword(string password)
    {
        _password = password;
    }
    void setPermissions(int permissions)
    {
        _permissions |= permissions;
    }

    static clsUser find(string username)
    {
        fstream fileManager;

        fileManager.open("users.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsUser user = _convertLineToUserObject(line);
                if (user.username() == username)
                {
                    fileManager.close();
                    return user;
                }
            }

            fileManager.close();
        }

        return _getEmptyUserObject();
    }
    static clsUser find(string username, string password)
    {
        fstream fileManager;

        fileManager.open("users.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsUser user = _convertLineToUserObject(line);
                if (user.username() == username && user.password() == password)
                {
                    fileManager.close();
                    return user;
                }
            }

            fileManager.close();
        }

        return _getEmptyUserObject();
    }
    static bool isUserExist(string username)
    {
        clsUser user = find(username);
        return !user.isEmpty();
    }
    static clsUser getAddNewClinet(string username)
    {
        return clsUser(addNewMode, "", "", "", "", username, "", 0);
    }
    enum enSaveStatus
    {
        svFailEmptyObject = 0,
        svSucceeded = 1,
        svFailedAlreadyUsed
    };
    bool deleteUser()
    {
        vector<clsUser> vUsers = _loadUsersDataFromFile();

        for (clsUser &C : vUsers)
        {
            if (C.username() == username())
            {
                C._markToDelete = true;
                break;
            }
        }

        _reWriteTheFile(vUsers);

        *this = _getEmptyUserObject();

        return true;
    }
    static vector<clsUser> getUsersList()
    {
        return _loadUsersDataFromFile();
    }
    static vector<stLoginRegister> getLoginRegisterList()
    {
        return _loadLoginRegisterListFromFile();
    }
    static vector<stTransferLog> getTransferLogsList()
    {
        return _loadTransferLogListFromFile();
    }
    enSaveStatus save()
    {
        switch (_mode)
        {
        case updateMode:
        {
            _update();
            return svSucceeded;
        }
        case addNewMode:
        {
            if (isUserExist(_username))
            {
                return svFailedAlreadyUsed;
            }
            else
            {
                _addNew();
                _mode = updateMode;
                return svSucceeded;
            }
        }
        default:
        {

            return svFailEmptyObject;
        }
        }
    }
    void loginRegister()
    {
        fstream fileManager;
        string line = _prepareLoginUser();

        fileManager.open("loginRegister.txt", ios::out | ios::app);

        if (fileManager.is_open())
        {
            fileManager << line << endl;

            fileManager.close();
        }
    }
    void transferLogins(clsBankClient fromClient, clsBankClient toClinet, double amount)
    {
        fstream fileManager;
        string line = _prepareTransferLogs(fromClient, toClinet, amount);

        fileManager.open("transferLog.txt", ios::out | ios::app);

        if (fileManager.is_open())
        {
            fileManager << line << endl;

            fileManager.close();
        }
    }
    bool checkAccessPermission(enPermissions permission)
    {
        if (this->permissions() == PFullAccess)
        {
            return true;
        }
        else if (this->permissions() & permission == permission)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};