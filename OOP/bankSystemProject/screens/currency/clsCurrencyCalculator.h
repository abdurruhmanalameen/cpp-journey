#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
using namespace std;

class clsCurrencyCalculator : protected clsScreen
{
private:
    static void _printCurrencyInfo(clsCurrency currency)
    {
        cout << "\n___________________";
        cout << "\nCountry: " << currency.country();
        cout << "\nCode   : " << currency.currencyCode();
        cout << "\nName   : " << currency.currencyName();
        cout << "\nRate($): " << currency.Rate();
        cout << "\n___________________\n";
    }
    static string _readCurrency(string code)
    {
        code = clsInputValidate::readString();

        while (!clsCurrency::isCurrencyExist(code))
        {
            cout << "Couldn't find the currency, try again: ";
            code = clsInputValidate::readString();
        }

        return code;
    }

    static void _printConvertCurrencyResult(double amount, clsCurrency currencyFrom, clsCurrency currencyTo)
    {
        double amountInUSD = currencyFrom.convertCurrencyToUSD(amount);

        cout << "\nConvert From " << currencyFrom.currencyCode() << " to USD:\n";
        _printCurrencyInfo(currencyFrom);
        cout << amount << " " << currencyFrom.currencyCode() << " = " << amountInUSD << " USD" << endl;

        if (currencyTo.currencyCode() == "USD")
        {
            return;
        }

        cout << "\nConvert from USD To " << currencyTo.currencyCode() << ":\n";
        _printCurrencyInfo(currencyTo);
        cout << amount << " " << currencyFrom.currencyCode() << " = " << currencyFrom.converttoAllCurrencies(amount, currencyTo) << " " << currencyTo.currencyCode() << endl;
    }

public:
    static void showCurrencyCalculator()
    {
        char choice = 'Y';

        while (toupper(choice) == 'Y')
        {
            _drawScreenHeader("Currency Calculator Screen");

            string c1Code;
            string c2Code;
            double amount;

            cout << "\nEnter Currency1 code: ";
            clsCurrency currencyFrom = clsCurrency::findByCode(_readCurrency(c1Code));

            cout << "\nEnter Currency2 code: ";
            clsCurrency currencyTo = clsCurrency::findByCode(_readCurrency(c2Code));

            cout << "\nEnter the amount to convert: ";
            amount = clsInputValidate::readDoubleNumber();

            _printConvertCurrencyResult(amount, currencyFrom, currencyTo);

            cout << "Do you want to perform another calculation? Y/N ";
            cin >> choice;
        }
    }
};
