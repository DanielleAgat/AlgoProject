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
            int data;
            int weight;
            ListNode *next;
            ListNode *prev;
        public:
            ///Constructors:
            ListNode();
            ListNode(int &_data);
            ListNode(int &_data,int &weight);

            ///Getters & setters:
            int getData() const { return data; }
            ListNode *getNext() const { return next; };
        };

        class List {
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
            int getNumOfCtzInLst() const { return listSize; };

            ///General methods:
            //This method clears the list and frees memory if needed
            void makeEmpty();

            //This method adds a given citizen to the list's tail
            void AddToLst(int &newData);
            void AddToLst(int &newData,int&weight);
            //This method returns true if the list is empty ; false otherwise
            bool isLstEmpty() const;

            void removeFromList(int& dataToRemove);
            ListNode* findDataInList(int& dataToFind);

            ///Overloading operators:
            const List &operator=(const List &Lst);
        };

}


#endif //ALGOPROJECT_LIST_H
