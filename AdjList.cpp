#include "AdjList.h"

namespace Graph {
    PUBLIC AdjList::AdjList(int n) : size(n) {
        listArr = new List[n];
    }
    PUBLIC void AdjList::AddEdge(int u, int v, int c) {
        arc tempArcToDelete;
        tempArcToDelete.i=u;
        tempArcToDelete.j=v;
        tempArcToDelete.weight=c;
        listArr[u].AddToLst(tempArcToDelete);
    }

    PUBLIC List AdjList::GetAdjList(int u) {
        return listArr[u];
    }
    PUBLIC bool AdjList::IsAdjacent(int u, int v) {
        arc tempArcToDelete;
        tempArcToDelete.i=u;
        tempArcToDelete.j=v;
        if (listArr[u].findDataInList(REF tempArcToDelete) != nullptr)
            return true;
        return false;
    }
    PUBLIC void AdjList::RemoveEdge(int u, int v) {
        arc tempArcToDelete;
        tempArcToDelete.i=u;
        tempArcToDelete.j=v;
        listArr[u].removeFromList(REF tempArcToDelete);
    }

    PUBLIC void AdjList::makeGraph(List &arcs) {
        int listSize=arcs.getNumOfArcsInLst();
        ListNode* currNode=arcs.getHead();
        for(int i=0;i<listSize;i++){
            int currSource=currNode->getData().i;
            arc currArcFromCurrNode=currNode->getData();
            listArr[currSource].AddToLst(REF currArcFromCurrNode);
            currNode=currNode->getNext();
        }
    }
}