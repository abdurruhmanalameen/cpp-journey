#include <iostream>
using namespace std;

int readNumber(string message)
{
    int number;

    cout << message << endl;
    cin >> number;

    return number;
}
string numberToText(int num)
{
    if (num < 20)
    {
        string arr[] = {
            "", "one", "two", "three", "four",
            "five", "six", "seven", "eight", "nine",
            "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

        return arr[num];
    }
    if (num >= 20 && num < 100)
    {
        string arr[] = {
            "", "", "twenty", "thirty", "forty",
            "fifty", "sixty", "seventy", "eighty", "ninety"};

        return arr[num / 10] + " " + numberToText(num % 10);
    }
    if (num >= 100 && num < 200)
    {
        return "one hundred " + numberToText(num % 100);
    }
    if (num >= 200 && num < 1000)
    {
        return numberToText(num / 100) + " Hundreds " + numberToText(num % 100);
    }
    if (num >= 1000 && num < 2000)
    {
        return "one thousand " + numberToText(num % 1000);
    }
    if (num >= 2000 && num < 1000000)
    {
        return numberToText(num / 1000) + " thousands " + numberToText(num % 1000);
    }
    if (num >= 1000000 && num < 2000000)
    {
        return "one million " + numberToText(num % 1000000);
    }
    if (num >= 2000000 && num < 1000000000)
    {
        return numberToText(num / 1000000) + " millions " + numberToText(num % 1000000);
    }
    else
    {
        return "Enough bro! :-)";
    }
}
int main()
{
    int number = readNumber("Enter a number: ");

    cout << numberToText(number) << endl;

    return 0;
}