#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsUsersListScreen : protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser User)
    {

        cout << "| " << setw(15) << left << User.username();
        cout << "| " << setw(20) << left << User.fullName();
        cout << "| " << setw(12) << left << User.phone();
        cout << "| " << setw(20) << left << User.email();
        cout << "| " << setw(10) << left << User.password();
        cout << "| " << setw(12) << left << User.permissions();
    }

public:
    static void showUsersList()
    {
        vector<clsUser> vUsers = clsUser::getUsersList();

        _drawScreenHeader("Show Users Screen", to_string(vUsers.size()) + " Users");
        cout << "\n\t\t\t\t\tUser List (" << vUsers.size() << ") User(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(20) << "Username";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
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
            for (clsUser &User : vUsers)
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