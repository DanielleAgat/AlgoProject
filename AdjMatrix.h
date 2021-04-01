#include <iostream>
#include <List.h> //TODO: implement our own list
#pragma once

using namespace std;

class AdjMatrix {
private:
    int** matrix;
public:
    AdjMatrix(int n);
    void MakeEmptyGraph(int n);
    bool IsAdjacent(int u, int v);
    list<int> GetAdjList(int u);
    bool AddEdge(int u, int v, int c);
    bool RemoveEdge(int u, int v);
};
