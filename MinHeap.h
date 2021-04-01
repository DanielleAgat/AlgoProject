//Student Name: Danielle Agat Levi
//Student ID: 313357329
//Student Name: Aviv Nevelev
//Student ID: 206026429
#pragma once

namespace Graph{
    class MinHeap{
    private:
        int heapData;
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

    public:
        ///Constructors & Destructors:
        //Allocate memory for the heap and make the heap empty.
        MinHeap(int _phySize);
        //copy ctor
        MinHeap(const MinHeap& toCopy);
        //turns arr of frequencies and chars into min heap.
        MinHeap(int arr[],int size);
        //destructor
        ~MinHeap();

        ///Methods:
        //return min without delete.
        int min();
        // reset logSize
        void makeEmpty();
        //check if empty
        bool isEmpty() const;
        // return and delete min
        int deleteMin();
        // insert HoffmanTree to heap
        void insert(int item);

        ///Overriding operators:
        MinHeap& operator=(const MinHeap& toCopy);
    };
    //swap 2 integers
    void swap(int& x, int& y);
}