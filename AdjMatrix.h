#include <iostream>
#include <list> //TODO: implement our own list
#pragma once

using namespace std;
namespace Graph {
    class AdjMatrix {
    private:
        int** matrix;
    public:
        AdjMatrix(int n);

        bool IsAdjacent(int u, int v);

        list<int> GetAdjList(int u);

        void AddEdge(int u, int v, int c);

        void RemoveEdge(int u, int v);
    };

    AdjMatrix *MakeEmptyGraph(int n);
}