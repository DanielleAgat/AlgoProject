#pragma once
#include <iostream>
#include "Constants.h"


using namespace std;

namespace Graph{

    dist* init(int size,int s_start);


    void relax(dist* d, int u, int v,double c);

    //This function is suitable only for pq class with DecreaseKey method!
    template<class pq>
    void relaxDijkstra(dist* d, int u, int v,double c,pq q){
        if(d[v].weight > d[u].weight + c){
            d[v].weight = d[u] .weight + c;
            d[v].isInfinite = false;
            q.DecreaseKey(v,d[v].weight);
        }
    }


}