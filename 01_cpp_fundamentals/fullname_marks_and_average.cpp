#include <iostream>
using namespace std;

// #6
struct stInfo
{
    string fName;
    string lName;
};
stInfo readFullName()
{
    stInfo info;
    cout << "Enter Your First Name: ";
    cin >> info.fName;

    cout << "Enter Your Last Name: ";
    cin >> info.lName;

    return info;
}
string getFullName(stInfo info, bool reversed)
{
    string fullName;

    if (reversed)
        fullName = info.lName + " " + info.fName;
    else
        fullName = info.fName + " " + info.lName;

    return fullName;
}
void printFullName(string fullName)
{
    cout << "Full Name: " << fullName << endl;
}
// #7
int readNumber()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    return number;
}
float calculateHalfNumber(int num)
{
    return (float)num / 2;
}
void printHalfNumber(int num)
{
    string halfOfNumber = "Half of " + to_string(num) + " is " + to_string(calculateHalfNumber(num));

    cout << halfOfNumber << endl;
}
// #8
enum enPassFail
{
    Pass = 1,
    Fail
};
int readMark()
{
    int mark;

    cout << "Please Enter Your Mark: ";
    cin >> mark;
    return mark;
}
enPassFail checkMark(int mark)
{

    if (mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}
void printMark(enPassFail status)
{
    if (status == enPassFail::Pass)
        cout << "Passed" << endl;
    else
        cout << "Failed" << endl;
}
// #9 #10
void readNumbers(int &num1, int &num2, int &num3)
{
    cout << "Enter num1: ";
    cin >> num1;

    cout << "Enter num2: ";
    cin >> num2;

    cout << "Enter num3: ";
    cin >> num3;
}
int calculateSum(int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}
float calculateAverage(int num1, int num2, int num3)
{
    return (float)calculateSum(num1, num2, num3) / 3;
}
void printResult(int sum, float average)
{
    cout << "Sum of them: " << sum << endl;
    cout << "Average of those numbers = " << average << endl;
}
int main()
{
    // printFullName(getFullName(readFullName(), true));
    //  printHalfNumber(readNumber());
    // printMark(checkMark(readMark()));
    int num1, num2, num3;
    readNumbers(num1, num2, num3);
    printResult(calculateSum(num1, num2, num3), calculateAverage(num1, num2, num3));
    return 0;
}