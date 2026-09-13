#pragma once

#include <iostream>
#include <string>
#include "clsString.h"
#include <vector>
#include <fstream>
class clsCurrency
{

private:
    enum enMode
    {
        emptyMode = 0,
        updateMode = 1
    };
    enMode _mode;

    string _country;
    string _currencyCode;
    string _currencyName;
    float _rate;

    static clsCurrency _convertLinetoCurrencyObject(string line, string delim = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::separateStringWords(line, delim);

        return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
                           stod(vCurrencyData[3]));
    }
    static string _convertCurrencyObjectToline(clsCurrency currency, string delim = "#//#")
    {

        string stCurrencyRecord = "";
        stCurrencyRecord += currency.country() + delim;
        stCurrencyRecord += currency.currencyCode() + delim;
        stCurrencyRecord += currency.currencyName() + delim;
        stCurrencyRecord += to_string(currency.Rate());

        return stCurrencyRecord;
    }
    static vector<clsCurrency> _loadCurrencysDataFromFile()
    {

        vector<clsCurrency> vCurrencys;

        fstream fileManager;
        fileManager.open("Currencies.txt", ios::in); // read Mode

        if (fileManager.is_open())
        {

            string line;

            while (getline(fileManager, line))
            {

                clsCurrency currency = _convertLinetoCurrencyObject(line);

                vCurrencys.push_back(currency);
            }

            fileManager.close();
        }

        return vCurrencys;
    }
    static void _saveCurrencyDataToFile(vector<clsCurrency> vCurrencys)
    {

        fstream fileManager;
        fileManager.open("Currencies.txt", ios::out); // overwrite

        string dataline;

        if (fileManager.is_open())
        {

            for (clsCurrency C : vCurrencys)
            {
                dataline = _convertCurrencyObjectToline(C);
                fileManager << dataline << endl;
            }

            fileManager.close();
        }
    }
    void _update()
    {
        vector<clsCurrency> _vCurrencys;
        _vCurrencys = _loadCurrencysDataFromFile();

        for (clsCurrency &C : _vCurrencys)
        {
            if (C.currencyCode() == currencyCode())
            {
                C = *this;
                break;
            }
        }

        _saveCurrencyDataToFile(_vCurrencys);
    }
    static clsCurrency _getEmptyCurrencyObject()
    {
        return clsCurrency(enMode::emptyMode, "", "", "", 0);
    }

public:
    clsCurrency(enMode Mode, string country, string currencyCode, string currencyName, float Rate)
    {
        _mode = Mode;
        _country = country;
        _currencyCode = currencyCode;
        _currencyName = currencyName;
        _rate = Rate;
    }
    static vector<clsCurrency> getAllUSDRates()
    {
        return _loadCurrencysDataFromFile();
    }
    bool isEmpty()
    {
        return (_mode == enMode::emptyMode);
    }
    string country()
    {
        return _country;
    }
    string currencyCode()
    {
        return _currencyCode;
    }
    string currencyName()
    {
        return _currencyName;
    }
    void updateRate(float NewRate)
    {
        _rate = NewRate;
        _update();
    }
    float Rate()
    {
        return _rate;
    }
    static clsCurrency findByCode(string currencyCode)
    {

        currencyCode = clsString::convertAllLettersToUpper(currencyCode);

        fstream fileManager;
        fileManager.open("Currencies.txt", ios::in); // read Mode

        if (fileManager.is_open())
        {
            string line;
            while (getline(fileManager, line))
            {
                clsCurrency currency = _convertLinetoCurrencyObject(line);
                if (currency.currencyCode() == currencyCode)
                {
                    fileManager.close();
                    return currency;
                }
            }

            fileManager.close();
        }

        return _getEmptyCurrencyObject();
    }
    static clsCurrency findBycountry(string country)
    {
        country = clsString::convertAllLettersToUpper(country);

        fstream fileManager;
        fileManager.open("Currencies.txt", ios::in); // read Mode

        if (fileManager.is_open())
        {
            string line;
            while (getline(fileManager, line))
            {
                clsCurrency currency = _convertLinetoCurrencyObject(line);
                if (clsString::convertAllLettersToUpper(currency.country()) == country)
                {
                    fileManager.close();
                    return currency;
                }
            }

            fileManager.close();
        }

        return _getEmptyCurrencyObject();
    }
    static bool isCurrencyExist(string currencyCode)
    {
        clsCurrency C1 = clsCurrency::findByCode(currencyCode);
        return (!C1.isEmpty());
    }
    static vector<clsCurrency> getCurrenciesList()
    {
        return _loadCurrencysDataFromFile();
    }
    double convertCurrencyToUSD(double amount)
    {
        double result = amount / Rate();

        return result;
    }
    double converttoAllCurrencies(double amount, clsCurrency currency)
    {
        double amountInUSD = convertCurrencyToUSD(amount);
        if (currency.currencyCode() == "USD")
        {
            return amountInUSD;
        }
        else
        {
            return amountInUSD * currency.Rate();
        }
    }
};
