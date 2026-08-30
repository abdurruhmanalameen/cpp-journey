#pragma once
#include <iostream>
#include <cstdlib>
#include "clsDate.h"
using namespace std;

class clsUtility
{
public:
    static int randomNumber(int from, int to)
    {
        int randomNumber = rand() % (to - from + 1) + from;

        return randomNumber;
    }
    static void Srand()
    {
        srand(time(unsigned(NULL)));
    }
    enum enCharType
    {
        capitalLetter = 1,
        smallLetter,
        digit,
        specialChar,
        mix
    };
    static void printArray(string arr[100], short numOfElements)
    {
        cout << "\nArray elements: ";
        for (int i = 0; i < numOfElements; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    static char generateRandomChar(enCharType type)
    {
        switch (type)
        {
        case capitalLetter:
        {
            return char(randomNumber(65, 90));
        }
        case smallLetter:
        {
            return char(randomNumber(97, 122));
        }
        case digit:
        {
            return char(randomNumber(48, 57));
        }
        case specialChar:
        {
            return char(randomNumber(33, 47));
        }
        default:
        {
            type = (enCharType)randomNumber(1, 3);
            return generateRandomChar(type);
        }
        }
    }
    static string numberToText(int num)
    {
        if (num < 20)
        {
            string arr[] = {
                "", "one", "two", "three", "four",
                "five", "six", "seven", "eight", "nine",
                "ten", "eleven", "twelve", "thirteen", "fourteen",
                "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

            return arr[num];
        }
        if (num >= 20 && num < 100)
        {
            string arr[] = {
                "", "", "twenty", "thirty", "forty",
                "fifty", "sixty", "seventy", "eighty", "ninety"};

            return arr[num / 10] + " " + numberToText(num % 10);
        }
        if (num >= 100 && num < 200)
        {
            return "one hundred " + numberToText(num % 100);
        }
        if (num >= 200 && num < 1000)
        {
            return numberToText(num / 100) + " Hundreds " + numberToText(num % 100);
        }
        if (num >= 1000 && num < 2000)
        {
            return "one thousand " + numberToText(num % 1000);
        }
        if (num >= 2000 && num < 1000000)
        {
            return numberToText(num / 1000) + " thousands " + numberToText(num % 1000);
        }
        if (num >= 1000000 && num < 2000000)
        {
            return "one million " + numberToText(num % 1000000);
        }
        if (num >= 2000000 && num < 1000000000)
        {
            return numberToText(num / 1000000) + " millions " + numberToText(num % 1000000);
        }
        else
        {
            return "Enough bro! :-)";
        }
    }
    static string generateWord(enCharType charType, short length)
    {
        string word;

        for (int i = 1; i <= length; i++)
        {
            word = word + generateRandomChar(charType);
        }

        return word;
    }
    static string generateKey(enCharType type)
    {
        string key;
        key = key + generateWord(type, 4) + "-";
        key = key + generateWord(type, 4) + "-";
        key = key + generateWord(type, 4) + "-";
        key = key + generateWord(type, 4);

        return key;
    }
    static void generateKeys(enCharType type, int howMany)
    {
        for (int i = 1; i <= howMany; i++)
        {
            cout << "Key [" << i << "]: ";
            cout << generateKey(type);
            cout << "\n";
        }
    }
    static void swap(int &num1, int &num2)
    {
        int swap = num1;
        num1 = num2;
        num2 = swap;
    }
    static void swap(string &s1, string &s2)
    {
        string swap = s1;
        s1 = s2;
        s2 = swap;
    }
    static void swap(double &d1, double &d2)
    {
        double swap = d1;
        d1 = d2;
        d2 = swap;
    }
    static void swap(clsDate &date1, clsDate &date2)
    {
        clsDate::swapDates(date1, date2);
    }
    static void shuffleArray(string arr[100], short arrayLength)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            swap(arr[randomNumber(0, arrayLength - 1)], arr[randomNumber(0, arrayLength - 1)]);
        }
    }
    static void shuffleArray(int arr[100], short arrayLength)
    {
        for (int i = 0; i < arrayLength; i++)
        {
            swap(arr[randomNumber(0, arrayLength - 1)], arr[randomNumber(0, arrayLength - 1)]);
        }
    }
    static void fillArrayWithRandomNumbers(int arr[100], short &numOfElements, int from, int to)
    {
        for (int i = 0; i < numOfElements; i++)
        {
            arr[i] = randomNumber(from, to);
        }
    }
    static void fillArrayWithRandomWords(string arr[100], short &numOfElements, enCharType type, int length)
    {
        for (int i = 0; i < numOfElements; i++)
        {
            arr[i] = generateWord(type, length);
        }
    }
    static void fillArrayWithRandomKeys(string arr[100], short &numOfElements, enCharType type)
    {
        for (int i = 0; i < numOfElements; i++)
        {
            arr[i] = generateKey(type);
        }
    }
    static string tabs(short numberOfTabs)
    {
        string t = "";
        for (int tabs = 1; tabs <= numberOfTabs; tabs++)
        {
            t += "\t";
        }

        return t;
    };
    static string encryption(string message, short encryptionKey = 2)
    {
        for (int i = 0; i <= message.length(); i++)
        {
            message[i] = char(int(message[i]) + encryptionKey);
        }

        return message;
    }
    static string decryption(string encryptedMessage, short encryptionKey = 2)
    {
        for (int i = 0; i <= encryptedMessage.length(); i++)
        {
            encryptedMessage[i] = char(int(encryptedMessage[i]) - encryptionKey);
        }

        return encryptedMessage;
    }
}

;
