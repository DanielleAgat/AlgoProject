//
// Created by Aviv Nevelev on 01/04/2021.
//

#include "List.h"
namespace Graph {
///Constructors & destructors - ListNode class:
    ListNode::ListNode() : next(nullptr), prev(nullptr) {
    }

    ListNode::ListNode(int &_data) : next(nullptr), prev(nullptr) {
        data = _data;
    }

///Constructors & destructors - CitizenList class:
    List::List() : listSize(0) {
        head = new ListNode;
        tail = head;
    }

    List::List(List &lst) {
        head = lst.head;
        tail = lst.tail;
        listSize = lst.listSize;
    }

    List::~List() {
        makeEmpty();
    }


///General methods - CitizenList class:
    void List::makeEmpty() {
        ListNode *tmp;
        while (head->next != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        listSize = 0;
    }

    void List::AddToLst(int &newData) {
        ListNode *toAdd = new ListNode(newData);
        tail->next = toAdd;
        toAdd->prev = tail;
        tail = toAdd;
        listSize++;
    }

    bool List::isLstEmpty() const {
        if (head == tail)
            return true;
        return false;
    }

///Overloading operators - CitizenList class:

    const List &List::operator=(const List &lst) {
        if (this != &lst) {
            head = lst.head;
            tail = lst.tail;
            listSize = lst.listSize;
        }
        return *this;
    }

}
