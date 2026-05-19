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
void fillArrayWithKeys(string arr[100], short arrayLength)
{
    for (int i = 0; i <= arrayLength; i++)
    {
        arr[i] = generateKey();
    }
}
void printStringArray(string arr[100], short arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Array [" << i << "]: ";
        cout << arr[i];
        cout << "\n";
    }
    cout << endl;
}

int main()
{
    srand(unsigned(time(NULL)));

    string arr[100];
    int arrayLength = readPositiveNumber("How many keys do you want? ");

    fillArrayWithKeys(arr, arrayLength);
    printStringArray(arr, arrayLength);

    return 0;
}