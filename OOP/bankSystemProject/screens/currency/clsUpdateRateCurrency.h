#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsUpdateRateCurrency : protected clsScreen
{
private:
    static void _printCurrencyInfo(clsCurrency currency)
    {
        cout << "\nCurrency card:";
        cout << "\n___________________";
        cout << "\nCountry: " << currency.country();
        cout << "\nCode   : " << currency.currencyCode();
        cout << "\nName   : " << currency.currencyName();
        cout << "\nRate($): " << currency.Rate();
        cout << "\n___________________\n";
    }
    static void _showResult(clsCurrency currency)
    {
        if (!currency.isEmpty())
        {
            _printCurrencyInfo(currency);
        }
        else
        {
            cout << "\nCurrency not found!\n";
        }
    }

public:
    static void updateRate()
    {
        _drawScreenHeader("Update Currency Screen");

        string code;
        cout << "Please enter the currency code: ";
        code = clsInputValidate::readString();

        while (!clsCurrency::isCurrencyExist(code))
        {
            cout << "Couldn't find the currency, try again: ";
            code = clsInputValidate::readString();
        }
        clsCurrency currency = clsCurrency::findByCode(code);

        _showResult(currency);

        char choice = 'N';
        cout << "\nAre you sure you want to update the rate of this currency y/n? ";
        cin >> choice;

        if (toupper(choice) == 'Y')
        {
            double newRate = 0;
            cout << "\nUpdate Currency Rate:\n"
                 << "_____________________\n"
                 << "Enter New Rate: ";
            newRate = clsInputValidate::readDoubleNumber();

            currency.updateRate(newRate);

            cout << "\nRate updated successfully:\n";
            _printCurrencyInfo(currency);
        }
        else
        {
            cout << "\nCancelled Successfully!\n";
            return;
        }
    }
};