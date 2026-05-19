#include <iostream>
using namespace std;

void printHeaderTable()
{
    cout << "\n\t\t\t" << "Multiplication Table from 1 to 10\n\n";
    for (int i = 1; i <= 10; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n__________________________________________________________________________________\n";
}
string printSeparator(int i)
{
    if (i < 10)
    {
        return "    |  ";
    }
    else
    {
        return "   |  ";
    }
}
void printMultiplicationTable()
{
    printHeaderTable();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << printSeparator(i);
        for (int j = 1; j <= 10; j++)
        {
            cout << j * i << "\t";
        }
        cout << "\n";
    }
}

int main()
{
    printMultiplicationTable();
    return 0;
}