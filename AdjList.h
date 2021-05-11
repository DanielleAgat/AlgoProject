#pragma once
#include <iostream>
#include "List.h"
#include "Constants.h"
#include "BfsHelper.h"
#include "PriorityQueueHeap.h"
#include "PriorityQueueArray.h"

using namespace std;
namespace Graph {
    class AdjList {
        friend ostream& operator<<(ostream& os, const AdjList& lst);
    private:
        List* listArr;
        int size;


        //This method is suitable only for pq class with the following methods: buildHeap, DecreaseKey, deleteMin, isEmpty
        template<class pq>
        dist dijkstra(int s_start, int t_end) {
            //Init:
            auto *d = init(size, s_start);
            pq priorityQueue(size, d);

            //Search:
            while (!priorityQueue.isEmpty()) {
                int u = priorityQueue.deleteMin().data;//TODO: bug here in last test, does not reach 9, does 6 7, 6 8 but not 8 9
                ListNode *currNode = listArr[u].getHead()->getNext(); //ignoring dummy head
                int adjListSize = listArr[u].getNumOfArcsInLst();

                for (int j = 0; j < adjListSize; j++) {
                    int v = currNode->getData().j_end;
                    double uvWeight = currNode->getData().weight;
                    relaxDijkstra(d, u, v, uvWeight, REF priorityQueue);
                    currNode = currNode->getNext();
                }
            }
            if (d[t_end].weight != DBL_MAX)
                return d[t_end];
            else
                throw invalid_argument("invalid input");

        }


    public:
        AdjList(int n);
        void makeGraph(List* arcs);
        bool IsAdjacent(int u_start, int v_end);
        List GetAdjList(int u_start);
        List* getAdjListArr(){return listArr;}
        void AddEdge(int u_start, int v_end, double c_weight);
        void RemoveEdge(int u_start, int v_end);
        dist BellmanFord(int s, int t);
        dist dijkstraHeap(int s_start, int t_end){ return dijkstra<PQHeap>(s_start,t_end); }
        dist dijkstraArray(int s_start, int t_end){ return dijkstra<PQArr>(s_start,t_end); }
    };
}