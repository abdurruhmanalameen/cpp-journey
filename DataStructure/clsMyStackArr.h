#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;
template <class T>

class clsMyStackArr : public clsMyQueueArr<T>
{

public:
    void push(T item)
    {
        clsMyQueueArr<T>::_myList.insertAtBeginning(item);
    }

    T top()
    {
        return clsMyQueueArr<T>::front();
    }

    T bottom()
    {
        return clsMyQueueArr<T>::back();
    }
};
