#include <iostream>
#include "List.h"
#pragma once

using namespace std;
namespace Graph {
    class AdjMatrix {
    private:
        int** matrix;
        int _n;
    public:
        AdjMatrix(int n);
        void makeGraph(List &arcs);
        bool IsAdjacent(int u, int v);

        List GetAdjList(int u);

        void AddEdge(int u, int v, int c);

        void RemoveEdge(int u, int v);
    };

    AdjMatrix *MakeEmptyGraph(int n);
}