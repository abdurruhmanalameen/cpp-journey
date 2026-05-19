#include <iostream>
#include <math.h>
using namespace std;

// #16 #17
void readNumbers(float &a, float &d)
{
    cout << "Enter  a: ";
    cin >> a;

    cout << "Enter d: ";
    cin >> d;
}
float calculateAreaBySideAndDiagonal(float a, float d)
{
    float area = a * sqrt(pow(d, 2) - pow(a, 2));
    return area;
}
void printArea(float area)
{
    cout << "Area = " << area << endl;
}
float triangleArea(float a, float h)
{
    float area = (a * h) / 2;
    return area;
}
// #18
float readRadios()
{
    float r;
    cout << "Enter the Radios: ";
    cin >> r;

    return r;
}
float circleArea(float r)
{
    const float PI = 3.14;
    float area = PI * pow(r, 2);

    return area;
}
// #19
float readDiameter()
{
    float d;
    cout << "Enter the diagonal: ";
    cin >> d;

    return d;
}
float circleAreaByDiameter(float d)
{
    const float PI = 3.14;
    float area = (PI * pow(d, 2)) / 4;

    return area;
}
// #20
float readSquareSide()
{
    float squareSide;
    cout << "Enter the square side: ";
    cin >> squareSide;

    return squareSide;
}
float areaOfCircleBySquareSide(float a)
{
    const float PI = 3.14;
    float area = (PI * pow(a, 2)) / 4;
    ;

    return area;
}
int main()
{
    // #16
    /*float a, d;
    readNumbers(a, d);
    float area = calculateAreaBySideAndDiagonal(a, d);
    printArea(area);*/
    // #17
    /*float a, h;
    readNumbers(a, h);
    printArea(triangleArea(a, h));*/
    // #18
    // printArea(circleArea(readRadios()));
    // #19
    // printArea(circleAreaByDiameter(readDiameter()));
    // #20
    printArea(areaOfCircleBySquareSide(readSquareSide()));
    return 0;
}