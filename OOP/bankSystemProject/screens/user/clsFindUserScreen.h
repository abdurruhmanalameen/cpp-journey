#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
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

public:
    static void findUser()
    {
        string username = "";

        _drawScreenHeader("Find User Screen");
        cout << "\nPlease enter username: ";
        username = clsInputValidate::readString();

        while (!clsUser::isUserExist(username))
        {
            cout << "\nUsername is not found, choose another one: ";
            username = clsInputValidate::readString();
        }

        clsUser user1 = clsUser::find(username);

        if (user1.isEmpty())
        {
            cout << "\nCouldn't find the User";
        }
        else
        {
            cout << "\nThe User was found successfully";
        }

        _printUser(user1);
    }
};