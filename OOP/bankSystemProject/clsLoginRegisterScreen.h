#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser::stLoginRegister User)
    {

        cout << "| " << setw(25) << left << User.time;
        cout << "| " << setw(15) << left << User.username;
        cout << "| " << setw(10) << left << User.password;
        cout << "| " << setw(12) << left << User.permissions;
    }

public:
    static void showLoginRegisterList()
    {
        vector<clsUser::stLoginRegister> vUsers = clsUser::getLoginRegisterList();

        if (!checkAccessRights(clsUser::enPermissions::PLoginRegister))
        {
            return;
        }
        _drawScreenHeader("Show Users Screen", to_string(vUsers.size()) + " Users");
        cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Users Available In the System!";
        }
        else
        {
            for (clsUser::stLoginRegister &User : vUsers)
            {
                _printUserRecordLine(User);
                cout << endl;
            }
        }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};