#pragma once
#include "Node.h"

class List
{
private:
    Node* pHead;
    Node* pTail;
    Node* createNode(Data* data);
public:
    List();
    ~List();
    Node* getpHead();
    Node* getpTail();
    Node* previousNode(Node* pNode);
    Node* nextNode(Node* pNode);
    void appendNode(Data* value);
    void insertNode(Data* value, Node* pAfter);
    void removeNode(Node* pNode);
    bool isEmpty();
    void printList();
};
