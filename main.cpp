#include <iostream>
#include "Constants.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include <fstream>
#include <list>

using namespace std;
using namespace Graph;
void readFile(List* arcs,const string &, int &, int &, int &);

void adjacencyDijkstraHeap(List &arcs/*TODO: ADD THINGS*/);

void adjacencyDijkstraArr(List &arcs/*TODO: ADD THINGS*/);

void adjacencyBellmanFord(List &arcs/*TODO: ADD THINGS*/);

void matrixDijkstraHeap(List &arcs/*TODO: ADD THINGS*/);

void matrixDijkstraArr(List &arcs/*TODO: ADD THINGS*/);

void matrixBellmanFord(List &arcs/*TODO: ADD THINGS*/);
int main() {
    /////////////////////////////////////** ReadFile**///////////////////////////////////
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
    //list<arc> arcs; //List of arcs
    List* arcs=new List();
    //string inputFileName = argv[1]; good
    string inputFileName = "readmePLS"; // for check
    inputFileName += ".txt";
    // string outputFileName = argv[2]; good
    // outputFileName += ".txt";
    readFile(arcs,inputFileName, REF n, REF s, REF t);
    /////////////////////////////////////** Make graphs**///////////////////////////////////
    AdjMatrix adjMat (n);
    AdjList adjLst(n);
    adjMat.makeGraph(REF arcs);
    adjLst.makeGraph(REF arcs);
    /////////////////////////////////////** Call Algos**///////////////////////////////////
//        adjacencyBellmanFord(REF arcs/*TODO: ADD THINGS*/);
//        adjacencyDijkstraArr(REF arcs/*TODO: ADD THINGS*/);
//        adjacencyDijkstraHeap(REF arcs/*TODO: ADD THINGS*/);
//        matrixBellmanFord(REF arcs/*TODO: ADD THINGS*/);
//        matrixDijkstraArr(REF arcs/*TODO: ADD THINGS*/);
//        matrixDijkstraHeap(REF arcs/*TODO: ADD THINGS*/);

    //TODO: Print all path weights
    //TODO: print runtime of all 6 algos to another file (argv[2])


    return 0;
}
    PUBLIC void readFile(List* arcs,const string &fileName, int &n, int &s, int &t) {
        ifstream file;
        file.open(fileName);
        if (!file) {
            cout << "invalid input" << endl;
            exit(1);
        }
        file >> n >> s >> t;
        arc currArc;
//    file >> currArc.i >> currArc.j >> currArc.weight; /// why need extra one before loop?
//    arcs.push_back(currArc);
        while (!file.eof()) {
            if (!file.good()) {
                cout << "invalid input" << endl;
                exit(1);
            }
            file >> currArc.i >> currArc.j >> currArc.weight;
            arcs->AddToLst(REF currArc);
        }
        file.close();
    }