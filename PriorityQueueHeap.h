#pragma once
#include <iostream>
#include "MinHeap.h"
#include "Constants.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


namespace Graph{

    class PQHeap{
    private:
        MinHeap heap;
    public:
        ///Constructors:
        //turns arr of frequencies and data into a priority queue.
        PQHeap(item* arr, int n): heap(arr,n){}
        //Creates a priority queue from a given dist array
        PQHeap(int _phySize,dist* d): heap(_phySize,d){}
        //Copy ctor
        PQHeap(const PQHeap& toCopy) : heap(toCopy.heap){}
        //Creates an empty priority queue.
        PQHeap(int queueSize) : heap(queueSize) {}
        ///Class methods:
        //return and delete min value in the priority queue
        item deleteMin(){ return heap.deleteMin(); }
        //check if empty
        bool isEmpty() const { return heap.isEmpty(); }
        //Decrease the key value of the item in the given place, and fix the heap afterward
        void DecreaseKey(int place, double newKey){ heap.decreaseKey(place,newKey); }
    };
}