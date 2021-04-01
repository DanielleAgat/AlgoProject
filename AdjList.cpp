#include "AdjList.h"


namespace Graph {
    AdjList::AdjList(int n) : size(n) {
        listArr = new List[n];
    }
//blabla
//blaaaa

    void AdjList::AddEdge(int u, int v, int c) {
        listArr[u].AddToLst(v, c);
    }

    List AdjList::GetAdjList(int u) {
        return listArr[u];
    }
    bool AdjList::IsAdjacent(int u, int v) {
        if (listArr[u].findDataInList(v) != nullptr)
            return true;
        return false;
    }

    void AdjList::RemoveEdge(int u, int v) {
        listArr[u].removeFromList(v);
    }
}