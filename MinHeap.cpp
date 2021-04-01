#include "MinHeap.h"

namespace Graph{
    MinHeap::MinHeap(int _phySize):phySize(_phySize){
        heapData = new HoffmanTree[phySize];
        logSize = 0;
        isAllocated = true;
    }

    MinHeap::MinHeap(int arr[],int size) {
        logSize = phySize = size;
        heapData = arr;
        isAllocated = false;

        for(int i = size/2-1 ; i >= 0 ; i--)
            fixHeap(i);
    }

    MinHeap::MinHeap(const MinHeap &toCopy) {
        *this=toCopy;
    }

    MinHeap &MinHeap::operator=(const MinHeap &toCopy) {
        if (this != &toCopy) {
            if(isEmpty()){
                makeEmpty();
            }
            logSize = toCopy.logSize;
            isAllocated = toCopy.isAllocated;
            phySize = toCopy.phySize;
            HoffmanTree *tmp = new HoffmanTree[toCopy.phySize];
            for (int i = 0; i < logSize; i++) {
                tmp[i] = toCopy.heapData[i];
            }
            heapData = tmp;
        }
        return *this;
    }
    MinHeap::~MinHeap(){
        if(isAllocated)
            delete[] heapData;
        heapData = nullptr;
    }

    int MinHeap::left(int nodeIndex){
        return (2*nodeIndex + 1);
    }
    int MinHeap::right(int nodeIndex){
        return (2*nodeIndex + 2);
    }
    int MinHeap::parent(int nodeIndex){
        return (nodeIndex-1)/2;
    }

    void MinHeap::fixHeap(int nodeIndex) {
        int min;
        int _left = left(nodeIndex);
        int _right = right(nodeIndex);

        if ((_left < logSize) && (heapData[_left].getRootKey() < heapData[nodeIndex].getRootKey())) {
            min = _left;
        } else {
            min = nodeIndex;
        }
        if ((_right < logSize) && (heapData[_right].getRootKey() < heapData[min].getRootKey()))
            min = _right;
        //Swap values if necessary and continue fixing the heap towards the leaves:
        if (min != nodeIndex) {
            swap(heapData[nodeIndex], heapData[min]);
            fixHeap(min);
        }
    }

    HoffmanTree* MinHeap::deleteMin() {
        if(logSize < 1){
            cout << "invalid input" << endl;
            exit(1);
        }else{
            HoffmanTree* min = new HoffmanTree();
            *min = *heapData;
            logSize--;
            heapData[0] = heapData[logSize];
            fixHeap(0);
            return min;
        }
    }

    void MinHeap::insert(HoffmanTree item) {
        if(logSize == phySize){
            cout << "invalid input" << endl;
            exit(1);
        }
        int i = logSize;
        logSize++;

        while((i > 0) && (heapData[parent(i)].getRootKey() > item.getRootKey())){
            heapData[i] = heapData[parent(i)];
            i = parent(i);
        }
        heapData[i] = item;
    }

    void MinHeap::makeHeap(BinSearchNode* node){
        Pair* heapArr=node->makeDataArr(phySize,logSize);
        for(int i=0;i<logSize;i++){
            HoffmanTree HoffmanTree;
            HoffmanTree.insert(heapArr[i].frequency, heapArr[i].key);
            heapData[i]=HoffmanTree;
        }
        for(int i=logSize/2-1;i>=0;i--){ // floyd.
            fixHeap(i);
        }
    }


    bool MinHeap::isEmpty() const {
        if (logSize == 0)
            return true;
        return false;
    }

    void MinHeap::makeEmpty() {
        logSize=0;
    }

    HoffmanTree* MinHeap::min() {
        if (logSize < 1) {
            cout << "invalid input" << endl;
            exit(1);
        } else {
            HoffmanTree *min = new HoffmanTree();
            *min = *heapData;
            return min;
        }
    }



    void swap(HoffmanTree& x, HoffmanTree& y){
        HoffmanTree temp = x;
        x = y;
        y = temp;
    }

}