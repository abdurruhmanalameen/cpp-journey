#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClient : protected clsScreen
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
    static void findClient()
    {
        if (!checkAccessRights(clsUser::enPermissions::PFindClient))
        {
            return;
        }
        string accountNumber = "";

        _drawScreenHeader("Find Client Screen");
        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);

        if (client1.isEmpty())
        {
            cout << "\nCouldn't find the client";
        }
        else
        {
            cout << "\nThe client was found successfully";
        }

        _printClient(client1);
    }
};