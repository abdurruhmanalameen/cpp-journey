#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsScreen.h"
using namespace std;

class clsFindCurrency : protected clsScreen
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
            cout << "\nCurrency found\n";
            _printCurrencyInfo(currency);
        }
        else
        {
            cout << "\nCurrency not found!\n";
        }
    }

public:
    static void findCurrency()
    {
        _drawScreenHeader("Find Currency Screen");
        short option;
        cout << "Find by [1]Code [2]Country? ";
        option = clsInputValidate::readShortNumberBetween(1, 2, "Invalid input! try again: ");

        if (option == 1)
        {
            string code;
            cout << "Enter the code: ";
            code = clsInputValidate::readString();

            clsCurrency currency1 = clsCurrency::findByCode(code);

            _showResult(currency1);
        }
        else
        {
            cout << "Enter the country: ";
            string country;
            country = clsInputValidate::readString();

            clsCurrency currency1 = clsCurrency::findBycountry(country);

            _showResult(currency1);
        }
    }
};
