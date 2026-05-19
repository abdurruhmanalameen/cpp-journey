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
bool checkPerfectOrNot(int number)
{
    int sum = 0;
    
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
   
    return sum == number;
}
void printPerfectOrNot(int number)
{
    if (checkPerfectOrNot(number))
    {
        cout << number << " is perfect" << endl;
    }
    else
    {
        cout << number << " is not perfect" << endl;
    }
}
int main()
{
    printPerfectOrNot(readPositiveNumber("Enter a number to check if perfect or not: "));
    return 0;
}