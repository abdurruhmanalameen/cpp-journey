#pragma once
#include <iostream>
#include <stack>

using namespace std;

class clsMyString
{
private:
    stack<string> _undo;
    stack<string> _redo;
    string _value;

public:
    void setValue(string value)
    {
        _undo.push(_value);
        _value = value;
    }
    string getValue()
    {
        return _value;
    }

    void undo()
    {
        if (!_undo.empty())
        {
            _redo.push(_value);
            _value = _undo.top();
            _undo.pop();
        }
    }
    void redo()
    {
        if (!_redo.empty())
        {
            _undo.push(_value);
            _value = _redo.top();
            _redo.pop();
        }
    }
};