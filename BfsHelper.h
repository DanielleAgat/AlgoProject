#pragma once
#include <iostream>
#include "Constants.h"
#include "PriorityQueueHeap.h"
#include "PriorityQueueArray.h"

using namespace std;

namespace Graph{

    dist* init(int size,int s_start){
        auto* d = new dist[size];
        for(int i=0 ; i < size ; i++){
            d[i].weight = (i==s_start) ? 0 : DBL_MAX;
            d[i].isInfinite = (i!=s_start);
        }
    }


    void relax(dist* d, int u, int v,double c){
        if(d[v].weight > d[u].weight + c){
            d[v].weight = d[u] .weight + c;
            d[v].isInfinite = false;
        }
    }

    //This function is suitable only for pq class with DecreaseKey method!
    template<class pq>
    void relaxDijkstra(dist* d, int u, int v,double c,pq q){
        if(d[v].weight > d[u].weight + c){
            d[v].weight = d[u] .weight + c;
            d[v].isInfinite = false;
            q.DecreaseKey(v,d[v].weight);
        }
    }


};