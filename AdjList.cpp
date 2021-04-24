
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

    PUBLIC void AdjList::makeGraph(List* arcs) {
        int listSize=arcs->getNumOfArcsInLst();
        ListNode* currNode=arcs->getHead();
        for(int i=0;i<listSize;i++){
            int currSource=currNode->getData().i;
            arc currArcFromCurrNode=currNode->getData();
            listArr[currSource].AddToLst(REF currArcFromCurrNode);
            currNode=currNode->getNext();
        }
    }

    PUBLIC dist AdjList::BellmanFord(int s, int t) {
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
            for(int u=0; u < size ; u++){
                ListNode* currNode = listArr[u].getHead()->getNext(); //ignoring dummy head
                int adjListSize = listArr[u].getNumOfArcsInLst();
                for(int j=0; j < adjListSize ; j++){
                    //Relax:
                    relax(d,u,currNode->getData().j,currNode->getData().weight);
                    currNode=currNode->getNext();
                }
            }
        }

        //Check termination:
        for(int u=0; u < size ; u++){
            ListNode* currNode = listArr[u].getHead()->getNext(); //ignoring dummy head
            int adjListSize = listArr[u].getNumOfArcsInLst();
            for(int j=0; j < adjListSize ; j++){
                int v = currNode->getData().j;
                double uvWeight = currNode->getData().weight;
                //Relax:
                if(d[v].weight > d[u].weight + uvWeight){
                    cout << "Negative Cycle!" << endl;
                    d[t].isInfinite = true;
                }
                currNode=currNode->getNext();
            }
        }

        return d[t];
    }
}