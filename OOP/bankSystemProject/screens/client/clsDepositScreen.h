#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

class clsDepositScreen : protected clsScreen
{
private:
    static void _printClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.firstName();
        cout << "\nLastName    : " << client.lastName();
        cout << "\nFull Name   : " << client.fullName();
        cout << "\nEmail       : " << client.email();
        cout << "\nPhone       : " << client.phone();
        cout << "\nAcc. Number : " << client.accountNumber();
        cout << "\nPassword    : " << client.PINcode();
        cout << "\nBalance     : " << client.accountBalance();
        cout << "\n___________________\n";
    }

public:
    static void showDepositScreen()
    {
        _drawScreenHeader("Deposit Screen");

        cout << "\nPlease enter account number: ";
        string accountNumber;
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "!Client with account number [" << accountNumber << "] is not found!\nTry again: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);
        _printClient(client1);

        cout << "How much do you want to deposit? ";
        double amount;
        amount = clsInputValidate::readDoubleNumber();

        char choice = 'N';
        cout << "Are you sure to apply this transaction? ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            client1.deposit(amount);

            cout << "Done successfully, New balance: " << client1.accountBalance() << endl;
        }
        else
        {
            cout << "\nTransaction was cancelled!";
        }
    }
};