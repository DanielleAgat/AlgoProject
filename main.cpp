#include <iostream>
#include "Constants.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include <fstream>
#include <list>

using namespace std;
namespace Graph {
    List readFile(const string &, char **, int &, int &, int &);

    void adjacencyDijkstraHeap(List &arcs/*TODO: ADD THINGS*/);

    void adjacencyDijkstraArr(List &arcs/*TODO: ADD THINGS*/);

    void adjacencyBellmanFord(List &arcs/*TODO: ADD THINGS*/);

    void matrixDijkstraHeap(List &arcs/*TODO: ADD THINGS*/);

    void matrixDijkstraArr(List &arcs/*TODO: ADD THINGS*/);

    void matrixBellmanFord(List &arcs/*TODO: ADD THINGS*/);

    AdjList makeGraphOnAdjList(List &arcs);
    AdjMatrix makeGraphOnAdjMatrix(List &arcs);


    int main(int argc, char **argv) {
        /////////////////////////////////////** ReadFile**///////////////////////////////////
        int n; //num of vertexes
        int s; //start vertex
        int t; //destination vertex
        //list<arc> arcs; //List of arcs
        List arcs;
        string inputFileName = argv[1];
        inputFileName += ".txt";
        string outputFileName = argv[2];
        outputFileName += ".txt";
        arcs = readFile(inputFileName, argv, REF n, REF s, REF t);
        /////////////////////////////////////** Make graphs**///////////////////////////////////
        AdjMatrix adjMat (n);
        AdjList adjLst(n);
        adjMat.makeGraph(REF arcs);
        adjLst.makeGraph(REF arcs);
        /////////////////////////////////////** Call Algos**///////////////////////////////////
        adjacencyBellmanFord(REF arcs/*TODO: ADD THINGS*/);
        adjacencyDijkstraArr(REF arcs/*TODO: ADD THINGS*/);
        adjacencyDijkstraHeap(REF arcs/*TODO: ADD THINGS*/);
        matrixBellmanFord(REF arcs/*TODO: ADD THINGS*/);
        matrixDijkstraArr(REF arcs/*TODO: ADD THINGS*/);
        matrixDijkstraHeap(REF arcs/*TODO: ADD THINGS*/);

        //TODO: Print all path weights
        //TODO: print runtime of all 6 algos to another file (argv[2])


        return 0;
    }


    PUBLIC List readFile(const string &fileName, char **argv, int &n, int &s, int &t) {
        ifstream file;
        file.open(fileName);
        if (!file) {
            cout << "invalid input" << endl;
            exit(1);
        }
        file >> n >> s >> t;
        List arcs;
        arc currArc;
//    file >> currArc.i >> currArc.j >> currArc.weight; /// why need extra one before loop?
//    arcs.push_back(currArc);
        while (!file.eof()) {
            if (!file.good()) {
                cout << "invalid input" << endl;
                exit(1);
            }
            file >> currArc.i >> currArc.j >> currArc.weight;
            arcs.AddToLst(REF currArc);
        }
        file.close();
        return arcs;
    }

    PUBLIC AdjList makeGraphOnAdjList(List &arcs) {

    }

    PUBLIC AdjMatrix makeGraphOnAdjMatrix(List &arcs) {

    }

}