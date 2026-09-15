#pragma once
#include <iostream>

using namespace std;
template <class T>

class clsMyDynamicArray
{
protected:
    int _size = 0;
    T *_originalArray;
    T *_tempArray;

public:
    clsMyDynamicArray(int size = 0)
    {
        if (size < 0)
        {
            size = 0;
        }
        _size = size;

        _originalArray = new T[_size];
    }
    ~clsMyDynamicArray()
    {
        delete[] _originalArray;
    }
    bool setItem(int index, T value)
    {
        if (index >= _size || index < 0)
        {
            return false;
        }

        _originalArray[index] = value;

        return true;
    }
    bool isEmpty()
    {
        return _size == 0 ? true : false;
    }
    void print()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << _originalArray[i] << " ";
        }
        cout << endl;
    }
    void resize(int newSize)
    {
        if (newSize < 0)
        {
            newSize = 0;
        }

        _tempArray = new T[newSize];

        if (newSize < _size)
        {
            _size = newSize;
        }

        for (int i = 0; i < _size; i++)
        {
            _tempArray[i] = _originalArray[i];
        }

        _size = newSize;
        delete[] _originalArray;

        _originalArray = _tempArray;
    }
    T getItem(int index)
    {
        if (index < 0 || index > _size - 1)
        {
            index = 0;
        }
        return _originalArray[index];
    }
    void reverse()
    {
        _tempArray = new T[_size];

        int counter = _size - 1;

        for (int i = 0; i < _size; i++)
        {
            _tempArray[counter] = _originalArray[i];
            counter--;
        }

        delete[] _originalArray;

        _originalArray = _tempArray;
    }
    void clear()
    {
        _size = 0;

        _tempArray = new T[0];

        delete[] _originalArray;

        _originalArray = _tempArray;
    }
    bool deleteItemAt(int index)
    {
        if (index < 0 || index > _size - 1)
        {
            return false;
        }
        _size--;
        _tempArray = new T[_size];

        for (int i = 0; i < index; i++)
        {
            _tempArray[i] = _originalArray[i];
        }

        for (int i = index; i < _size; i++)
        {
            _tempArray[i] = _originalArray[i + 1];
        }

        delete[] _originalArray;

        _originalArray = _tempArray;

        return true;
    }
    void deleteLastItem()
    {
        deleteItemAt(_size - 1);
    }
    void deleteFistItem()
    {
        deleteItemAt(0);
    }
    int find(T value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (_originalArray[i] == value)
            {
                return i;
            }
        }

        return -1;
    }
    bool deleteItemByVal(T value)
    {
        int index = find(value);

        if (index == -1)
        {
            return false;
        }
        else
        {
            deleteItemAt(index);

            return true;
        }
    }
    bool insertAt(int index, T value)
    {
        if (index < 0 || index > _size - 1)
        {
            return false;
        }
        _size++;
        _tempArray = new T[_size];

        for (int i = 0; i < index; i++)
        {
            _tempArray[i] = _originalArray[i];
        }

        _tempArray[index] = value;

        for (int i = index; i < _size - 1; i++)
        {
            _tempArray[i + 1] = _originalArray[i];
        }

        delete[] _originalArray;

        _originalArray = _tempArray;

        return true;
    }
    void insertAtBegining(T value)
    {
        insertAt(0, value);
    }
    bool insertAfter(int index, T value)
    {
        if (index >= _size)
        {
            return insertAt(_size - 1, value);
        }

        return insertAt(index + 1, value);
    }
    void insertBefore(int index, T value)
    {
        if (index < 1)
        {
            return insertAt(0, value);
        }
        insertAt(index - 1, value);
    }
    void insertAtEnd(T value)
    {
        insertAt(_size, value);
    }
};