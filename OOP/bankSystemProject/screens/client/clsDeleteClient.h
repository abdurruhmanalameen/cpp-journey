#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDeleteClient : protected clsScreen
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
    static void deleteClient()
    {
        if (!checkAccessRights(clsUser::enPermissions::PDeleteClient))
        {
            return;
        }
        _drawScreenHeader("Delete Client Screen");
        string accountNumber = "";
        cout << "\nEnter account number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nClient not found, try again: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);

        _printClient(client1);

        char choice = 'N';
        cout << "\nAre you sure about deleting this client? Y/N ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            if (client1.deleteClient())
            {
                cout << "\nClient deleted successfully\n";
                _printClient(client1);
            }
            else
            {
                cout << "\nError couldn't delete the client!\n";
            }
        }
    }
};