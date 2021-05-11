#include <cmath>
#include "MinHeap.h"

namespace Graph{
    PRIVATE MinHeap::MinHeap(int _phySize):phySize(_phySize){
        heapData = new item[phySize];
        for(int i=0;i<phySize;i++){
            heapData[i].key=DBL_MAX;
        }
        indexArr = new int[phySize];
        logSize = 0;
        isAllocated = true;
    }

    PUBLIC MinHeap::MinHeap(int _phySize,dist* d) :phySize(_phySize-1){
        heapData = new item[phySize];
        indexArr = new int[phySize+1];
        for(int i=0 ; i < phySize ; i++){
            heapData[i].data = i+1;
            heapData[i].key = d[i+1].weight;
            indexArr[i+1] = i;
        }

        for(int i = phySize/2-1 ; i >= 0 ; i--) //Floyd
            fixHeap(i);

        logSize = phySize;
        isAllocated = true;
    }

    PRIVATE MinHeap::MinHeap(item arr[],int size) { //TODO: Consider removing
        logSize = phySize = size;
        heapData = arr;
        isAllocated = false;

        for(int i = size/2-1 ; i >= 0 ; i--)
            fixHeap(i);
    }

    PRIVATE MinHeap::MinHeap(const MinHeap &toCopy) {
        *this=toCopy;
    }

    PRIVATE MinHeap &MinHeap::operator=(const MinHeap &toCopy) {
        if (this != &toCopy) {
            if(isEmpty()){
                makeEmpty();
            }
            logSize = toCopy.logSize;
            isAllocated = toCopy.isAllocated;
            phySize = toCopy.phySize;
            item* tmp = new item[toCopy.phySize];
            int* tmpIndex = new int[toCopy.phySize];
            for (int i = 0; i < logSize; i++) {
                tmp[i] = toCopy.heapData[i];
                tmpIndex[i] = toCopy.indexArr[i];
            }
            delete indexArr;
            delete heapData;
            heapData = tmp;
            indexArr = tmpIndex;
        }
        return *this;
    }
    PRIVATE MinHeap::~MinHeap(){
        if(isAllocated)
            delete[] heapData;
        delete[] indexArr;
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
        int min=nodeIndex;
        int _left = left(nodeIndex);
        int _right = right(nodeIndex);

        if ((_left < logSize) && (heapData[_left].key < heapData[nodeIndex].key)) {
            min = _left;
        }
        if ((_right < logSize) && (heapData[_right].key < heapData[min].key))
            min = _right;
        //Swap values if necessary and continue fixing the heap towards the leaves:
        if (min != nodeIndex) {
            swap(REF heapData[nodeIndex], REF heapData[min]);
            updateVertexToIndexArr(heapData[nodeIndex].data, nodeIndex);//niv
            updateVertexToIndexArr(heapData[min].data, min);//niv
            fixHeap(min);
        }
    }
    void MinHeap::updateVertexToIndexArr(int vertexToUpdate,int indexInHeapArray) {
        indexArr[vertexToUpdate - 1] = indexInHeapArray;
    }


    PRIVATE void MinHeap::decreaseKey(int vertex, double newKey){
        int index = indexArr[vertex];
        heapData[index].key = newKey;
        while (index != 0 && heapData[parent(index)].key > heapData[index].key)
        {
            swap(heapData[index], heapData[parent(index)]);
            index = parent(index);
        }
    }

    PRIVATE item MinHeap::deleteMin() {
        if(logSize < 1){
            throw invalid_argument("invalid input");
        }else{
            item min = heapData[0];
            logSize--;
            heapData[0] = heapData[logSize];
            indexArr[heapData[logSize].data] = 0;
            fixHeap(0);
            indexArr[min.data] = 0;
            return min;
        }
    }

    PRIVATE void MinHeap::insert(item _item) {
        if(logSize == phySize){
            throw invalid_argument("invalid input");
        }
        int i = logSize;
        indexArr[_item.data] = i;
        logSize++;

        while((i > 0) && (heapData[parent(i)].key > _item.key)){
            heapData[i] = heapData[parent(i)];
            indexArr[heapData[parent(i)].data] = indexArr[heapData[i].data];
            i = parent(i);
        }
        heapData[i] = _item;
        indexArr[_item.data] = i;
    }

    PRIVATE bool MinHeap::isEmpty() const {
        if (logSize == 0)
            return true;
        return false;
    }

    PRIVATE void MinHeap::makeEmpty() {
        logSize=0;
    }

    PRIVATE item MinHeap::min() {
        if (logSize < 1) {
             throw invalid_argument("invalid input");
        } else {
            return heapData[0];
        }
    }

    void MinHeap::swap(item& x, item& y){
        item temp = x;
        x = y;
        y = temp;
    }


    MinHeap* BuildMinHeap(item* arr,int n){
        return new MinHeap(arr,n);
    }
}