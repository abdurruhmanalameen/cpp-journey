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
int countFrequency(short chosenNumber, int fullNumber)
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

    return frequency;
}
void printNumbersFrequency(int fullNumber)
{
    for (int i = 0; i < 10; i++)
    {
        int frequency = countFrequency(i, fullNumber);
        if (frequency > 0)
        {
            cout << "Frequency of " << i << " is " << frequency << endl;
        }
    }
}
int main()
{
    int fullNumber = readPositiveNumber("Enter the number: ");
    printNumbersFrequency(fullNumber);
    return 0;
}