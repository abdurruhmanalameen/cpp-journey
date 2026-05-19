#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType
{
    capitalLetter = 1,
    smallLetter,
    specialChar,
    digit
};
int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
int readPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}
char getRandomCharacter(enCharType charType)
{
    switch (charType)
    {
    case enCharType::capitalLetter:
        return char(randomNumber(65, 90));
    case enCharType::smallLetter:
        return char(randomNumber(97, 122));
    case enCharType::specialChar:
        return char(randomNumber(33, 47));
    default:
        return randomNumber(48, 57);
    }
}
string generateWord(enCharType charType, short length)
{
    string word;

    for (int i = 1; i <= length; i++)
    {
        word = word + getRandomCharacter(charType);
    }

    return word;
}
string generateKey()
{
    string key;
    key = key + generateWord(enCharType::capitalLetter, 4) + "-";
    key = key + generateWord(enCharType::capitalLetter, 4) + "-";
    key = key + generateWord(enCharType::capitalLetter, 4) + "-";
    key = key + generateWord(enCharType::capitalLetter, 4);

    return key;
}
void generateKeys(int howMany)
{
    for (int i = 1; i <= howMany; i++)
    {
        cout << "Key [" << i << "]: ";
        cout << generateKey();
        cout << "\n";
    }
}

int main()
{
    srand(unsigned(time(NULL)));

    generateKeys(readPositiveNumber("How many keys do you want? "));
    return 0;
}