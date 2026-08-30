#pragma once
#include <iostream>
#include "clsMainScreen.h"
#include "clsDate.h"
#include "global.h"

class clsLoginScreen : protected clsScreen
{
private:
    static bool _login()
    {
        string username, password;

        bool loginFailed = false;
        short trials = 3;

        do
        {

            if (loginFailed)
            {
                trials--;

                if (trials == 0)
                {
                    cout << "\n\nYou are locked after three failed trials!\n";
                    return false;
                }

                cout << "\nInvalid username & password!\n";
                cout << "You have " << trials << " trials to login.\n";
            }

            cout << "\nEnter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            currentUser = clsUser::find(username, password);

            loginFailed = currentUser.isEmpty();

        } while (loginFailed);

        currentUser.loginRegister();
        clsMainScreen::showMainMenu();

        return true;
    }
    static void loginRegister()
    {
    }

public:
    static bool showLoginScreen()
    {
        _drawScreenHeader("LOGIN SCREEN");
        return _login();
    }
};