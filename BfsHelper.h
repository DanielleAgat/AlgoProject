#pragma once
#include <iostream>

using namespace std;

namespace Graph{

    void relax(dist* d, int u, int v,double c){
        if(d[v].weight > d[u].weight + c){
            d[v].weight = d[u] .weight + c;
            d[v].isInfinite = false;
        }
    }




};