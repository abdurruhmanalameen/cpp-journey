#include <iostream>
using namespace std;

void fillArrayWithOrderedNums(short arr[3][3], short rows, short columns)
{
    short counter = 1;
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            arr[i][j] = counter;
            counter++;
        }
    }
}
void printArray(short arr[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << "\n";
    }
}
void transposedMatrix(short arr[3][3], short transposedArr[3][3], short rows, short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            transposedArr[i][j] = arr[j][i];
        }
    }
}
int main()
{
    short arr[3][3];
    short transposedArr[3][3];

    fillArrayWithOrderedNums(arr, 3, 3);

    cout << "The following is a 3x3 ordered matrix:\n";
    printArray(arr, 3, 3);

    cout << "\nThe following is the transposed matrix:\n";

    transposedMatrix(arr, transposedArr, 3, 3);
    printArray(transposedArr, 3, 3);
}