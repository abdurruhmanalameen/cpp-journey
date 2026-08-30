#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsTransferLoginScreen : protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser::stTransferLog User)
    {
        cout << "| " << setw(25) << left << User.time;
        cout << "| " << setw(10) << left << User.sourceAccountNumber;
        cout << "| " << setw(10) << left << User.destinationAccountNumber;
        cout << "| " << setw(12) << left << User.amount;
        cout << "| " << setw(12) << left << User.sourceBalance;
        cout << "| " << setw(12) << left << User.destinationBalance;
        cout << "| " << setw(12) << left << User.username;
    }

public:
    static void showTransferLogsList()
    {
        vector<clsUser::stTransferLog> vUsers = clsUser::getTransferLogsList();

        _drawScreenHeader("Transfer Logs Screen");
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "From";
        cout << "| " << left << setw(10) << "To";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "SBalance";
        cout << "| " << left << setw(12) << "DBalance";
        cout << "| " << left << setw(12) << "User";

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\tNo Transfer Logs Available In the System Yet!";
        }
        else
        {
            for (clsUser::stTransferLog &User : vUsers)
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