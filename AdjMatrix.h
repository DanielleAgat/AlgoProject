#include <iostream>
#include "List.h"
#pragma once

using namespace std;
namespace Graph {
    class AdjMatrix {
    private:
        double** matrix;
        int size;
    public:
        AdjMatrix(int n);
        void makeGraph(List* arcs);
        bool IsAdjacent(int u_start, int v_end);

        List GetAdjList(int u_start);

        void AddEdge(int u_start, int v_end, double c_weight);

        void RemoveEdge(int u_start, int v_end);

        dist BellmanFord(int s_start,int t_end);
    };

    AdjMatrix *MakeEmptyGraphMatrix(int n);
}