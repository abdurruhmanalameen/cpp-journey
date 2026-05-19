#include <iostream>
using namespace std;

int readPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number < 0);

    return number;
}
void countFrequency(short chosenNumber, int fullNumber)
{
    int remainder = 0, frequency = 0;

    while (fullNumber > 0)
    {
        remainder = fullNumber % 10;
        fullNumber = fullNumber / 10;

        if (remainder == chosenNumber)
        {
            frequency++;
        }
    }
    cout << "The frequency of " << chosenNumber << " is " << frequency << " time(s)" << endl;
}
int main()
{
    int fullNumber = readPositiveNumber("Enter the full number: ");
    short int chosenNumber = readPositiveNumber("Enter the chosen number: ");

    countFrequency(chosenNumber, fullNumber);
    return 0;
}