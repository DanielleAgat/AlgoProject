//
// Created by Aviv Nevelev on 01/04/2021.
//

#include "List.h"
namespace Graph {
///Constructors & destructors - ListNode class:
    PUBLIC ListNode::ListNode() : next(nullptr), prev(nullptr) {
        data.weight=NO_ARC;
        data.i_start=-1;
        data.j_end=-1;
    }

    PUBLIC ListNode::ListNode(arc &_data) : next(nullptr), prev(nullptr),data(_data) {
    }

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
    PUBLIC void List::makeEmpty() {
        ListNode *tmp;
        while (head->next != nullptr) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        listSize = 0;
    }

    PUBLIC void List::AddToLst(arc &newData) {
        ListNode *toAdd = new ListNode(REF newData);
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


    PUBLIC const List &List::operator=(const List &lst) {
        if (this != &lst) {
            head = lst.head;
            tail = lst.tail;
            listSize = lst.listSize;
        }
        return *this;
    }

    PUBLIC void List::removeFromList(arc& dataToRemove) {
        ListNode* toRemove=findDataInList(REF dataToRemove);
        toRemove->prev=toRemove->next;
    }

    PUBLIC ListNode *List::findDataInList(arc &dataToFind) {
        ListNode* temp = head;
        while(temp != nullptr){
            if(temp->data.i_start==dataToFind.i_start && temp->data.j_end==dataToFind.j_end ) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

}