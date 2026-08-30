#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClient : protected clsScreen
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

    static void _readClientInfo(clsBankClient &client)
    {
        cout << "\nEnter first name: ";
        client.setFirstName(clsInputValidate::readString());

        cout << "\nEnter last name: ";
        client.setLastName(clsInputValidate::readString());

        cout << "\nEnter PIN code: ";
        client.setPINcode(clsInputValidate::readString());

        cout << "\nEnter phone: ";
        client.setPhone(clsInputValidate::readString());

        cout << "\nEnter email: ";
        client.setEmail(clsInputValidate::readString());

        cout << "\nEnter account balance: ";
        client.setAccountBalance(clsInputValidate::readFloatNumber());
    }

public:
    static void updateClient()
    {
        if (!checkAccessRights(clsUser::enPermissions::PUpdateClient))
        {
            return;
        }
        string accountNumber = "";

        _drawScreenHeader("Update Client Screen");
        cout << "\nPlease enter account number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::find(accountNumber);
        _printClient(client1);

        cout << "\n\nUpdate client info:\n"
             << "\n====================\n";

        _readClientInfo(client1);

        char choice = 'N';

        cout << "\nAre you sure to update this client? ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            clsBankClient::enSaveStatus saveStatus;

            saveStatus = client1.save();

            switch (saveStatus)
            {
            case clsBankClient::enSaveStatus::svSucceeded:
            {
                cout << "\nClient saved successfully\n";
                _printClient(client1);

                break;
            }
            case clsBankClient::enSaveStatus::svFailEmptyObject:
            {
                cout << "\nSaved failed because the object is empty!\n";

                break;
            }
            }
        }
    }
};