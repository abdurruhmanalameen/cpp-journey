#include <iostream>
#include <string>
using namespace std;

// #1, #2 ======================================
void printName(string name)
{
    cout << "Name: " << name << endl;
}
string readName()
{
    string name;
    cout << "Please Enter Your Name: ";
    getline(cin, name);

    return name;
}
// #3 ==========================================
enum enNumberType
{
    Odd = 1,
    Even = 2
};
int readNumber()
{
    int number;
    cout << "Enter a number to show if even or odd: ";
    cin >> number;

    return number;
}
enNumberType checkNumberType(int number)
{
    enNumberType numberType;

    if (number % 2 == 0)
        numberType = enNumberType::Even;
    else
        numberType = enNumberType::Odd;

    return numberType;
}
void printNumberType(enNumberType numberType)
{
    if (numberType == enNumberType::Even)
        cout << "The number is Even!" << endl;
    else
        cout << "The number is Odd!" << endl;
}
// #4, #5 ======================================
struct stInfo
{
    int age;
    bool hasDrivingLicense;
    bool hasRecomendation;
};
stInfo readInfo()
{
    stInfo info;

    cout << "===================Interview for a driver===================\n\n";
    cout << "Enter Your Age: ";
    cin >> info.age;

    cout << "Do You Have A Driving License? "
            "\nYes(1)"
            "\nNo(0)\n";
    cin >> info.hasDrivingLicense;

    cout << "Do You Have A Recomendation? "
            "\nYes(1)"
            "\nNo(0)\n";
    cin >> info.hasRecomendation;

    return info;
}
bool isAccepted(stInfo info)
{
    if (info.hasRecomendation)
        return true;
    else
        return (info.age > 18 && info.hasDrivingLicense);
}
void printResultOfDriver(bool status)
{
    if (status == true)
        cout << "Hired!" << endl;
    else
        cout << "Rejected" << endl;
}
int main()
{
    // printName(readName());
    // printNumberType(checkNumberType(readNumber()));
    printResultOfDriver(isAccepted(readInfo()));

    return 0;
}