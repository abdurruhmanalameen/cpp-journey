#include <iostream>
using namespace std;

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
void invertedPattern(int number)
{
    for (int i = number; i > 0; i--)
    {

        for (int j = i ; j > 0; j--)
        {
            cout << i;
        }
        
        cout << endl;
    }
}
int main()
{
    int number = readPositiveNumber("Enter a positive number: ");

    invertedPattern(number);
    return 0;
    
}