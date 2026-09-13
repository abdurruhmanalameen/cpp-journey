#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
    string _value;

public:
    static char invertChar(char c)
    {
        return isupper(c) ? tolower(c) : toupper(c);
    }
    static vector<string> separateStringWords(string txt, string delim)
    {
        vector<string> vWords;
        short pos = 0;
        string word;

        while ((pos = txt.find(delim)) != std::string::npos)
        {
            word = txt.substr(0, pos);

            if (word != "")
            {
                vWords.push_back(word);
            }

            txt.erase(0, pos + delim.length());
        }

        if (txt != "")
        {
            vWords.push_back(txt);
        }

        return vWords;
    }
    static bool isVowelLetter(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }
    clsString()
    {
        _value = "";
    }
    clsString(string value)
    {
        _value = value;
    }
    void setValue(string value)
    {
        _value = value;
    }
    string getValue()
    {
        return _value;
    }
    static int countStringWords(string txt)
    {
        string delim = " ";
        short pos = 0;
        string word;
        int count = 0;

        cout << "Words of your string:\n";

        while ((pos = txt.find(delim)) != std::string::npos)
        {
            word = txt.substr(0, pos);

            if (word != "")
            {
                count++;
            }

            txt.erase(0, pos + delim.length());
        }

        if (txt != "")
        {
            count++;
        }

        return count;
    }
    int countStringWords()
    {
        return countStringWords(_value);
    }
    static string convertFirstLettersToUpper(string txt)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] != ' ' && isFirstLetter)
            {
                txt[i] = toupper(txt[i]);
            }
            isFirstLetter = (txt[i] == ' ' ? true : false);
        }
        return txt;
    }
    void convertFirstLettersToUpper()
    {
        _value = convertFirstLettersToUpper(_value);
    }
    static string deletePunctuation(string txt)
    {
        string txt2 = "";
        for (int i = 0; i < txt.length(); i++)
        {
            if (!ispunct(txt[i]))
            {
                txt2 += txt[i];
            }
        }

        return txt2;
    }
    void deletePunctuation()
    {
        _value = deletePunctuation(_value);
    }
    static void getFirstLettersOfString(string txt)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < txt.length(); i++)
        {
            if (txt.at(i) != ' ' && isFirstLetter)
            {
                cout << txt.at(i) << endl;
            }
            isFirstLetter = (txt.at(i) == ' ' ? true : false);
        }
    }
    void getFirstLettersOfString()
    {
        getFirstLettersOfString(_value);
    }
    static string convertFirstLettersToLower(string txt)
    {
        bool isFirstLetter = true;

        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] != ' ' && isFirstLetter)
            {
                txt[i] = tolower(txt[i]);
            }
            isFirstLetter = (txt[i] == ' ' ? true : false);
        }

        return txt;
    }
    void convertFirstLettersToLower()
    {
        _value = convertFirstLettersToLower(_value);
    }
    static string trimLeft(string txt)
    {

        for (int i = 0; i < txt.length(); i++)
        {
            if (txt[i] != ' ')
            {
                return txt.substr(i, txt.length() - i);
            }
        }

        return "";
    }
    void trimLeft()
    {
        _value = trimLeft(_value);
    }
    static string trimRight(string txt)
    {
        for (int i = txt.length() - 1; i >= 0; i--)
        {
            if (txt[i] != ' ')
            {
                return txt.substr(0, i + 1);
            }
        }

        return "";
    }
    void trimRight()
    {
        _value = trimRight(_value);
    }
    static int countLetter(string s, char c)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == c)
            {
                count++;
            }
        }

        return count;
    }
    int countLetter(char c)
    {
        return countLetter(_value, c);
    }
    static int counterLetterCaseSensetive(string s, char c, bool matchCase = true)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (matchCase)
            {
                if (s[i] == c)
                {
                    count++;
                }
            }
            else
            {
                if (tolower(s[i]) == tolower(c))
                {
                    count++;
                }
            }
        }

        return count;
    }
    int counterLetterCaseSensetive(char c, bool matchCase = true)
    {
        return counterLetterCaseSensetive(_value, c, matchCase);
    }
    static int countVowel(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isVowelLetter(s[i]))
            {
                count++;
            }
        }

        return count;
    }
    int countVowel()
    {
        return countVowel(_value);
    }
    static string invertString(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = invertChar(s[i]);
        }

        return s;
    }
    void invertString()
    {
        _value = invertString(_value);
    }
    static string reverseWordsInString(string txt)
    {
        string reversedS = "";
        vector<string> vString = separateStringWords(txt, " ");
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            iter--;
            reversedS += *iter + " ";
        }

        return trimRight(reversedS);
    }
    void reverseWordsInString()
    {
        _value = reverseWordsInString(_value);
    }
    static string convertAllLettersToLower(string txt)
    {
        for (int i = 0; i < txt.length(); i++)
        {
            txt[i] = tolower(txt[i]);
        }

        return txt;
    }
    void convertAllLettersToLower()
    {
        _value = convertAllLettersToLower(_value);
    }
    static string convertAllLettersToUpper(string txt)
    {
        for (int i = 0; i < txt.length(); i++)
        {
            txt[i] = toupper(txt[i]);
        }

        return txt;
    }
    void convertAllLettersToUpper()
    {
        _value = convertAllLettersToUpper(_value);
    }
};