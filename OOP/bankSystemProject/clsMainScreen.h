#pragma once
#include <iostream>
#include <iomanip>
#include "global.h"
#include "clsScreen.h"
#include "clsClientsListScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClients = 1,
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eLoginRegister = 8,
        eExit = 9
    };

    static short _readMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";
        short Choice = clsInputValidate::readShortNumberBetween(1, 9, "Enter Number between 1 to 9? ");
        return Choice;
    }
    static void _goBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress Enter to go back to main menu...\n";

        cin.ignore();
        cin.get();
        showMainMenu();
    }

    static void _showAllClientsScreen()
    {
        clsClientsListScreen::showClientsList();
    }
    static void _showAddNewClientsScreen()
    {
        clsAddNewClient::addNewClient();
    }
    static void _showDeleteClientScreen()
    {
        clsDeleteClient::deleteClient();
    }
    static void _showUpdateClientScreen()
    {
        clsUpdateClient::updateClient();
    }
    static void _showFindClientScreen()
    {
        clsFindClient::findClient();
    }
    static void _showTransactionsMenu()
    {
        clsTransactionScreen::showTransactionMenu();
    }
    static void _showManageUsersMenu()
    {
        clsManageUsersScreen::showManageUserScreen();
    }
    static void _showLoginRegister()
    {
        clsLoginRegisterScreen::showLoginRegisterList();
    }
    static void _logout()
    {
        currentUser = clsUser::find("", "");
    }
    static void _performMainMenuOption(enMainMenuOptions mainMenuOption)
    {
        switch (mainMenuOption)
        {
        case enMainMenuOptions::eListClients:
        {
            system("clear");
            _showAllClientsScreen();
            _goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
            system("clear");
            _showAddNewClientsScreen();
            _goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            system("clear");
            _showDeleteClientScreen();
            _goBackToMainMenu();
            break;
        }

        case enMainMenuOptions::eUpdateClient:
        {
            system("clear");
            _showUpdateClientScreen();
            _goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            system("clear");
            _showFindClientScreen();
            _goBackToMainMenu();
            break;
        }

        case enMainMenuOptions::eShowTransactionsMenu:
        {
            system("clear");
            _showTransactionsMenu();
            _goBackToMainMenu();
            break;
        }

        case enMainMenuOptions::eManageUsers:
        {
            system("clear");
            _showManageUsersMenu();
            _goBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eLoginRegister:
        {
            system("clear");
            _showLoginRegister();
            _goBackToMainMenu();
            break;
        }

        case enMainMenuOptions::eExit:
        {
            system("clear");
            // _showEndScreen();
            // Login();
            _logout();
        }
        break;
        }
    }
    static void _drawMainMenuScreen()
    {
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }

public:
    static void showMainMenu()
    {

        system("clear");
        _drawScreenHeader("\t\tMain Screen");

        _drawMainMenuScreen();
        _performMainMenuOption((enMainMenuOptions)_readMainMenuOption());
    }
};