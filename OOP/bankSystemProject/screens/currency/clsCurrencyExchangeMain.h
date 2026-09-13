#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowCurrenciesList.h"
#include "clsFindCurrency.h"
#include "clsUpdateRateCurrency.h"
#include "clsCurrencyCalculator.h"
using namespace std;

class clsCurrencyExchangeMain : protected clsScreen
{
private:
    enum enCurrencyExchangeOptions
    {
        ListCurrencies = 1,
        FindCurrency,
        UpdateRate,
        CurrencyCalculator,
        goBackMainMenu
    };
    static short _readCurrencyOptions()
    {
        short option;

        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]";
        option = clsInputValidate::readShortNumberBetween(1, 5, "Only numbers between 1, 5 are allowed: ");

        return option;
    }
    static void _drawCurrencyExchangeScreen()
    {
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }
    static void _showListCurrenciesScreen()
    {
        clsShowCurrenciesList::showCurrenciesList();
    }
    static void _showFindCurrencyScreen()
    {
        clsFindCurrency::findCurrency();
    }
    static void _showUpdateRateScreen()
    {
        clsUpdateRateCurrency::updateRate();
    }
    static void _showCurrencyCalculatorScreen()
    {
        clsCurrencyCalculator::showCurrencyCalculator();
    }
    static void _goBackMainMenuScreen()
    {
        cout << "\nPress Enter to go back to Main menu...";
        cin.ignore();
        cin.get();
        showCurrencyExchangeMainScreen();
    }
    static void _performCurrencyExchangeOptions(enCurrencyExchangeOptions option)
    {
        switch (option)
        {
        case ListCurrencies:
        {
            system("clear");
            _showListCurrenciesScreen();
            _goBackMainMenuScreen();
            break;
        }
        case FindCurrency:
        {
            system("clear");
            _showFindCurrencyScreen();
            _goBackMainMenuScreen();
            break;
        }
        case UpdateRate:
        {
            system("clear");
            _showUpdateRateScreen();
            _goBackMainMenuScreen();
            break;
        }
        case CurrencyCalculator:
        {
            system("clear");
            _showCurrencyCalculatorScreen();
            _goBackMainMenuScreen();
            break;
        }
        default:
        {
        }
        }
    }

public:
    static void showCurrencyExchangeMainScreen()
    {
        _drawScreenHeader("Currency Exchange Menu");
        _drawCurrencyExchangeScreen();
        _performCurrencyExchangeOptions(enCurrencyExchangeOptions(_readCurrencyOptions()));
    }
};