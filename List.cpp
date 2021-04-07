//
// Created by Aviv Nevelev on 01/04/2021.
//

#include "List.h"
namespace Graph {
///Constructors & destructors - ListNode class:
    PUBLIC ListNode::ListNode() : next(nullptr), prev(nullptr) {
        weight=0;
        data=-1;
    }

    PUBLIC ListNode::ListNode(int &_data) : next(nullptr), prev(nullptr) {
        data = _data;
    }
    PUBLIC ListNode::ListNode(int &_data,int&_weight) : next(nullptr), prev(nullptr) {
        data = _data;
        weight=_weight;
    }

///Constructors & destructors - CitizenList class:
    PUBLIC List::List() : listSize(0) {
        head = new ListNode;
        tail = head;
    }

    PUBLIC List::List(List &lst) {
        head = lst.head;
        tail = lst.tail;
        listSize = lst.listSize;
    }

    PUBLIC List::~List() {
        makeEmpty();
    }


///General methods - CitizenList class:
    PUBLIC void List::makeEmpty() {
        ListNode *tmp;
        while (head->next != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        listSize = 0;
    }

    PUBLIC void List::AddToLst(int &newData) {
        ListNode *toAdd = new ListNode(REF newData);
        tail->next = toAdd;
        toAdd->prev = tail;
        tail = toAdd;
        listSize++;
    }
    PUBLIC void List::AddToLst(int &newData,int&weight) {
        ListNode *toAdd = new ListNode(REF newData,REF weight);
        tail->next = toAdd;
        toAdd->prev = tail;
        tail = toAdd;
        listSize++;
    }

    PUBLIC bool List::isLstEmpty() const {
        if (head == tail)
            return true;
        return false;
    }

///Overloading operators - CitizenList class:

    PUBLIC const List &List::operator=(const List &lst) {
        if (this != &lst) {
            head = lst.head;
            tail = lst.tail;
            listSize = lst.listSize;
        }
        return *this;
    }

    PUBLIC void List::removeFromList(int& dataToRemove) {
        ListNode* toRemove=findDataInList(REF dataToRemove);
        toRemove->prev=toRemove->next;
    }

    PUBLIC ListNode *List::findDataInList(int &dataToFind) {
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->data==dataToFind) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

}