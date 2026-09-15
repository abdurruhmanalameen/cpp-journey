#include <iostream>
#include "clsMyQueueLine.h"
using namespace std;

int main()
{

    clsMyQueueLine myQueue("A0", 10);
    myQueue.issueTicket();
    myQueue.issueTicket();
    myQueue.issueTicket();
    // myQueue.printInfo();

    // // myQueue.printInfo();

    // myQueue.printTicketsLineRtL();
    // myQueue.printTicketsLineLtR();

    myQueue.serveNextClient();

    myQueue.printAllTickets();
    myQueue.printInfo();

    return 0;
}