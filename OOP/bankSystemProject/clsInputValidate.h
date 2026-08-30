#pragma once
#include <iostream>
#include <limits>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:
    static bool isNumberBetween(short num, short from, short to)
    {
        return (num >= from && num <= to);
    }
    static bool isNumberBetween(int num, int from, int to)
    {
        return (num >= from && num <= to);
    }
    static bool isNumberBetween(float num, float from, float to)
    {
        return (num >= from && num <= to);
    }
    static bool isNumberBetween(double num, double from, double to)
    {
        return (num >= from && num <= to);
    }
    static bool isDateBetween(clsDate date1, clsDate date2, clsDate date3)
    {
        if (clsDate::isDate1AfterDate2(date1, date2) && clsDate::isDate1BeforeDate2(date1, date3) || clsDate::isDate1EqualDate2(date1, date2) || clsDate::isDate1EqualDate2(date1, date3))
        {
            return true;
        }
        else if (clsDate::isDate1AfterDate2(date2, date1) && clsDate::isDate1BeforeDate2(date3, date1) || clsDate::isDate1EqualDate2(date2, date1) || clsDate::isDate1EqualDate2(date3, date1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    static string readString()
    {
        string s;

        getline(cin >> ws, s);

        return s;
    }
    static int readIntNumber(string message = "\nInvalid number, enter again!")
    {
        int num;
        cin >> num;

        while (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << message << endl;
            cin >> num;
        }

        return num;
    }
    static double readDoubleNumber(string message = "\nInvalid number, enter again!")
    {
        double num;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << message << endl;
            cin >> num;
        }

        return num;
    }
    static float readFloatNumber(string message = "\nInvalid number, enter again!")
    {
        float num;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << message << endl;
            cin >> num;
        }

        return num;
    }
    static int readIntNumberBetween(int from, int to, string message)
    {
        int num = readIntNumber();

        while (!isNumberBetween(num, from, to))
        {
            cout << message << from << " and " << to << endl;
            num = readIntNumber("\nInvalid number! try again");
        }

        return num;
    }
    static short readShortNumberBetween(short from, short to, string message)
    {
        short num = readIntNumber();

        while (!isNumberBetween(num, from, to))
        {
            cout << message << from << " and " << to << endl;
            num = readIntNumber("\nInvalid number! try again");
        }

        return num;
    }
    static double readDblNumberBetween(double from, double to, string message)
    {
        double num = readDoubleNumber("\nInvalid number! try again");

        while (num < from || num > to)
        {
            cout << message << from << " and " << to << endl;
            cin >> num;
        }

        return num;
    }
    static bool isValidDate(clsDate date)
    {
        return clsDate::dateValidation(date);
    }
};