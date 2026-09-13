#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalances.h"
#include "clsTransferScreen.h"
#include "clsTransferLoginScreen.h"
using namespace std;

class clsTransactionScreen : protected clsScreen
{
private:
    enum enTransactionsChoices
    {
        Deposit = 1,
        Withdraw,
        TotalBalances,
        Transfer,
        TransferLogs,
        MainMenu
    };
    static short _readTransactionOption()
    {
        short choice;

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        choice = clsInputValidate::readShortNumberBetween(1, 6, "Enter a number between 1 & 6: ");

        return choice;
    }
    static void _goBackTransactionsMenu()
    {
        cout << "\nPress Enter to go back to transactions menu...";
        cin.ignore();
        cin.get();
        showTransactionMenu();
    }
    static void _showDepositScreen()
    {
        clsDepositScreen::showDepositScreen();
    }
    static void _showWithdrawScreen()
    {
        clsWithdrawScreen::showWithdrawScreen();
    }
    static void _showTotalBalancesScreen()
    {
        clsTotalBalances::showTotalBalancesScreen();
    }
    static void _showTransferScreen()
    {
        clsTransferScreen::showTransferScreen();
    }
    static void _showTransferLogsScreen()
    {
        clsTransferLoginScreen::showTransferLogsList();
    }

    static void _performTransactionScreen()
    {
        short choice = _readTransactionOption();

        switch (enTransactionsChoices(choice))
        {
        case enTransactionsChoices::Deposit:
        {
            system("clear");
            _showDepositScreen();
            _goBackTransactionsMenu();

            break;
        }
        case enTransactionsChoices::Withdraw:
        {
            system("clear");
            _showWithdrawScreen();
            _goBackTransactionsMenu();

            break;
        }
        case enTransactionsChoices::TotalBalances:
        {
            system("clear");
            _showTotalBalancesScreen();
            _goBackTransactionsMenu();

            break;
        }
        case enTransactionsChoices::Transfer:
        {
            system("clear");
            _showTransferScreen();
            _goBackTransactionsMenu();

            break;
        }
        case enTransactionsChoices::TransferLogs:
        {
            system("clear");
            _showTransferLogsScreen();
            _goBackTransactionsMenu();
            break;
        }
        default:
        {
        }
        }
    }

public:
    static void showTransactionMenu()
    {
        if (!checkAccessRights(clsUser::enPermissions::PTransactions))
        {
            return;
        }
        _drawScreenHeader("Transaction Screen");
        cout << setw(37) << left << "" << "====================================================" << endl
             << setw(37) << left << "" << "\t\ttransaction Menu Screen\n"
             << setw(37) << left << "" << "====================================================\n"
             << setw(37) << left << "" << "\t[1] Deposit" << endl
             << setw(37) << left << "" << "\t[2] Withdraw" << endl
             << setw(37) << left << "" << "\t[3] Total balances" << endl
             << setw(37) << left << "" << "\t[4] Transfer" << endl
             << setw(37) << left << "" << "\t[5] Transfer logs" << endl
             << setw(37) << left << "" << "\t[6] Main menu" << endl
             << setw(37) << left << "" << "====================================================\n";

        _performTransactionScreen();
    }
};