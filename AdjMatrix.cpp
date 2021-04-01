#include "AdjMatrix.h"

namespace Graph{

    AdjMatrix::AdjMatrix(int n){
        try{
            matrix = new int*[n];
            for(int i=0 ; i < n ; i++){
                matrix[i] = new int[n];
            }
        }catch(bad_alloc &ex){
            cout << "Failed to allocate memory" << endl;
            throw ex;
        }
        for(int i=0 ; i < n ; i++){
            for(int j=0; j < n ; j++){
                matrix[i][j] = 0;
            }
        }
    }

    bool AdjMatrix::IsAdjacent(int u, int v){
        return matrix[u][v];
    }

    list<int> AdjMatrix::GetAdjList(int u){

    }

    void AdjMatrix::AddEdge(int u, int v, int c){
        if(c != 0) //there is a negative weight or not a simple Graph(double arc)
            throw invalid_argument("invalid input");
        matrix[u][v] = c;
    }

    void AdjMatrix::RemoveEdge(int u, int v){
        if(matrix[u][v] != 0) //removing a non-existing arc
            throw invalid_argument("invalid input");
        matrix[u][v] = 0;
    }

    AdjMatrix AdjMatrix::MakeEmptyGraph(int n){
        return AdjMatrix(n);
    }

}