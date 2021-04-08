#pragma once
#include <iostream>
#include "MinHeap.h"

using namespace std;


namespace Graph{

    class PQHeap{
    private:
        MinHeap heap;
    public:
        ///Constructors:
        //turns arr of frequencies and data into a priority queue.
        PQHeap(item* arr, int n): heap(arr,n){}
        //Copy ctor
        PQHeap(const PQHeap& toCopy) : heap(toCopy.heap){}
        //Creates an empty priority queue.
        PQHeap(int queueSize) : heap(queueSize) {}

        ///Class methods:
        //return and delete min value in the priority queue
        item deleteMin(){ heap.deleteMin(); }
        //check if empty
        bool isEmpty() const { return heap.isEmpty(); }
        //Decrease the key value of the item in the given place, and fix the heap afterward
        void DecreaseKey(int place, int newKey){ heap.decreaseKey(place,newKey); }
    };

    PQHeap* Build(item* arr,int n){
        return new PQHeap(arr,n);
    }
}