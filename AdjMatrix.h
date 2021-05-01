#include <iostream>
#include "List.h"
#include "PriorityQueueArray.h"
#include "PriorityQueueHeap.h"
#include "BfsHelper.h"
#pragma once

using namespace std;
namespace Graph {
    class AdjMatrix {
    private:
        double** matrix;
        int size;

        //This method is suitable only for pq class with the following methods: buildHeap, DecreaseKey, deleteMin, isEmpty
        template<class pq>
        dist dijkstra(int s_start, int t_end) {
            //Init:
            auto *d = init(size, s_start);
            pq priorityQueue(size, d);

            //Search:
            while (!priorityQueue.isEmpty()) {
                int u = priorityQueue.deleteMin().data;
                List *uAdj = GetAdjList(u);
                ListNode *currNode = uAdj->getHead()->getNext(); //ignoring dummy head
                int adjListSize = uAdj->getNumOfArcsInLst();

                for (int j = 0; j < adjListSize; j++) {
                    int v = currNode->getData().j_end;
                    double uvWeight = currNode->getData().weight;
                    relaxDijkstra(d, u, v, uvWeight, priorityQueue);
                    currNode = currNode->getNext();
                }
            }
            return d[t_end];
        }

    public:
        AdjMatrix(int n);
        void makeGraph(List* arcs);
        bool IsAdjacent(int u_start, int v_end);
        List* GetAdjList(int u_start);
        dist dijkstraHeap(int s_start, int t_end){ return dijkstra<PQHeap>(s_start,t_end); }
        dist dijkstraArray(int s_start, int t_end){ return dijkstra<PQArr>(s_start,t_end); }
        void AddEdge(int u_start, int v_end, double c_weight);
        void RemoveEdge(int u_start, int v_end);
        dist BellmanFord(int s_start,int t_end);

    };
}