#include "AdjList.h"

namespace Graph {
    PUBLIC AdjList::AdjList(int n) : size(n) {
        listArr = new List[n];
    }
    PUBLIC void AdjList::AddEdge(int u_start, int v_end, double c_weight) {
        arc tempArcToAdd;
        if (c_weight<0||u_start==v_end/*TODO:check if arc exists*/)
            throw invalid_argument("invalid input");
        tempArcToAdd.i_start=u_start;
        tempArcToAdd.j_end=v_end;
        tempArcToAdd.weight=c_weight;
        listArr[u_start].AddToLst(tempArcToAdd);
    }

    PUBLIC List AdjList::GetAdjList(int u_start) {
        return listArr[u_start];
    }
    PUBLIC bool AdjList::IsAdjacent(int u_start, int v_end) {
        arc tempArcToFind;
        tempArcToFind.i_start=u_start;
        tempArcToFind.j_end=v_end;
        if (listArr[u_start].findDataInList(REF tempArcToFind) != nullptr)
            return true;
        return false;
    }
    PUBLIC void AdjList::RemoveEdge(int u_start, int v_end) {
        arc tempArcToDelete;
        tempArcToDelete.i_start=u_start;
        tempArcToDelete.j_end=v_end;
        listArr[u_start].removeFromList(REF tempArcToDelete);
    }

    PUBLIC void AdjList::makeGraph(List* arcs) {
        int listSize=arcs->getNumOfArcsInLst();
        ListNode* currNode=arcs->getHead()->getNext();//ignore dummy head
        for(int i=0;i<listSize;i++){
            int currSource=currNode->getData().i_start;
            arc currArcFromCurrNode=currNode->getData();
            listArr[currSource].AddToLst(REF currArcFromCurrNode);
            currNode=currNode->getNext();
        }
    }
}