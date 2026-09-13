#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iostream>

class clsAddNewClient : protected clsScreen
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
    static void addNewClient()
    {
        if (!checkAccessRights(clsUser::enPermissions::PAddClient))
        {
            return;
        }
        clsScreen::_drawScreenHeader("Add New Client Screen");
        string accountNumber = "";
        cout << "\nEnter the account number: ";
        accountNumber = clsInputValidate::readString();

        while (clsBankClient::isClientExist(accountNumber))
        {
            cout << "This client is already exists enter another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client1 = clsBankClient::getAddNewClinet(accountNumber);

        _readClientInfo(client1);

        clsBankClient::enSaveStatus status;

        status = client1.save();

        switch (status)
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
        case clsBankClient::enSaveStatus::svFailedAlreadyUsed:
        {
            cout << "\nSaved failed this account is already used\n";

            break;
        }
        }
    }
};