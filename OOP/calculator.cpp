#include <iostream>
using namespace std;

class clsCalculator
{
private:
    float _result = 0;
    float _lastResult = 0;
    float _userNumber = 0;
    string choice;
    bool isZero(float number)
    {
        return number == 0;
    }

public:
    void add(float num)
    {
        _lastResult = _result;
        _result += num;
        choice = "Adding";
        _userNumber = num;
    }
    void subtract(float num)
    {
        _lastResult = _result;
        _result -= num;
        choice = "Subtracting";
        _userNumber = num;
    }
    void multiply(float num)
    {
        _lastResult = _result;
        _result *= num;
        choice = "Multiplying";
        _userNumber = num;
    }
    void divide(float num)
    {
        if (isZero(num))
        {
            num = 1;
        }
        _lastResult = _result;
        _result /= num;
        choice = "Dividing";
        _userNumber = num;
    }
    void clear()
    {
        _lastResult = 0;
        _userNumber = 0;
        _result = 0;
        choice = "Clearing";
    }
    void cancelLastOperation()
    {
        _result = _lastResult;
        _userNumber = 0;
        choice = "Canceling";
    }
    void printResult()
    {
        cout << "\nResult after " << choice << " " << _userNumber << " is " << _result << endl;
    }
};

int main()
{
    clsCalculator calculator1;

    calculator1.clear();
    calculator1.add(100);
    calculator1.printResult();

    calculator1.multiply(3);
    calculator1.printResult();

    calculator1.divide(3);
    calculator1.printResult();

    calculator1.subtract(1);
    calculator1.printResult();

    calculator1.clear();
    calculator1.printResult();

    calculator1.cancelLastOperation();
    calculator1.printResult();

    return 0;
}