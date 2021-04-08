#pragma once
#include <iostream>
#include "Constants.h"

using namespace std;

namespace Graph{

    class PQArr{
    private:
        item* arr;
        int phySize;
        int logSize;
        int isAllocated;
        item min;
        int minIndex;

        //Calculate and return min without delete.
        void calcMin();

    public:
        ///Constructors & Destructors
        //Creates an empty priority queue of a given size
        PQArr(int _phySize);
        //Creates a priority queue from a given array
        PQArr(item* arr,int _size);
        //Copy ctor
        PQArr(const PQArr& toCopy);
        //Dtor
        ~PQArr();

        ///Methods:
        //returns the min value
        item getMin();
        //return and delete min value in the priority queue
        item deleteMin();
        //check if empty
        bool isEmpty() const;
        //Decrease the key value of the item in the given place, and fix the heap afterward
        void DecreaseKey(int place, int newKey);
        // insert item to arr
        void insert(item _item);

    };
    //Creates and returns a priority queue from a given array.
    void Build(PQArr& obj,item* arr, int size);

}