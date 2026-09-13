#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{

    clsDblLinkedLlist<int> myDblLinkedList;

    myDblLinkedList.insertAtBeginning(5);
    myDblLinkedList.insertAtBeginning(4);
    myDblLinkedList.insertAtBeginning(3);
    myDblLinkedList.insertAtBeginning(2);
    myDblLinkedList.insertAtBeginning(1);

    cout << "\nLinked List Content:\n";
    myDblLinkedList.printListDetails();

    // myDblLinkedList.reverse();
    // myDblLinkedList.printListDetails();

    // clsDblLinkedLlist<int>::node *node1 = myDblLinkedList.getNode(2);

    // cout << "node1 value is: " << node1->value << endl;

    // cout << "Item of node1 is: " << myDblLinkedList.getItem(2) << endl;

    // myDblLinkedList.updateItem(2, 500);

    myDblLinkedList.insertAfter(2, 600);
    myDblLinkedList.printListDetails();
}