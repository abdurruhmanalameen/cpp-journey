#pragma once
#include <iostream>
#include "clsMyDynamicArray.h"

using namespace std;
template <class T>

class clsMyQueueArr
{
protected:
    clsMyDynamicArray<T> _myList;

public:
    bool isEmpty()
    {
        _myList.isEmpty();
    }
    void push(T value)
    {
        _myList.insertAtEnd(value);
    }
    void pop()
    {
        _myList.deleteFistItem();
    }
    T front()
    {
        return _myList.getItem(0);
    }
    T back()
    {
        return _myList.getItem(size() - 1);
    }
    int size()
    {
        return _myList.size();
    }
    void print()
    {
        _myList.print();
    }
    T getItem(int index)
    {
        return _myList.getItem(index);
    }
    void reverse()
    {
        _myList.reverse();
    }
    void updateItem(int index, T update)
    {
        _myList.setItem(index, update);
    }
    void insertAfter(int index, T value)
    {
        _myList.insertAfter(index, value);
    }
    void insertAtFront(T value)
    {
        _myList.insertAtBeginning(value);
    }
    void insertAtBack(T value)
    {
        _myList.insertAtEnd(value);
    }
    void clear()
    {
        _myList.clear();
    }
};