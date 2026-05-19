#include <iostream>
using namespace std;

// #26 #27
int readNumber()
{
    int number;
    cout << "Please Enter a number: ";
    cin >> number;

    return number;
}
void printRangeFrom1toN_usingWhile(int n)
{
    int counter = n;

    cout << "Range printed using while statement: \n";

    while (counter > 0)
    {
        cout << counter << endl;
        counter--;
    }
}
void printRangeFrom1toN_usingDoWhile(int n)
{
    int counter = n;

    cout << "Range printed using do while statement: \n";

    do
    {
        cout << counter << endl;
        counter--;
    } while (counter > 0);
}
void printRangeFrom1toN_usingFor(int n)
{
    cout << "Range printed using for statement: \n";

    for (int counter = n; counter > 0; counter--)
    {
        cout << counter << endl;
    }
}
// #28
enum oddOrEven
{
    Odd = 1,
    Even = 2
};
oddOrEven checkOddOrEven(int number)
{
    if (number % 2 == 0)
        return oddOrEven::Even;
    else
        return oddOrEven::Odd;
}
int sumOddNumbersFrom1toN_usingFor(int N)
{
    int sum = 0;

    cout << "Sum of odd numbers using for = ";

    for (int counter = 1; counter <= N; counter++)
    {
        if (checkOddOrEven(counter) == oddOrEven::Odd)
        {
            sum += counter;
        }
    }

    return sum;
}
int sumOddNumbersFrom1toN_usingWhile(int N)
{
    int sum = 0;
    int counter = 0;

    cout << "Sum of odd numbers using while = ";

    while (counter < N)
    {
        counter++;
        if (checkOddOrEven(counter) == oddOrEven::Odd)
        {
            sum += counter;
        }
    }

    return sum;
}
int sumOddNumbersFrom1toN_usingDoWhile(int N)
{
    int sum = 0;
    int counter = 1;

    cout << "Sum of odd number using do while = ";

    do
    {
        if (checkOddOrEven(counter) == oddOrEven::Odd)
        {
            sum += counter;
        }
        counter++;
    } while (counter <= N);

    return sum;
}
// #29
int sumEvenNumbersFrom1toN_usingFor(int N)
{
    int sum = 0;

    cout << "Sum of even numbers using for = ";

    for (int counter = 1; counter <= N; counter++)
    {
        if (checkOddOrEven(counter) == oddOrEven::Even)
        {
            sum += counter;
        }
    }

    return sum;
}
int sumEvenNumbersFrom1toN_usingWhile(int N)
{
    int sum = 0;
    int counter = 0;

    cout << "Sum of even numbers using while = ";

    while (counter < N)
    {
        counter++;
        if (checkOddOrEven(counter) == oddOrEven::Even)
        {
            sum += counter;
        }
    }

    return sum;
}
int sumEvenNumbersFrom1toN_usingDoWhile(int N)
{
    int sum = 0;
    int counter = 1;

    cout << "Sum of even number using do while = ";

    do
    {
        if (checkOddOrEven(counter) == oddOrEven::Even)
        {
            sum += counter;
        }
        counter++;
    } while (counter <= N);

    return sum;
}
// #30
int readPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);

    return number;
}
int factorial(int n)
{
    int f = 1;

    for (int i = n; i >= 1; i--)
    {
        f = f * i;
    }

    return f;
}
int main()
{
    // int n = readNumber();
    // #26 #27
    /*printRangeFrom1toN_usingWhile(n);
    printRangeFrom1toN_usingDoWhile(n);
    printRangeFrom1toN_usingFor(n);*/
    // #28
    /*cout << sumOddNumbersFrom1toN_usingFor(n) << endl;
    cout << sumOddNumbersFrom1toN_usingWhile(n) << endl;
    cout << sumOddNumbersFrom1toN_usingDoWhile(n) << endl;*/
    // #29
    /*cout << sumEvenNumbersFrom1toN_usingFor(n) << endl;
    cout << sumEvenNumbersFrom1toN_usingWhile(n) << endl;
    cout << sumEvenNumbersFrom1toN_usingDoWhile(n) << endl;*/
    // #30
    cout << factorial(readPositiveNumber("Enter a positive number: ")) << "\n";
    return 0;
}