#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include "clsDate.h"

using namespace std;

class clsMyQueueLine
{
public:
    class clsTicket;

private:
    string _prefix;
    int _averageTime;
    int _totalTickets = 0;
    queue<clsTicket> myQueue;

public:
    clsMyQueueLine(string prefix, int averageTime)
    {
        _prefix = prefix;
        _averageTime = averageTime;
    }
    class clsTicket
    {
    private:
        int _number = 0;
        string _prefix;
        string _printTime;
        int _waitingClinets = 0;
        int _averageServeTime = 0;
        int _ExpectedServeTime = 0;

    public:
        clsTicket(int number, string prefix, int waitingClinets, int averageServeTime)
        {
            _number = number;
            _prefix = prefix;
            _waitingClinets = waitingClinets;
            _averageServeTime = averageServeTime;
            _printTime = clsDate::printCurrentTime();
        }
        string perfix()
        {
            return _prefix;
        }

        int number()
        {
            return _number;
        }

        string fullNumber()
        {
            return _prefix + to_string(_number);
        }

        string ticketTime()
        {
            return _printTime;
        }

        int waitingClients()
        {
            return _waitingClinets;
        }

        int ExpectedServeTime()
        {
            return _averageServeTime * _waitingClinets;
        }

        void print()
        {
            cout << setw(37) << left << "" << "_______________________\n";
            cout << setw(37) << left << "" << "\t" << fullNumber() << endl;
            cout << setw(37) << left << "" << _printTime << endl;
            cout << setw(37) << left << "" << "Waiting Clients = " << _waitingClinets << endl;
            cout << setw(37) << left << "" << "Serve Time In\n";
            cout << setw(37) << left << "" << ExpectedServeTime() << " Minutes.\n";
            cout << setw(37) << left << "" << "_______________________\n";
        }
    };

    int servedClinets()
    {
        return _totalTickets - myQueue.size();
    }
    int waitingClients()
    {
        return myQueue.size();
    }
    void printInfo()
    {
        cout << setw(37) << left << "" << "=========================\n"
             << setw(37) << left << "" << "\tQueue Data\n"
             << setw(37) << left << "" << "=========================\n"
             << setw(37) << left << "" << "Prefix         : " << _prefix << endl
             << setw(37) << left << "" << "Total Tickets  : " << _totalTickets << endl
             << setw(37) << left << "" << "Served Clients : " << servedClinets() << endl
             << setw(37) << left << "" << "Waiting Clinets: " << waitingClients() << endl
             << setw(37) << left << "" << "=========================\n";
    }
    void printTicketsLineRtL()
    {
        if (myQueue.empty())
        {
            cout << "\n\tTickets: No Tickets!\n";
        }
        else
        {
            queue<clsTicket> myTempQueue = myQueue;

            cout << "\n\t\tTickets: ";
            while (!myTempQueue.empty())
            {
                clsTicket tempTicket = myTempQueue.front();

                cout << " " << tempTicket.fullNumber() << " <-- ";

                myTempQueue.pop();
            }

            cout << endl;
        }
    }
    void printTicketsLineLtR()
    {
        if (myQueue.empty())
        {
            cout << "\n\tTickets: No Tickets!\n";
        }
        else
        {
            queue<clsTicket> myTempQueue = myQueue;
            stack<clsTicket> myStack;

            while (!myTempQueue.empty())
            {
                myStack.push(myTempQueue.front());
                myTempQueue.pop();
            }

            cout << "\n\t\tTickets: ";
            while (!myStack.empty())
            {
                clsTicket tempTicket = myStack.top();

                cout << " " << tempTicket.fullNumber() << " <-- ";

                myStack.pop();
            }

            cout << "\n";
        }
    }
    void printAllTickets()
    {
        if (myQueue.empty())
        {
            cout << "\n\tNo Tickets!\n";
        }
        else
        {
            cout << setw(32) << left << "" << "=========================\n"
                 << setw(32) << left << "" << "\tTickets\n"
                 << setw(32) << left << "" << "=========================\n";
            queue<clsTicket> myTempQueue = myQueue;
            while (!myTempQueue.empty())
            {
                myTempQueue.front().print();

                myTempQueue.pop();
            }
        }
    }
    void issueTicket()
    {
        _totalTickets++;
        clsTicket ticket(_totalTickets, _prefix, waitingClients(), _averageTime);
        myQueue.push(ticket);
    }
    bool serveNextClient()
    {
        if (myQueue.empty())
        {
            return false;
        }

        myQueue.pop();
        return true;
    }
};