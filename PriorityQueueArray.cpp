#include "PriorityQueueArray.h"
#include <cassert>

namespace Graph{
    PUBLIC PQArr::PQArr(int _phySize) :phySize(_phySize){
        arr = new item[phySize];
        indexArr = new int[phySize+1];
        logSize = 0;
        isAllocated = true;
        minIndex = -1;
    }

    PUBLIC PQArr::PQArr(int _phySize,dist* d) :phySize(_phySize){
        arr = new item[phySize];
        indexArr = new int[phySize + 1];
        for(int i=0 ; i < phySize ; i++){
            arr[i].data = i+1;
            arr[i].key = d[i+1].weight;
            indexArr[i + 1] = i;
        }
        logSize = phySize;
        isAllocated = true;
        min = arr[0];
        minIndex = indexArr[min.data];
        calcMin();
    }


    PUBLIC PQArr::PQArr(item* _arr, int _size){
        logSize = phySize = _size;
        arr = _arr;
        indexArr = new int[phySize + 1];
        for (int i = 0; i < phySize; i++)
             indexArr[i + 1] = i;
        isAllocated = false;
        calcMin();
    }

    PUBLIC PQArr::PQArr(const PQArr &toCopy) {
        *this = toCopy;
    }

    PUBLIC PQArr::~PQArr(){
        if(isAllocated)
            delete[] arr;
        delete[] indexArr;
    }

    PUBLIC item PQArr::getMin() { return min; }

    PRIVATE void PQArr::calcMin() {
        for(int i=1; i < logSize ; i++){
            if(min.key > arr[i].key){
                min = arr[i];
                minIndex = i;
            }
        }
    }

    PUBLIC void PQArr::insert(item _item){
        if(logSize == phySize){
            throw invalid_argument("invalid input");
        }
        arr[_item.data] = _item;
        indexArr[_item.data] = _item.data;
        if(arr[_item.data].key < min.key){
            min = arr[_item.data];
            minIndex = _item.data;
        }
    }

    PUBLIC item PQArr::deleteMin() {
        item _min = min;
        for(int i = minIndex; i < logSize; i++){
            arr[i] = arr[i+1];
        }
        for (int i = minIndex; i < phySize; i++) {
            if(indexArr[i+1]==1||indexArr[i+1]==0){
                indexArr[i+1]=0;
            }
            else {
                indexArr[i + 1] -= 1;
            }
        }

        logSize--;
        min = arr[0];
        minIndex = indexArr[min.data];
        calcMin();
        return _min;

//        if(logSize < 1){
//            throw invalid_argument("invalid input");
//        }else{
//            item min = heapData[0];
//            logSize--;
//            heapData[0] = heapData[logSize];
//            indexArr[heapData[logSize].data] = 0;
//            fixHeap(0);
//            indexArr[min.data] = 0;
//            return min;

    }

    PUBLIC bool PQArr::isEmpty() const{
        return logSize <=1 ; //the 0 index is dummy
    }

    PUBLIC void PQArr::DecreaseKey(int place, double newKey){
         int index = indexArr[place];
        arr[index].key = newKey;
        if(newKey < min.key){
            min = arr[index];
            minIndex = index;
        }
    }

    void Build(PQArr& obj,item* arr, int size){
        obj = PQArr(arr,size);
    }


}