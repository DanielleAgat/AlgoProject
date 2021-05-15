#pragma once
#include <iostream>
#include "List.h"
#include "PriorityQueueArray.h"
#include "PriorityQueueHeap.h"
#include "BfsHelper.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
namespace Graph {
    class AdjMatrix {
        friend ostream& operator<<(ostream& os, const AdjMatrix& mat);
    private:
        double** matrix;
        int size;

        //This method is suitable only for pq class with the following methods: buildHeap, DecreaseKey, deleteMin, isEmpty
        template<class pq>
        dist dijkstra(int s_start, int t_end) {
            //Init:
            dist toReturn;
            auto *d = init(size, s_start);
            pq priorityQueue(size-1, d);

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
                delete uAdj;
            }

            toReturn.isInfinite=d[t_end].isInfinite;
            toReturn.weight = d[t_end].weight;
            delete[] d;
            if (toReturn.isInfinite != true)
                return toReturn;
            else
                throw invalid_argument("invalid input");

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