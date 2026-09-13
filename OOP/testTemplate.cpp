#include <iostream>
using namespace std;

template <typename T>
T maxNum(T num1, T num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int main()
{
    maxNum<int>(1, 2);
}