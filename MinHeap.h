//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once
#include <iostream>
#include "Constants.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace Graph{

    class MinHeap {
        friend class PQHeap;
        friend MinHeap* BuildMinHeap(item* arr,int n);
    private:
        item* heapData;
        int phySize;
        int logSize;
        int* indexArr;
        bool isAllocated; // 'true' if heap allocated memory ; 'false' otherwise.

        ///Constructors & Destructors:
        //Allocate memory for the heap and make the heap empty.
        MinHeap(int _phySize);
        //Creates a min heap from a given dist array
        MinHeap(int _phySize,dist* d);
        //copy ctor
        MinHeap(const MinHeap& toCopy);
        //turns arr of frequencies and chars into min heap.
        MinHeap(item arr[],int size);
        //destructor
        ~MinHeap();

        ///Methods:
        // calc leftChild index
        static int left(int nodeIndex);
        // calc rightChild index
        static int right(int nodeIndex);
        // calc parent index
        static int parent(int nodeIndex);
        //fixHeap based on algorithm learned in class.
        void fixHeap(int nodeIndex);
        //Decreases value of key at a given index to newKey.
        void decreaseKey(int place, double newKey);
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
        //swap 2 integers
        void swap(item& x, item& y);
        void updateVertexToIndexArr(int vertexToUpdate,int indexInHeapArray);
        ///Overriding operators:
        MinHeap& operator=(const MinHeap& toCopy);

    };



    //Return MinHeap
    MinHeap* BuildMinHeap(item* arr,int n);
}