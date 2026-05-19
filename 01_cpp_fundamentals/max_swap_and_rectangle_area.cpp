#include <iostream>
using namespace std;

// #11
enum enPassFail
{
    Pass = 1,
    Fail
};
void readNumbers(int &mark1, int &mark2, int &mark3)
{
    cout << "Enter 1st mark: ";
    cin >> mark1;

    cout << "Enter 2nd mark: ";
    cin >> mark2;

    cout << "Enter 3rd mark: ";
    cin >> mark3;
}
int calcSum(int mark1, int mark2, int mark3)
{
    return mark1 + mark2 + mark3;
}
float calcAvrg(int sum)
{
    return (float)sum / 3;
}
enPassFail checkAvrg(float average)
{
    enPassFail status;

    if (average >= 50)
        status = enPassFail::Pass;
    else
        status = enPassFail::Fail;

    return status;
}
void printResult(float average, enPassFail status)
{
    cout << "Your average = " << average << endl;

    if (status == enPassFail::Pass)
        cout << "You've Passed" << endl;
    else
        cout << "You've Failed" << endl;
}
// #12
void readNumbers(int &num1, int &num2)
{
    cout << "Enter number 1: ";
    cin >> num1;

    cout << "Enter number 2: ";
    cin >> num2;
}
int checkMaxNumber(int num1, int num2)
{
    if (num1 > num2)
        return num1;
    else
        return num2;
}
void printMaxNum(int max)
{
    cout << "The maximam number is: " << max << endl;
}
// #13
void read3Numbers(int &n1, int &n2, int &n3)
{
    cout << "Enter 1st number: ";
    cin >> n1;

    cout << "Enter 2nd number: ";
    cin >> n2;

    cout << "Enter 3rd number: ";
    cin >> n3;
}
int maxOf3Numbers(int n1, int n2, int n3)
{
    if (n1 > n2 && n1 > n3)
        return n1;
    else if (n2 > n3)
        return n2;
    else
        return n3;
}
void printMaxOf3(int max)
{
    cout << "Max of those numbers is: " << max << "\n";
}
// #14
void swapNumbers(int &num1, int &num2)
{
    int swap = num1;
    num1 = num2;
    num2 = swap;
}
void printNumbers(int num1, int num2)
{
    cout << "NUMBERS: \n"
         << num1 << "\n"
         << num2 << "\n";
}
// #15
void readNums(float &n1, float &n2)
{
    cout << "Enter the length: ";
    cin >> n1;

    cout << "Enter the width: ";
    cin >> n2;
}
float calcRectangleArea(float n1, float n2)
{
    return n1 * n2;
}
void printRectangleArea(float area)
{
    cout << "Area = " << area << endl;
}

int main()
{
    // #11
    /*int mark1, mark2, mark3;
    readNumbers(mark1, mark2, mark3);
    int sum = calcSum(mark1, mark2, mark3);
    float avg = calcAvrg(sum);
    enPassFail status = checkAvrg(avg);
    printResult(avg, status);*/

    // #12
    /*int num1, num2;
    readNumbers(num1, num2);
    int max = checkMaxNumber(num1, num2);
    printMaxNum(max);*/

    // #13
    /*int n1, n2, n3;
    read3Numbers(n1, n2, n3);
    int max = maxOf3Numbers(n1, n2, n3);
    printMaxOf3(max);*/

    // #14
    /*int num1, num2;
    readNumbers(num1, num2);
    printNumbers(num1, num2);
    swap(num1, num2);
    printNumbers(num1, num2);*/

    // #15
    /*float length, width;
    readNums(length, width);
    float area = calcRectangleArea(length, width);
    printRectangleArea(area);*/
    
    return 0;
}
