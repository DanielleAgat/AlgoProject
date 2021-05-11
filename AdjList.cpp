#include "AdjList.h"

namespace Graph {
    PUBLIC AdjList::AdjList(int n) : size(n) {
        listArr = new List[n];
    }
    PUBLIC void AdjList::AddEdge(int u_start, int v_end, double c_weight) {
        arc tempArcToAdd;
        tempArcToAdd.i_start = u_start;
        tempArcToAdd.j_end = v_end;
        tempArcToAdd.weight = c_weight;
        if (c_weight < 0 || u_start == v_end || listArr[u_start].findDataInList(tempArcToAdd) != nullptr
            || !isValidVertexes(u_start, v_end, size))
            throw invalid_argument("invalid input");
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
            arc currArcFromCurrNode=currNode->getData();
            AddEdge(currArcFromCurrNode.i_start,currArcFromCurrNode.j_end,currArcFromCurrNode.weight);
            currNode=currNode->getNext();
        }
    }

    PUBLIC dist AdjList::BellmanFord(int s, int t) {
        //Init:
        auto* d = init(size,s);
        dist toReturn;
        //Main Loop:
        for(int i=1 ; i < size ; i++){
            for(int u=0; u < size ; u++){
                ListNode* currNode = listArr[u].getHead()->getNext(); //ignoring dummy head
                int adjListSize = listArr[u].getNumOfArcsInLst();
                for(int j=0; j < adjListSize ; j++){
                    relax(d,u,currNode->getData().j_end,currNode->getData().weight);
                    currNode=currNode->getNext();
                }
            }
        }
        //Check termination:
        for(int u=0; u < size ; u++){
            ListNode* currNode = listArr[u].getHead()->getNext(); //ignoring dummy head
            int adjListSize = listArr[u].getNumOfArcsInLst();
            for(int j=0; j < adjListSize ; j++){
                int v = currNode->getData().j_end;
                double uvWeight = currNode->getData().weight;
                //Relax:
                if(d[v].weight > d[u].weight + uvWeight){
                    cout << "Negative Cycle!" << endl;
                    d[t].isInfinite = true;
                }
                currNode=currNode->getNext();
            }
        }
        toReturn=d[t];
        if (toReturn.isInfinite != true)
            return toReturn;
        else
            throw invalid_argument("invalid input");

    }
    ostream& operator<<(ostream& os, const AdjList& lst){
        for(int i=0;i<lst.size;i++){
            os<<lst.listArr[i]<<endl;
        }
        return os;
    }
}