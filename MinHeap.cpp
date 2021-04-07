#include "MinHeap.h"

namespace Graph{
    PUBLIC MinHeap::MinHeap(int _phySize):phySize(_phySize){
        heapData = new item[phySize];
        logSize = 0;
        isAllocated = true;
    }

    PUBLIC MinHeap::MinHeap(item arr[],int size) {
        logSize = phySize = size;
        heapData = arr;
        isAllocated = false;

        for(int i = size/2-1 ; i >= 0 ; i--)
            fixHeap(i);
    }

    PUBLIC MinHeap::MinHeap(const MinHeap &toCopy) {
        *this=toCopy;
    }

    PUBLIC MinHeap &MinHeap::operator=(const MinHeap &toCopy) {
        if (this != &toCopy) {
            if(isEmpty()){
                makeEmpty();
            }
            logSize = toCopy.logSize;
            isAllocated = toCopy.isAllocated;
            phySize = toCopy.phySize;
            item* tmp = new item[toCopy.phySize];
            for (int i = 0; i < logSize; i++) {
                tmp[i] = toCopy.heapData[i];
            }
            delete heapData;
            heapData = tmp;
        }
        return *this;
    }
    PUBLIC MinHeap::~MinHeap(){
        if(isAllocated)
            delete[] heapData;
        heapData = nullptr;
    }

    PRIVATE STATIC int MinHeap::left(int nodeIndex){
        return (2*nodeIndex + 1);
    }
    PRIVATE STATIC int MinHeap::right(int nodeIndex){
        return (2*nodeIndex + 2);
    }
    PRIVATE STATIC int MinHeap::parent(int nodeIndex){
        return (nodeIndex-1)/2;
    }

    PRIVATE void MinHeap::fixHeap(int nodeIndex) {
        int min;
        int _left = left(nodeIndex);
        int _right = right(nodeIndex);

        if ((_left < logSize) && (heapData[_left].key < heapData[nodeIndex].key)) {
            min = _left;
        } else {
            min = nodeIndex;
        }
        if ((_right < logSize) && (heapData[_right].key < heapData[min].key))
            min = _right;
        //Swap values if necessary and continue fixing the heap towards the leaves:
        if (min != nodeIndex) {
            swap(REF heapData[nodeIndex], REF heapData[min]);
            fixHeap(min);
        }
    }

    PUBLIC item MinHeap::deleteMin() {
        if(logSize < 1){
            throw invalid_argument("invalid input");
        }else{
            item min = heapData[0];
            logSize--;
            heapData[0] = heapData[logSize];
            fixHeap(0);
            return min;
        }
    }

    PUBLIC void MinHeap::insert(item _item) {
        if(logSize == phySize){
            throw invalid_argument("invalid input");
        }
        int i = logSize;
        logSize++;

        while((i > 0) && (heapData[parent(i)].key > _item.key)){
            heapData[i] = heapData[parent(i)];
            i = parent(i);
        }
        heapData[i] = _item;
    }

    PUBLIC bool MinHeap::isEmpty() const {
        if (logSize == 0)
            return true;
        return false;
    }

    PUBLIC void MinHeap::makeEmpty() {
        logSize=0;
    }

    PUBLIC item MinHeap::min() {
        if (logSize < 1) {
             throw invalid_argument("invalid input");
        } else {
            return heapData[0];
        }
    }

    PUBLIC void swap(item& x, item& y){
        item temp = x;
        x = y;
        y = temp;
    }

    PUBLIC MinHeap* Build(item* arr,int n){
        return new MinHeap(arr,n);
    }
}