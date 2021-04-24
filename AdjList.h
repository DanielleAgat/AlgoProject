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
        bool IsAdjacent(int u, int v);

        List GetAdjList(int u);

        void AddEdge(int u, int v, int c);

        void RemoveEdge(int u, int v);
    };

    AdjList *MakeEmptyGraphList(int n);
}