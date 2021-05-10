#include "AdjMatrix.h"

namespace Graph {

    PUBLIC AdjMatrix::AdjMatrix(int n) {
        size = n;
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
                if(i==j){
                    matrix[i][j]=0;
                }
                else {
                    matrix[i][j] = NO_ARC;
                }
            }
        }
    }

    PUBLIC bool AdjMatrix::IsAdjacent(int u_start, int v_end) {
        return (matrix[u_start][v_end] != NO_ARC);
    }

    PUBLIC List* AdjMatrix::GetAdjList(int u_start) {
        List* adjList=new List;
        arc tempArc;
        for (int i = 1; i < size; i++) {
            if (matrix[u_start][i] != NO_ARC) {
                tempArc.i_start = u_start;
                tempArc.j_end = i;
                tempArc.weight = matrix[u_start][i];
                adjList->AddToLst(REF tempArc);
            }
        }
        return adjList;
    }

    PUBLIC void AdjMatrix::AddEdge(int u_start, int v_end, double c_weight) {
        if (c_weight < 0 || u_start == v_end ||
            matrix[u_start][v_end] != NO_ARC) //there is a negative weight or not a simple Graph(double arc/loop)
            throw invalid_argument("invalid input");
        matrix[u_start][v_end] = c_weight;
    }

    PUBLIC void AdjMatrix::RemoveEdge(int u_start, int v_end) {
        if (matrix[u_start][v_end] != NO_ARC) //removing a non-existing arc
            throw invalid_argument("invalid input");
        matrix[u_start][v_end] = NO_ARC;
    }

    PUBLIC void AdjMatrix::makeGraph(List *arcs) {
        int listSize = arcs->getNumOfArcsInLst();
        ListNode *currNode = arcs->getHead()->getNext();
        for (int i = 0; i < listSize; i++) {
            arc currArc = currNode->getData();
            AddEdge(currArc.i_start, currArc.j_end, currArc.weight);
            currNode = currNode->getNext();
        }
    }

    PUBLIC dist AdjMatrix::BellmanFord(int s_start, int t_end) {
        //Init:
        auto *d = init( size, s_start);

        //Main Loop:
        for (int t = 1; t < size; t++) {
            for (int i = 1; i < size; i++) {
                for (int j = 1; j < size; j++) {
                    relax(d, i, j, matrix[i][j]);
                }
            }
        }

        //Check termination:
        for (int i = 1; i < size; i++) {
            for (int j = 1; j < size; j++) {
                if (d[j].weight > d[i].weight + matrix[i][j]) {
                    cout << "Negative Cycle!" << endl;
                    d[t_end].isInfinite = true;
                }
            }
        }
        return d[t_end];
    }
    ostream& operator<<(ostream& os, const AdjMatrix& mat){
        for(int i=0;i<mat.size;i++){
            for(int j=0;j<mat.size;j++){
                os<<mat.matrix[i][j]<<"       ";
            }
            os<<endl;
        }
        return os;
    }

}