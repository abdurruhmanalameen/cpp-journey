#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>

class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _printUser(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << user.firstName();
        cout << "\nLastName    : " << user.lastName();
        cout << "\nFull Name   : " << user.fullName();
        cout << "\nEmail       : " << user.email();
        cout << "\nPhone       : " << user.phone();
        cout << "\nUsername    : " << user.username();
        cout << "\nPassword    : " << user.password();
        cout << "\nPermissions     : " << user.permissions();
        cout << "\n___________________\n";
    }
    static void _readUserInfo(clsUser &user)
    {
        cout << "\nEnter first name: ";
        user.setFirstName(clsInputValidate::readString());

        cout << "\nEnter last name: ";
        user.setLastName(clsInputValidate::readString());

        cout << "\nEnter phone: ";
        user.setPhone(clsInputValidate::readString());

        cout << "\nEnter Password: ";
        user.setPassword(clsInputValidate::readString());

        cout << "\nEnter email: ";
        user.setEmail(clsInputValidate::readString());

        _readPermissions(user);
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

    static void addNewUser()
    {
        clsScreen::_drawScreenHeader("Add New User Screen");
        string username = "";
        cout << "\nEnter the username: ";
        username = clsInputValidate::readString();

        while (clsUser::isUserExist(username))
        {
            cout << "This user is already exists enter another one: ";
            username = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::getAddNewClinet(username);

        _readUserInfo(user1);

        clsUser::enSaveStatus status;

        status = user1.save();

        switch (status)
        {
        case clsUser::enSaveStatus::svSucceeded:
        {
            cout << "\nuser saved successfully\n";
            _printUser(user1);

            break;
        }
        case clsUser::enSaveStatus::svFailEmptyObject:
        {
            cout << "\nSaved failed because the object is empty!\n";

            break;
        }
        case clsUser::enSaveStatus::svFailedAlreadyUsed:
        {
            cout << "\nSaved failed this account is already used\n";

            break;
        }
        }
    }
};