#include "List.h"

List::List() {
    pHead = NULL;
    pTail = NULL;
}

List ::~List() {
    while (!isEmpty())   //keep on removing until the
        //head points to NULL
        removeNode(pHead);
    cout << "List deleted\n";
}

Node* List::getpHead() { return pHead; }
Node* List::getpTail() { return pTail; }
Node* List::previousNode(Node* pNode) { return pNode->pPrev; }
Node* List::nextNode(Node* pNode) { return pNode->pNext; }

Node* List::createNode(Data* data) {
    Node* pNode = new Node(data); //allocate memory for new node and
    //intialize value to data
    return pNode;
}

bool List::isEmpty() {
    return pHead == NULL;
}

void List::appendNode(Data* value)
{
    Node* pNode = createNode(value);

    if (isEmpty()) {     //if list is empty
        pHead = pNode;        //make head point to pNode
        pNode->pPrev = NULL;
    }
    else {                    //otherwise
        pTail->pNext = pNode;  //make tail point to pNode
        pNode->pPrev = pTail;
    }
    pTail = pNode;        //tail is now pNode
    pNode->pNext = NULL;  //pNode next now points to NULL
}


void List::insertNode(Data* value, Node* pAfter)
{
    Node* pNode = createNode(value);
    pNode->pNext = pAfter->pNext;
    pNode->pPrev = pAfter;

    if (pAfter->pNext != NULL)
        pAfter->pNext->pPrev = pNode;
    else
        pTail = pNode;
    pAfter->pNext = pNode;
}

void List::removeNode(Node* pNode)
{
    if (pNode->pPrev == NULL)  //if removing the head
        pHead = pNode->pNext;
    else
        pNode->pPrev->pNext = pNode->pNext;  //if removing a middle node

    if (pNode->pNext == NULL)  //if removing the tail
        pTail = pNode->pPrev;
    else
        pNode->pNext->pPrev = pNode->pPrev;

    delete pNode; //*free the memory
}

void List::printList()
{
    Node* pNode = pHead;
    if (isEmpty())
        cout << "The list is empty\n";
    else
        for (pNode = pHead; pNode != NULL; pNode = pNode->pNext)
            pNode->nData->print();
}