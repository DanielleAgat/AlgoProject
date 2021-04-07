//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#include <iostream>
#include "Constants.h"
#pragma once

using namespace std;

namespace Graph{
    typedef struct ITEM{
        int data;
        int key;
    }item;


    class MinHeap {
        friend class PQHeap;
        friend MinHeap* BuildMinHeap(item* arr,int n);
    private:
        item* heapData;
        int phySize;
        int logSize;
        bool isAllocated; // 'true' if heap allocated memory ; 'false' otherwise.

        ///Inner Methods:
        // calc leftChild index
        static int left(int nodeIndex);
        // calc rightChild index
        static int right(int nodeIndex);
        // calc parent index
        static int parent(int nodeIndex);
        //fixHeap based on algorithm learned in class.
        void fixHeap(int nodeIndex);

        ///Constructors & Destructors:
        //Allocate memory for the heap and make the heap empty.
        MinHeap(int _phySize);
        //copy ctor
        MinHeap(const MinHeap& toCopy);
        //turns arr of frequencies and chars into min heap.
        MinHeap(item arr[],int size);
        //destructor
        ~MinHeap();

        ///Methods:
        //return min without delete.
        item min();
        // reset logSize
        void makeEmpty();
        //check if empty
        bool isEmpty() const;
        // return and delete min
        item deleteMin();
        // insert item to heap
        void insert(item _item);

        ///Overriding operators:
        MinHeap& operator=(const MinHeap& toCopy);
    };

    //swap 2 integers
    void swap(item& x, item& y);

    //Return MinHeap
    MinHeap* BuildMinHeap(item* arr,int n);
}