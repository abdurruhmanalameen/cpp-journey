#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsShowCurrenciesList : protected clsScreen
{
private:
    static void _printCurrencyRecordLine(clsCurrency currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << currency.country();
        cout << "| " << setw(8) << left << currency.currencyCode();
        cout << "| " << setw(45) << left << currency.currencyName();
        cout << "| " << setw(10) << left << currency.Rate();
    }
    static string prepareCurrencyLine(clsCurrency currency, string delim = "#//#")
    {
        string line = "";

        line += currency.country() += delim;
        line += currency.currencyCode() += delim;
        line += currency.currencyName() += delim;
        line += currency.Rate();

        return line;
    }

public:
    static void showCurrenciesList()
    {
        vector<clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();

        _drawScreenHeader("Show Users Screen", to_string(vCurrencies.size()) + " Currency");
        cout << "\n\t\t\t\t\tCurrencies List (" << vCurrencies.size() << ") User(s).";
        cout << "\n____________________________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";

        cout << "\n____________________________________________________________________";
        cout << "_________________________________________\n"
             << endl;

        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\tNo Currencies Available In the System!";
        }
        else
        {
            for (clsCurrency &Currency : vCurrencies)
            {
                _printCurrencyRecordLine(Currency);
                cout << endl;
            }
        }

        cout << "\n____________________________________________________________________";
        cout << "_________________________________________\n"
             << endl;
    }
};