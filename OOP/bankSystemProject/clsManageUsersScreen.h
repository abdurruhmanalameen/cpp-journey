#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
    static void _goBackManageUsersScreen()
    {
        cout << "\nPress Enter to go back to transactions menu...";
        cin.ignore();
        cin.get();
        showManageUserScreen();
    }
    static void _listAllUsers()
    {
        clsUsersListScreen::showUsersList();
    };
    static void _addUsers()
    {
        clsAddNewUserScreen::addNewUser();
    };
    static void _deleteUserFromFile()
    {
        clsDeleteUserScreen::deleteUser();
    };
    static void _findUser()
    {
        clsFindUserScreen::findUser();
    };
    static void _updateUserFromFile()
    {
        clsUpdateUserScreen::updateUser();
    };
    static short _readManageUsersOption()
    {
        short choice;

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        choice = clsInputValidate::readShortNumberBetween(1, 6, "Enter a number between 1 & 6: ");

        return choice;
    }
    static void _performManageUsersScreen(short choice)
    {
        switch (enManageUsersChoices(choice))
        {
        case enManageUsersChoices::ListUsers:
        {
            _listAllUsers();
            _goBackManageUsersScreen();

            break;
        }
        case enManageUsersChoices::AddNewUser:
        {
            _addUsers();
            _goBackManageUsersScreen();

            break;
        }
        case enManageUsersChoices::DeleteUser:
        {

            _deleteUserFromFile();
            _goBackManageUsersScreen();

            break;
        }
        case enManageUsersChoices::FindUser:
        {
            _findUser();
            _goBackManageUsersScreen();

            break;
        }
        case enManageUsersChoices::UpdateUser:
        {
            _updateUserFromFile();
            _goBackManageUsersScreen();

            break;
        }
        default:
        {
        }
        }
    }

public:
    enum enManageUsersChoices
    {
        ListUsers = 1,
        AddNewUser,
        DeleteUser,
        FindUser,
        UpdateUser,
        GoBackMainMenu
    };
    static void showManageUserScreen()
    {
        if (!checkAccessRights(clsUser::enPermissions::PManageUsers))
        {
            return;
        }
        _drawScreenHeader("Manage Users Screen");

        cout << setw(37) << left << "" << "====================================================" << endl
             << setw(37) << left << "" << "              Manage Users Screen\n"
             << setw(37) << left << "" << "====================================================\n"
             << setw(37) << left << "" << "              [1] List users" << endl
             << setw(37) << left << "" << "              [2] Add a new user" << endl
             << setw(37) << left << "" << "              [3] Delete user" << endl
             << setw(37) << left << "" << "              [4] Find user" << endl
             << setw(37) << left << "" << "              [5] Update user" << endl
             << setw(37) << left << "" << "              [6] Go back to main menu" << endl
             << setw(37) << left << "" << "====================================================\n";

        _performManageUsersScreen(_readManageUsersOption());
    }
};