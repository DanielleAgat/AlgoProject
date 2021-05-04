#include "BfsHelper.h"

namespace Graph{
    dist* init(int size,int s_start){
        auto* d = new dist[size];
        for(int i=0 ; i < size ; i++){
            d[i].weight = (i==s_start) ? 0 : DBL_MAX;
            d[i].isInfinite = (i!=s_start);
        }
        return d;
    }


    void relax(dist* d, int u, int v,double c){
        if(d[v].weight > d[u].weight + c){
            d[v].weight = d[u] .weight + c;
            d[v].isInfinite = false;
        }
    }


}