#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include "clsString.h"
#include "clsPerson.h"
#include "clsUtility.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        emptyMode = 0,
        updateMode = 1,
        addNewMode
    };
    enMode _mode;
    string _accountNumber;
    string _PINcode;
    float _accountBalance;
    bool _markToDelete = false;

    static void _reWriteTheFile(vector<clsBankClient> &vClients)
    {
        fstream fileManager;

        fileManager.open("clients.txt", ios::out);

        if (fileManager.is_open())
        {
            string line;

            for (clsBankClient &C : vClients)
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
    static string _convertRecordToLine(clsBankClient clientData, string delim = "#//#")
    {
        string oneLine = "";

        oneLine += clientData.firstName() + delim;
        oneLine += clientData.lastName() + delim;
        oneLine += clientData.email() + delim;
        oneLine += clientData.phone() + delim;
        oneLine += clientData.accountNumber() + delim;
        oneLine += clsUtility::encryption(clientData.PINcode()) + delim;
        oneLine += to_string(clientData.accountBalance());

        return oneLine;
    }
    static void _saveClientDataToFile(vector<clsBankClient> &vClients)
    {
        fstream fileManager;
        string line;

        fileManager.open("clients.txt", ios::out);

        if (fileManager.is_open())
        {
            for (clsBankClient &C : vClients)
            {
                line = _convertRecordToLine(C);

                fileManager << line << endl;
            }

            fileManager.close();
        }
    }
    static clsBankClient _convertLineToClientObject(string line, string separator = "#//#")
    {
        vector<string> vClients = clsString::separateStringWords(line, separator);

        return clsBankClient(enMode::updateMode, vClients[0], vClients[1], vClients[2], vClients[3], vClients[4], clsUtility::decryption(vClients[5]), stod(vClients[6]));
    }
    static void _addAlineToFile(string line)
    {
        fstream fileManager;

        fileManager.open("clients.txt", ios::out | ios::app);

        if (fileManager.is_open())
        {
            fileManager << line << endl;

            fileManager.close();
        }
    }
    static clsBankClient _getEmptyClientObject()
    {
        return clsBankClient(emptyMode, "", "", "", "", "", "", 0);
    }
    static vector<clsBankClient> _loadClientsDataFromFile()
    {
        fstream fileManager;
        vector<clsBankClient> vClients;

        fileManager.open("clients.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsBankClient client = _convertLineToClientObject(line);
                vClients.push_back(client);
            }

            fileManager.close();
        }

        return vClients;
    }
    void _update()
    {
        vector<clsBankClient> vClients = _loadClientsDataFromFile();

        for (clsBankClient &C : vClients)
        {
            if (C.accountNumber() == accountNumber())
            {
                C = *this;
                break;
            }
        }

        _saveClientDataToFile(vClients);
    }
    void _addNew()
    {
        _addAlineToFile(_convertRecordToLine(*this));
    }

public:
    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone, string accountNumber, string PINcode, float accountBalance) : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _accountNumber = accountNumber;
        _PINcode = PINcode;
        _accountBalance = accountBalance;
    }

    bool isEmpty()
    {
        return _mode == emptyMode;
    }
    string accountNumber()
    {
        return _accountNumber;
    }
    string PINcode()
    {
        return _PINcode;
    }
    float accountBalance()
    {
        return _accountBalance;
    }

    void setPINcode(string PINcode)
    {
        _PINcode = PINcode;
    }
    void setAccountBalance(float accountBalance)
    {
        _accountBalance = accountBalance;
    }

    static double getTotalBalances()
    {
        vector<clsBankClient> vClients = _loadClientsDataFromFile();
        double totalBalances = 0;

        for (clsBankClient &C : vClients)
        {
            totalBalances += C.accountBalance();
        }

        return totalBalances;
    }
    static clsBankClient find(string accountNumber)
    {
        fstream fileManager;

        fileManager.open("clients.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.accountNumber() == accountNumber)
                {
                    fileManager.close();
                    return client;
                }
            }

            fileManager.close();
        }

        return _getEmptyClientObject();
    }
    static clsBankClient find(string accountNumber, string PINcode)
    {
        fstream fileManager;

        fileManager.open("clients.txt", ios::in);

        if (fileManager.is_open())
        {
            string line;

            while (getline(fileManager, line))
            {
                clsBankClient client = _convertLineToClientObject(line);
                if (client.accountNumber() == accountNumber && client.PINcode() == PINcode)
                {
                    fileManager.close();
                    return client;
                }
            }

            fileManager.close();
        }

        return _getEmptyClientObject();
    }
    static bool isClientExist(string accountNumber)
    {
        clsBankClient client = find(accountNumber);
        return !client.isEmpty();
    }
    static clsBankClient getAddNewClinet(string accountNumber)
    {
        return clsBankClient(addNewMode, "", "", "", "", accountNumber, "", 0);
    }
    enum enSaveStatus
    {
        svFailEmptyObject = 0,
        svSucceeded = 1,
        svFailedAlreadyUsed
    };
    bool deleteClient()
    {
        vector<clsBankClient> vClients = _loadClientsDataFromFile();

        for (clsBankClient &C : vClients)
        {
            if (C.accountNumber() == accountNumber())
            {
                C._markToDelete = true;
                break;
            }
        }

        _reWriteTheFile(vClients);

        *this = _getEmptyClientObject();

        return true;
    }
    static vector<clsBankClient> getClientsList()
    {
        return _loadClientsDataFromFile();
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
            if (isClientExist(_accountNumber))
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
    void deposit(double amount)
    {
        _accountBalance += amount;

        save();
    }
    bool withdraw(double amount)
    {
        if (amount > _accountBalance)
        {
            return false;
        }
        else
        {
            _accountBalance -= amount;

            save();

            return true;
        }
    }
    bool transfer(double amount, clsBankClient &destinationAccount)
    {
        if (amount > _accountBalance)
        {
            return false;
        }
        else
        {
            withdraw(amount);
            destinationAccount.deposit(amount);

            return true;
        }
    }
};