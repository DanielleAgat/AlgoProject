#include "AdjList.h"

namespace Graph {
    PUBLIC AdjList::AdjList(int n) : size(n) {
        listArr = new List[n];
    }
    PUBLIC void AdjList::AddEdge(int u, int v, int c) {
        listArr[u].AddToLst(REF v, REF c);
    }

    PUBLIC List AdjList::GetAdjList(int u) {
        return listArr[u];
    }
    PUBLIC bool AdjList::IsAdjacent(int u, int v) {
        if (listArr[u].findDataInList(REF v) != nullptr)
            return true;
        return false;
    }

    PUBLIC void AdjList::RemoveEdge(int u, int v) {
        listArr[u].removeFromList(REF v);
    }

    PUBLIC void AdjList::makeGraph(List &arcs) {

    }
}