#include <iostream>
#include <math.h>
using namespace std;

// #21
float readCircumference()
{
    float l;
    cout << "Enter the circumference: ";
    cin >> l;

    return l;
}
float circleAreaByCircumference(float l)
{
    const float PI = 3.141592653589793238;
    float area = (pow(l, 2)) / (4 * PI);

    return area;
}
void printArea(float area)
{
    cout << "Area: " << area << "\n";
}
// #22
void readTriangleData(float &a, float &b)
{
    cout << "Enter triangle side a and b ";
    cin >> a >> b;
}
float circleAreaByTriangle(float a, float b)
{
    const float PI = 3.141592653589793238;
    float area = PI * pow(b, 2) / 4 * (2 * a - b) / (2 * a + b);

    return area;
}
// #23
void readTriangleData(float &a, float &b, float &c)
{
    cout << "Enter triangle sides a, b, c: ";
    cin >> a >> b >> c;
}
float circleByATriangle(float a, float b, float c)
{
    const float PI = 3.141592653589793238;
    float P = (a + b + c) / 2;
    float area = PI * pow((a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c))), 2);

    return area;
}
// #24 #25
int readAge()
{
    int age;
    cout << "Enter your age between 18 & 45: ";
    cin >> age;

    return age;
}
bool checkNumberBetweenRange(int number, int from, int to)
{
    return (number >= from && number <= to);
}
int ReadUntilAgeBetween(int from, int to)
{
    int age;
    do
    {
        age = readAge();
    } while (!checkNumberBetweenRange(age, from, to));

    return age;
}
void printResult(int age)
{
    /*if (checkNumberBetweenRange(age, 18, 45))
        cout << "Valid age" << endl;
    else
        cout << "Invalid age" << endl;*/
    cout << "Your age is: " << age << endl;
}
int main()
{
    // #21
    // printArea(circleAreaByCircumference(readCircumference()));
    // #22
    /*float a, b;
    readTriangleData(a, b);
    printArea(circleAreaByTriangle(a, b));*/
    // #23
    /*float a, b, c;
    readTriangleData(a, b, c);
    printArea(circleByATriangle(a, b, c));*/
    // #24
    // printResult(readAge());
    // #25
    printResult(ReadUntilAgeBetween(18, 45));
    return 0;
}