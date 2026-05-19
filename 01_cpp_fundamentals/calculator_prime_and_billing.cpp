#include <iostream>
#include <math.h>
using namespace std;

// #36
float readNumber(string message)
{
    float number;
    cout << message << endl;

    cin >> number;

    return number;
}
enum enOperationType
{
    add = '+',
    substract = '-',
    multiply = '*',
    divide = '/'
};
enOperationType readOpType()
{
    char op;

    cout << "Choose which operator (+, -, *, /)" << endl;
    cin >> op;

    return (enOperationType)op;
}
float calculate(float n1, float n2, enOperationType op)
{
    switch (op)
    {
    case enOperationType::add:
        return n1 + n2;
    case enOperationType::substract:
        return n1 - n2;
    case enOperationType::multiply:
        return n1 * n2;
    case enOperationType::divide:
        return n1 / n2;
    default:
        return n1 + n2;
    }
}
// #37
float sumNumbers()
{
    int sum = 0, number = 0, counter = 1;

    do
    {
        number = readNumber("Please Enter number " + to_string(counter));

        if (number == -99)
        {
            break;
        }
        sum += number;
        counter++;

    } while (number != -99);

    return sum;
}
// #38
enum enPrimeNotPrime
{
    Prime = 1,
    NotPrime
};
float readPositiveNumber(string message)
{
    float number;

    do
    {
        cout << message;
        cin >> number;
    } while (number < 0);

    return number;
}
enPrimeNotPrime checkPrime(int number)
{
    int half = round(number / 2);

    for (int i = 2; i <= half; i++)
    {
        if (number % i == 0)
            return enPrimeNotPrime::NotPrime;
    }
    return enPrimeNotPrime::Prime;
}
void printNumberType(int number)
{
    if (checkPrime(number) == enPrimeNotPrime::Prime)
        cout << "Prime Number!" << endl;
    else
        cout << "Not Prime Number!" << endl;
}
// #39
float calculateRemainder(float totalBill, float totalCashPaid)
{
    return totalCashPaid - totalBill;
}
// #40
float totalBillAfterServiceAndTax(float totalBill)
{
    totalBill = totalBill * 1.1;
    totalBill = totalBill * 1.16;

    return totalBill;
}
int main()
{
    // #36
    /*int n1 = readNumber("Enter the first number: ");
    int n2 = readNumber("Enter the second number: ");
    char op = (char)readOpType();
    cout << n1 << " " << op << " " << n2 << " = " << calculate(n1, n2, (enOperationType)op) << endl;*/
    // #37
    // cout << sumNumbers() << endl;
    // #38
    // printNumberType(readPositiveNumber("Enter a positive number: "));
    // #39
    /*float totalCashPaid = readPositiveNumber("Please Enter total cash paid: ");
    float totalBill = readPositiveNumber("Please Enter total bill: ");

    cout << "\nTotal Cash Paid = " << totalCashPaid << endl;
    cout << "Total Bill = " << totalBill << endl;
    cout << "*************************************\n";
    cout << "Remainder = " << calculateRemainder(totalBill, totalCashPaid) << endl;*/
    // #40
    float totalBill = readPositiveNumber("Enter total bill: ");

    cout << "Total bill = " << totalBill << endl;
    cout << "Total bill after services fee and tax = "
         << totalBillAfterServiceAndTax(totalBill)
         << endl;
    return 0;
}