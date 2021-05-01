#include "PriorityQueueArray.h"

namespace Graph{
    PUBLIC PQArr::PQArr(int _phySize) :phySize(_phySize){
        arr = new item[phySize];
        logSize = 0;
        isAllocated = true;
        minIndex = -1;
    }

    PUBLIC PQArr::PQArr(int _phySize,dist* d) :phySize(_phySize){
        arr = new item[phySize];
        for(int i=0 ; i < phySize ; i++){
            arr[i].data = i;
            arr[i].key = d[i].weight;
        }
        calcMin();
        logSize = phySize;
        isAllocated = true;
        minIndex = -1;
    }


    PUBLIC PQArr::PQArr(item* _arr, int _size) {
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
        arr = nullptr;
    }

    PUBLIC item PQArr::getMin() { return min; }

    PRIVATE void PQArr::calcMin() {
        for(int i; i < logSize ; i++){
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
        arr[++logSize] = _item;
        if(arr[logSize].key < min.key){
            min = arr[logSize];
            minIndex = logSize;
        }
    }

    PUBLIC item PQArr::deleteMin() {
        item _min = min;
        for(int i = minIndex; i < logSize-1; i++){
            arr[i] = arr[i+1];
        }
        logSize--;
        calcMin();
        return _min;
    }

    PUBLIC bool PQArr::isEmpty() const{
        return logSize == 0;
    }

    PUBLIC void PQArr::DecreaseKey(int place, double newKey){
        arr[place].key = newKey;
        if(newKey < min.key){
            min = arr[place];
            minIndex = place;
        }
    }

    void Build(PQArr& obj,item* arr, int size){
        obj = PQArr(arr,size);
    }


}