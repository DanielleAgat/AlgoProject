#include "PriorityQueueArray.h"

namespace Graph{
    PUBLIC PQArr::PQArr(int _phySize) :phySize(_phySize),offset(0){
        arr = new item[phySize];
        logSize = 0;
        isAllocated = true;
        minIndex = -1;
    }

    PUBLIC PQArr::PQArr(int _phySize,dist* d) :phySize(_phySize),offset(0){
        arr = new item[phySize];
        for(int i=0 ; i < phySize ; i++){
            arr[i].data = i;
            arr[i].key = d[i].weight;
        }
        logSize = phySize;
        isAllocated = true;
        calcMin();
    }


    PUBLIC PQArr::PQArr(item* _arr, int _size):offset(0){
        logSize = phySize = _size;
        arr = _arr;
        isAllocated = false;
        calcMin();
    }

    PUBLIC PQArr::PQArr(const PQArr &toCopy) {
        *this = toCopy;
    }

    PUBLIC PQArr::~PQArr(){
        if(isAllocated)
            delete[] arr;
    }

    PUBLIC item PQArr::getMin() { return min; }

    PRIVATE void PQArr::calcMin() {
        for(int i=0; i < logSize ; i++){
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
        if(arr[_item.data].key < min.key){
            min = arr[_item.data];
            minIndex = _item.data;
        }
    }

    PUBLIC item PQArr::deleteMin() {
        item _min = min;
        for(int i = minIndex; i < logSize-1; i++){
            arr[i] = arr[i+1];
        }
        logSize--;
        offset++;
        min = arr[0];
        calcMin();
        return _min;
    }

    PUBLIC bool PQArr::isEmpty() const{
        return logSize <=1 ; //the 0 index is dummy
    }

    PUBLIC void PQArr::DecreaseKey(int place, double newKey){
        arr[place-offset].key = newKey;
        if(newKey < min.key){
            min = arr[place-offset];
            minIndex = place-offset;
        }
    }

    void Build(PQArr& obj,item* arr, int size){
        obj = PQArr(arr,size);
    }


}