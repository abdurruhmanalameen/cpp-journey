#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _printUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.firstName();
        cout << "\nLastName    : " << User.lastName();
        cout << "\nFull Name   : " << User.fullName();
        cout << "\nEmail       : " << User.email();
        cout << "\nPhone       : " << User.phone();
        cout << "\nUsername    : " << User.username();
        cout << "\nPassword    : " << User.password();
        cout << "\nPermissions     : " << User.permissions();
        cout << "\n___________________\n";
    }
    static void _readPermissions(clsUser &userData)
    {
        char answer = 'N';

        cout << "\nDo you want to give full access? Y/N\n";
        cin >> answer;

        if (toupper(answer) == 'Y')
        {
            userData.setPermissions(PFullAccess);
        }
        else
        {
            cout << "Do you want to give access to:\n";
            cout << "Show User list? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PShowClients);
            }

            cout << "Add new User? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PAddClient);
            }

            cout << "Delete User? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PDeleteClient);
            }

            cout << "Update User? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PUpdateClient);
            }

            cout << "Find User? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PFindClient);
            }

            cout << "Transactions? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PTransactions);
            }

            cout << "Manage users? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PManageUsers);
            }

            cout << "Login register? Y/N\n";
            cin >> answer;
            if (toupper(answer) == 'Y')
            {
                userData.setPermissions(PShowLoginRegister);
            }
        }
    }
    static void _readUserInfo(clsUser &user)
    {
        cout << "\nEnter first name: ";
        user.setFirstName(clsInputValidate::readString());

        cout << "\nEnter last name: ";
        user.setLastName(clsInputValidate::readString());

        cout << "\nEnter phone: ";
        user.setPhone(clsInputValidate::readString());

        cout << "\nEnter username: ";
        user.setUsername(clsInputValidate::readString());

        cout << "\nEnter password: ";
        user.setPassword(clsInputValidate::readString());

        cout << "\nEnter email: ";
        user.setEmail(clsInputValidate::readString());

        _readPermissions(user);
    }

public:
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
        PShowLoginRegister = 128
    };
    static void updateUser()
    {
        string username = "";

        _drawScreenHeader("Update User Screen");
        cout << "\nPlease enter account number: ";
        username = clsInputValidate::readString();

        while (!clsUser::isUserExist(username))
        {
            cout << "\nAccount number is not found, choose another one: ";
            username = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(username);
        _printUser(user1);

        cout << "\n\nUpdate User info:\n"
             << "\n====================\n";

        _readUserInfo(user1);

        char choice = 'N';

        cout << "\nAre you sure to update this User? ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            clsUser::enSaveStatus saveStatus;

            saveStatus = user1.save();

            switch (saveStatus)
            {
            case clsUser::enSaveStatus::svSucceeded:
            {
                cout << "\nUser saved successfully\n";
                _printUser(user1);

                break;
            }
            case clsUser::enSaveStatus::svFailEmptyObject:
            {
                cout << "\nSaved failed because the object is empty!\n";

                break;
            }
            }
        }
    }
};