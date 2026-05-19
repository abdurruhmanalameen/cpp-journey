#include <iostream>
#include <cstdlib>
using namespace std;

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}
enum enTypeOfChar
{
    SmallLetter = 1,
    CapitalLetter,
    SpecialCharacter,
    Digit
};
void generateRandomChar(enTypeOfChar type)
{
    int from, to;

    if (type == enTypeOfChar::CapitalLetter)
    {
        from = 65;
        to = 90;
    }
    else if (type == enTypeOfChar::SmallLetter)
    {
        from = 97;
        to = 122;
    }
    else if (type == enTypeOfChar::Digit)
    {
        from = 48;
        to = 57;
    }
    else
    {
        from = 33;
        to = 47;
    }

    cout << char(randomNumber(from, to)) << endl;
}
int main()
{
    srand(unsigned(time(NULL)));

    generateRandomChar(enTypeOfChar::SmallLetter);
    generateRandomChar(enTypeOfChar::CapitalLetter);
    generateRandomChar(enTypeOfChar::SpecialCharacter);
    generateRandomChar(enTypeOfChar::Digit);


    return 0;
}