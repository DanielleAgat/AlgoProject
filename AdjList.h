#pragma once
#include <iostream>
#include "List.h"
#include "Constants.h"

using namespace std;
namespace Graph {
    class AdjList {

    private:
        List* listArr;
        int size;
    public:
        AdjList(int n);
        void makeGraph(List* arcs);
        bool IsAdjacent(int u_start, int v_end);
        List GetAdjList(int u_start);
        List* getAdjListArr(){return listArr;}
        void AddEdge(int u_start, int v_end, double c_weight);

        void RemoveEdge(int u_start, int v_end);
    };

    AdjList *MakeEmptyGraphList(int n);
}