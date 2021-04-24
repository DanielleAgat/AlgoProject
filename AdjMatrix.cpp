#include <cfloat>
#include "AdjMatrix.h"

namespace Graph {

    PUBLIC AdjMatrix::AdjMatrix(int n) {
        size=n;
        try {
            matrix = new double *[n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new double[n];
            }
        } catch (bad_alloc &ex) {
            cout << "Failed to allocate memory" << endl;
            throw ex;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = NO_ARC;
            }
        }
    }

    PUBLIC bool AdjMatrix::IsAdjacent(int u, int v) {
        return (matrix[u][v] != NO_ARC);
    }

    PUBLIC List AdjMatrix::GetAdjList(int u) {
        List adjList;
        arc tempArc;
        for (int i = 0; i < size; i++) {
            if (matrix[u][i] != NO_ARC) {
                tempArc.i_start = u;
                tempArc.j_end = i;
                tempArc.weight = matrix[u][i];
                adjList.AddToLst(REF tempArc);
            }
        }
        return adjList;
    }

    PUBLIC void AdjMatrix::AddEdge(int u, int v, int c) {
        if (c != 0 || u == v) //there is a negative weight or not a simple Graph(double arc/loop)
            throw invalid_argument("invalid input");
        matrix[u][v] = c;
    }

    PUBLIC void AdjMatrix::RemoveEdge(int u, int v) {
        if (matrix[u][v] != NO_ARC) //removing a non-existing arc
            throw invalid_argument("invalid input");
        matrix[u][v] = NO_ARC;
    }

    PUBLIC void AdjMatrix::makeGraph(List* arcs) {
        int listSize = arcs->getNumOfArcsInLst();
        ListNode *currNode = arcs->getHead();
        arc currArc = currNode->getData();
        for (int i = 0; i < listSize; i++) {
            AddEdge(currArc.i_start, currArc.j_end, currArc.weight);
            currNode = currNode->getNext();
        }
    }

    PUBLIC dist AdjMatrix::BellmanFord(int s, int t) {
        //Init:
        auto* d = new dist[size];
        for(int i=0 ; i < size ; i++){
            d[i].weight = (i==s) ? 0 : DBL_MAX;
            d[i].isInfinite = (i!=s);
        }

        auto* p = new int[size]; //TODO: Consider removing the p[] array since it has no usage
        for(int i=0; i < size ; i++){
            p[i] = NULL;
        }

        //Main Loop:
        for(int t=1 ; t < size ; t++){
            for(int i=0; i < size ; i++){
                for(int j=0; j < size ; j++){
                    //Relax:
                    if(d[j].weight > d[i].weight + matrix[i][j]){
                        d[j].weight = d[i] .weight+ matrix[i][j];
                        d[j].isInfinite = false;
                        p[j] = i;
                    }
                }
            }
        }

        //Check termination:
        for(int i=0; i < size ; i++){
            for(int j=0; j < size ; j++){
                if(d[j].weight > d[i].weight + matrix[i][j]){
                    cout << "Negative Cycle!" << endl;
                    d[t].isInfinite = true;
                }
            }
        }
        return d[t];
    }


    AdjMatrix *MakeEmptyGraph(int n) {
        return new AdjMatrix(n);
    }
}