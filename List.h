//
// Created by Aviv Nevelev on 01/04/2021.
//

#ifndef ALGOPROJECT_LIST_H
#define ALGOPROJECT_LIST_H
#include "ostream"
#include "Constants.h"
using namespace std;
namespace Graph {
    class ListNode {
        friend class List;
    private:
        arc data;
        ListNode *next;
        ListNode *prev;
    public:
        ///Constructors:
        ListNode();
        explicit ListNode(arc &_data);

        ///Getters & setters:
        arc getData() const { return data; }
        ListNode *getNext() const { return next; };
    };

    class List {
        friend ostream& operator<<(ostream& os, const List& lst);
    private:
        ListNode *head;
        ListNode *tail;
        int listSize;

        //This method returns osStream object of the first X citizens in the list, while X is given by the user
        //ostream &getTheFirstDataByNum(ostream &os, int num) const;

    public:
        ///Constructors & destructors:
        List();
        List(List &list);
        ~List();

        //explicit List(istream &in);

        ///Getters & Setters:
        int getNumOfArcsInLst() const { return listSize; };
        ListNode* getHead(){return head;}
        bool setI(int i){getHead()->data.i_start=i;return true;}
        bool setJ(int j){getHead()->data.j_end=j;return true;}
        bool setWeight(int w){getHead()->data.weight=w;return true;}
        ///General methods:
        //This method clears the list and frees memory if needed
        void makeEmpty();

        //This method adds a given citizen to the list's tail
        void AddToLst(arc &newData);
        //This method returns true if the list is empty ; false otherwise
        bool isLstEmpty() const;
        void removeFromList(arc& dataToRemove);
        ListNode* findDataInList(arc& dataToFind);

        ///Overloading operators:
        const List &operator=(const List &Lst);
    };

}


#endif //ALGOPROJECT_LIST_H
