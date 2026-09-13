#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "global.h"
using namespace std;

class clsScreen
{
protected:
    static void _drawScreenHeader(string title, string subtitle = "")
    {
        system("clear");
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << title;
        if (subtitle != "")
        {
            cout << "\n\t\t\t\t\t  " << subtitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\t\t\t\t\tUser: " << currentUser.username() << endl
             << "\t\t\t\t\tDate: " << clsDate::convertDateToString(clsDate()) << endl;
    }

public:
    static bool checkAccessRights(clsUser::enPermissions permission)
    {
        if (!currentUser.checkAccessPermission(permission))
        {
            cout << "\t\t\t\t\t=====================================\n"
                 << "\n\t\t\t\t\tAccess denied contact your admin!\n\n"
                 << "\t\t\t\t\t=====================================\n";

            return false;
        }

        return true;
    }
};