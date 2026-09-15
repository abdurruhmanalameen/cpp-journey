#pragma once

#include <iostream>
#include "clsMyQueue.h"
using namespace std;
template <class T>

class clsMyStack : public clsMyQueue<T>
{

public:
    void push(T item)
    {
        clsMyQueue<T>::_myList.insertAtBeginning(item);
    }

    T top()
    {
        return clsMyQueue<T>::front();
    }

    T bottom()
    {
        return clsMyQueue<T>::back();
    }
};
