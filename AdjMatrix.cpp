#include "AdjMatrix.h"

namespace Graph {

    PUBLIC AdjMatrix::AdjMatrix(int n) {
        try {
            matrix = new int *[n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
            }
        } catch (bad_alloc &ex) {
            cout << "Failed to allocate memory" << endl;
            throw ex;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    PUBLIC bool AdjMatrix::IsAdjacent(int u, int v) {
        return matrix[u][v];
    }

    PUBLIC List AdjMatrix::GetAdjList(int u) {
        List adjList;
        arc tempArc;
        for (int i = 0; i < _n; i++) {
            if (matrix[u][i] > 0) { //TODO : change
                tempArc.i = u;
                tempArc.j = i;
                tempArc.weight = matrix[u][i];
                adjList.AddToLst(REF tempArc);
            }
        }
        return adjList;
    }

    PUBLIC void AdjMatrix::AddEdge(int u, int v, int c) {
        if (c != 0) //there is a negative weight or not a simple Graph(double arc)
            throw invalid_argument("invalid input");
        matrix[u][v] = c;
    }

    PUBLIC void AdjMatrix::RemoveEdge(int u, int v) {
        if (matrix[u][v] != 0) //removing a non-existing arc
            throw invalid_argument("invalid input");
        matrix[u][v] = 0;
    }

    PUBLIC void AdjMatrix::makeGraph(List* arcs) {
        int listSize = arcs->getNumOfArcsInLst();
        ListNode *currNode = arcs->getHead();
        arc currArc = currNode->getData();
        for (int i = 0; i < listSize; i++) {
            AddEdge(currArc.i, currArc.j, currArc.weight);
            currNode = currNode->getNext();
        }
    }

    PUBLIC STATIC AdjMatrix *MakeEmptyGraph(int n) {
        return new AdjMatrix(n);
    }
}