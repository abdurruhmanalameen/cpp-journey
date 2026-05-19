#include <iostream>
using namespace std;

// #46
void printLettersAtoZ()
{
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;
    }
}
// #47
float readPositiveNumber(string message)
{
    int number;

    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}
void totalMonths(float loanAmount, float monthlyInstallment)
{
    float total = (float)loanAmount / monthlyInstallment;
    cout << "Total Months: " << total << endl;
}
// #48
float MonthlyInstallment(float loanAmount, float howManyMonths)
{
    return (float)loanAmount / howManyMonths;
}
// #49
string readPINCode()
{
    string PIN;
    cout << "Enter Your PIN: ";
    cin >> PIN;

    return PIN;
}
void login()
{
    string PIN;
    int i = 3;

    do
    {
        i--;
        PIN = readPINCode();

        if (PIN == "1234")
        {
            cout << "\033[42m\033[97m";
            cout << "Login successfully!" << endl;
            cout << "\033[0m";
        }
        else
        {
            cout << "\033[41m\033[97m";
            cout << "Wrong PIN!" << endl;
            cout << "You have " << i << " tries left!" << "\n";

            if (i == 0)
            {
                cout << "Your Acount has been blocked call the bank for help!" << endl;
            }
        }

    } while (i >= 1 && PIN != "1234");

    cout << "\033[0m";
}
int main()
{
    // #46
    // printLettersAtoZ();
    // #47
    /*float loanAmount = readPositiveNumber("Enter loan amount: ");
    float monthlyInstallment = readPositiveNumber("Enter the monthly installment: ");
    totalMonths(loanAmount, monthlyInstallment);*/
    // #48
    /*float loanAmount = readPositiveNumber("Enter loan amount: ");
    float HowManyMonths = readPositiveNumber("Enter how many months? ");
    cout << "Monthly Installment = " << MonthlyInstallment(loanAmount, HowManyMonths) << endl;*/
    // #49
    login();

    return 0;
}