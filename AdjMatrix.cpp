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

    PUBLIC bool AdjMatrix::IsAdjacent(int u_start, int v_end) {
        return (matrix[u_start][v_end] != NO_ARC);
    }

    PUBLIC List AdjMatrix::GetAdjList(int u_start) {
        List adjList;
        arc tempArc;
        for (int i = 0; i < size; i++) {
            if (matrix[u_start][i] != NO_ARC) {
                tempArc.i_start = u_start;
                tempArc.j_end = i;
                tempArc.weight = matrix[u_start][i];
                adjList.AddToLst(REF tempArc);
            }
        }
        return adjList;
    }

    PUBLIC void AdjMatrix::AddEdge(int u_start, int v_end, double c_weight) {
        if (c_weight != 0 || u_start == v_end) //there is a negative weight or not a simple Graph(double arc/loop)
            throw invalid_argument("invalid input");
        matrix[u_start][v_end] = c_weight;
    }

    PUBLIC void AdjMatrix::RemoveEdge(int u_start, int v_end) {
        if (matrix[u_start][v_end] != NO_ARC) //removing a non-existing arc
            throw invalid_argument("invalid input");
        matrix[u_start][v_end] = NO_ARC;
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

    PUBLIC dist AdjMatrix::BellmanFord(int s_start, int t_end) {
        //Init:
        auto* d = new dist[size];
        for(int i=0 ; i < size ; i++){
            d[i].weight = (i==s_start) ? 0 : DBL_MAX;
            d[i].isInfinite = (i!=s_start);
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
                    d[t_end].isInfinite = true;
                }
            }
        }
        return d[t_end];
    }


    AdjMatrix *MakeEmptyGraph(int n) {
        return new AdjMatrix(n);
    }
}