#include <iostream>
using namespace std;

// #31
int readNumber()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    return number;
}
void powerOf2_3_4(int number)
{
    cout << number << "^2 = " << number * number << endl;
    cout << number << "^3 = " << number * number * number << endl;
    cout << number << "^4 = " << number * number * number * number << endl;
}
// #32
int readPower()
{
    int m;
    cout << "Enter the power: ";
    cin >> m;

    return m;
}
int powerOfM(int power, int number)
{
    int p = 1;
    if (power == 0)
    {
        return 1;
    }
    for (int i = 1; i <= power; i++)
    {
        p *= number;
    }

    return p;
}
// #33
int readNumberInRange(int from, int to)
{
    int number;

    do
    {
        cout << "Enter a number between 0 & 100: ";
        cin >> number;
    } while (number < from || number > to);

    return number;
}
char getGradeLetter(int grade)
{
    if (grade >= 90)
        return 'A';
    else if (grade >= 80)
        return 'B';
    else if (grade >= 70)
        return 'C';
    else if (grade >= 60)
        return 'D';
    else if (grade >= 50)
        return 'E';
    else
        return 'F';
}
// #34
float getCommissionPercentage(float totalSales)
{
    if (totalSales >= 1000000)
        return .01;
    else if (totalSales >= 500000)
        return .02;
    else if (totalSales >= 100000)
        return .03;
    else if (totalSales >= 50000)
        return .05;
    else
        return .00;
}
float calculateTotalCommission(float totalSales)
{
    return totalSales * getCommissionPercentage(totalSales);
}
// #35
struct stPiggyBankContent
{
    int Penny;
    int Nickel;
    int Dime;
    int Quarter;
    int Dollar;
};
stPiggyBankContent readPiggyBankContent()
{
    stPiggyBankContent PiggyBank;

    cout << "Enter Your Pennies: ";
    cin >> PiggyBank.Penny;

    cout << "Enter Your Nickels: ";
    cin >> PiggyBank.Nickel;

    cout << "Enter Your Dimes: ";
    cin >> PiggyBank.Dime;

    cout << "Enter Your Quarters: ";
    cin >> PiggyBank.Quarter;

    cout << "Enter Your Dollars: ";
    cin >> PiggyBank.Dollar;

    return PiggyBank;
}
int calculateTotalPennies(stPiggyBankContent PiggyBank)
{
    int totalPennies = PiggyBank.Penny * 1 + PiggyBank.Nickel * 5 + PiggyBank.Dime * 10 + PiggyBank.Quarter * 25 + PiggyBank.Dollar * 100;

    return totalPennies;
}
int main()
{
    // #31
    // powerOf2_3_4(readNumber());
    // #32
    // cout << powerOfM(readPower(), readNumber()) << endl;
    // #33
    /*int grade = readNumberInRange(0, 100);
    cout << "Your Grade: " << getGradeLetter(grade) << endl;*/
    // #34
    /*float totalSales = readNumber();
    cout << calculateTotalCommission(totalSales) << endl;*/
    // #35
    /*int totalPennies = calculateTotalPennies(readPiggyBankContent());
    cout << "Total Pennies = " << totalPennies << endl;
    cout << "total Dollars = " << (float)totalPennies / 100 << endl;*/
    return 0;
}