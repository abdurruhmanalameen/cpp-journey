#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedLlist
{
protected:
    int _size = 0;

public:
    class node
    {
    public:
        T value;
        node *next;
        node *prev;
    };

    node *head = NULL;

    void printListDetails()
    {
        node *current = head;

        cout << "\n";
        while (current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << "\n";
    }
    void insertAtBeginning(T value)
    {
        node *newNode = new node();

        newNode->value = value;

        newNode->next = head;

        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
        _size++;
    }
    node *find(T value)
    {
        node *current = head;
        while (current != NULL)
        {
            if (current->value == value)
            {
                return current;
            }

            current = current->next;
        }

        return NULL;
    }
    void insertAfter(node *prevNode, T value)
    {
        node *newNode = new node();
        newNode->value = value;

        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;

        if (prevNode->next != NULL)
        {
            prevNode->next->prev = newNode;
        }

        _size++;
    }
    void insertAtEnd(T value)
    {
        node *newNode = new node();
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;

            head = newNode;
        }
        else
        {
            node *currentNode = head;

            while (currentNode->next != NULL)
            {
                currentNode = currentNode->next;
            }

            newNode->prev = currentNode;

            currentNode->next = newNode;
        }

        _size++;
    }
    void deleteNode(node *toDelete)
    {
        if (head == NULL || toDelete == NULL)
        {
            return;
        }
        if (head == toDelete)
        {
            head = toDelete->next;
        }
        if (toDelete->next != NULL)
        {
            toDelete->next->prev = toDelete->prev;
        }
        if (toDelete->prev != NULL)
        {
            toDelete->prev->next = toDelete->next;
        }

        _size--;

        delete toDelete;
    }
    void deleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }

        node *temp = head;

        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
        _size--;
    }
    void deleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        node *currentNode = head;

        while (currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }

        node *temp = currentNode->next;
        currentNode->next = NULL;

        delete temp;
        _size--;
    }
    int size()
    {
        return _size;
    }
    bool isEmpty()
    {
        return _size == 0 ? true : false;
    }
    void clear()
    {
        while (_size > 0)
        {
            deleteFirstNode();
        }
    }
    void reverse()
    {
        node *current = head;
        node *temp = nullptr;

        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }
    node *getNode(int index)
    {
        if (index > _size - 1 || index < 0)
        {
            return NULL;
        }

        node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
    }

    T getItem(int index)
    {
        node *node1 = getNode(index);

        if (node1 == NULL)
        {
            return NULL;
        }
        else
        {
            return node1->value;
        }
    }
    bool updateItem(int index, T update)
    {
        node *node1 = getNode(index);

        if (node1 != NULL)
        {
            node1->value = update;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool insertAfter(int index, T value)
    {
        node *node1 = getNode(index);

        if (node1 != NULL)
        {
            insertAfter(node1, value);
            return true;
        }
        else
        {
            return false;
        }
    }
};