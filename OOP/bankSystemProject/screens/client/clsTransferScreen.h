#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsTransferLoginScreen.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
private:
    static void _printShortClientCard(clsBankClient client)
    {
        cout << "\nClinet Card: \n"
             << "________________________________\n"
             << "Full name  : " << client.fullName() << endl
             << "Acc. Number: " << client.accountNumber() << endl
             << "Balance    : " << client.accountBalance() << endl
             << "________________________________\n";
    }
    static string _readSourceAccountNumber()
    {
        string transferFromAccountNumber = "";

        cout << "Pleas enter account number to transfer from: ";
        transferFromAccountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(transferFromAccountNumber))
        {
            cout << "This client is not exist, try again: ";
            transferFromAccountNumber = clsInputValidate::readString();
        }

        return transferFromAccountNumber;
    }
    static string _readDestinationAccountNumber()
    {
        string transferToAccountNumber = "";

        cout << "Please enter account number to transfer to: ";
        transferToAccountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(transferToAccountNumber))
        {
            cout << "This client is not exist, try again: ";
            transferToAccountNumber = clsInputValidate::readString();
        }

        return transferToAccountNumber;
    }
    static double _readAmount(clsBankClient client)
    {
        double amount = 0;

        cout << "Enter transfer amount: ";
        amount = clsInputValidate::readDoubleNumber();

        while (amount > client.accountBalance())
        {
            cout << "Amount exceeds account balance try again: ";
            amount = clsInputValidate::readDoubleNumber();
        }

        return amount;
    }
    static void _performTransferScreen()
    {

        clsBankClient sourceAccount = clsBankClient::find(_readSourceAccountNumber());

        _printShortClientCard(sourceAccount);

        clsBankClient destinationAccount = clsBankClient::find(_readDestinationAccountNumber());

        _printShortClientCard(destinationAccount);

        double amount = _readAmount(sourceAccount);

        if (sourceAccount.transfer(amount, destinationAccount))
        {
            cout << "\nTransfer done successfully\n";
        }
        else
        {
            cout << "\nTransfer failed!\n";
        }

        _printShortClientCard(sourceAccount);
        _printShortClientCard(destinationAccount);

        currentUser.transferLogins(sourceAccount, destinationAccount, amount);
    }

public:
    static void showTransferScreen()
    {
        _drawScreenHeader("Transfer Screen");
        _performTransferScreen();
    }
};