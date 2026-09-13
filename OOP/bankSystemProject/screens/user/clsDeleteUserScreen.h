#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _printUser(clsUser user)
    {
        cout << "\nuser Card:";
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

public:
    static void deleteUser()
    {
        _drawScreenHeader("Delete User Screen");
        string username = "";
        cout << "\nEnter username: ";
        username = clsInputValidate::readString();

        while (!clsUser::isUserExist(username))
        {
            cout << "\nuser not found, try again: ";
            username = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(username);

        _printUser(user1);

        char choice = 'N';
        cout << "\nAre you sure about deleting this user? Y/N ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            if (user1.deleteUser())
            {
                cout << "\nUser deleted successfully\n";
                _printUser(user1);
            }
            else
            {
                cout << "\nError couldn't delete the user!\n";
            }
        }
    }
};