#include <iostream>
#include "Constants.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include "chrono"
#include "iomanip"
#include "List.h"
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS


using namespace std;
using namespace Graph;

void readFile(List* arcs,const string &, int &, int &, int &);

int main(int argc, char **argv) {
    /////////////////////////////////////** ReadFile**///////////////////////////////////
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
    double weightToPrint;
    //List of arcs
    auto* arcs=new Graph::List();
    string inputFileName = argv[1];
    string outputFileName = argv[2];

     try{
        readFile(arcs,inputFileName, REF n, REF s, REF t);
    }catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    /////////////////////////////////////** Make graphs**///////////////////////////////////
    AdjMatrix adjMat(n+1);
    AdjList adjLst(n+1);
    try{
        adjLst.makeGraph(REF arcs);
        adjMat.makeGraph(REF arcs);
    }catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }


    /////////////////////////////////////** Call Algos**///////////////////////////////////
    //Adjacency Dijkstra heap :
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    try {
        weightToPrint=adjLst.dijkstraHeap(s, t).weight;
        cout << "Adjacency Dijkstra heap <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    auto end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    ofstream myfile(outputFileName); // The name of the file which is in argv[2]

    myfile << "Adjacency Dijkstra heap  <" << fixed << time_taken << setprecision(9) << ">" << endl;

    //Adjacency Dijkstra array :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    try {
        weightToPrint=adjLst.dijkstraArray(s, t).weight;
        cout << "Adjacency Dijkstra array <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Adjacency Dijkstra heap  <" << fixed << time_taken << setprecision(9) << ">" << endl;

    //Adjacency Bellman Ford :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    try {
        weightToPrint=adjLst.BellmanFord(s, t).weight;
        cout << "Adjacency Bellman Ford <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Adjacency Dijkstra heap <" << fixed << time_taken << setprecision(9) << ">" << endl;


    //Matrix Dijkstra heap :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    try {
        weightToPrint = adjMat.dijkstraHeap(s, t).weight;
        cout << "Matrix Dijkstra heap <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Matrix Dijkstra heap <" << fixed << time_taken << setprecision(9) << ">" << endl;

    //Matrix Dijkstra array  :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);



    try {
        weightToPrint=adjMat.dijkstraArray(s, t).weight;
        cout << "Matrix Dijkstra array <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Matrix Dijkstra array <" << fixed << time_taken << setprecision(9) << ">" << endl;


    //Matrix Bellman Ford :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    try {
        weightToPrint=adjMat.BellmanFord(s, t).weight;
        cout << "Matrix Bellman Ford <" << weightToPrint << ">"
             << endl;// Here you put the name of the function you wish to measure
    }
    catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Matrix Bellman Ford <" << fixed << time_taken << setprecision(9) << ">" << endl;
    myfile.close();


    return 0;
}
    PUBLIC void readFile(List* arcs,const string &fileName, int &n, int &s, int &t) {
        ifstream file;
        file.open(fileName);
        if (!file) {
            file.close();
            throw invalid_argument("invalid input");
        }
        file >> n >> s >> t;
        Graph::arc currArc;
        if(t>n||s>n){
            file.close();
            throw invalid_argument("invalid input");
        }
        while (!file.eof()) {
            char peek=file.peek();
            if(peek=='\n'){
                file.get(); //ignore \n
            }
            else if(peek==-1){
                break;
            }
            else {
                try {
                    file >> currArc.i_start >> currArc.j_end >> currArc.weight;
                }
                catch (exception &ex) {
                    file.close();
                    throw invalid_argument("invalid input");
                }
                if (currArc.weight < 0 || currArc.j_end > n || currArc.i_start < 1) {
                    file.close();
                    throw invalid_argument("invalid input");
                }
                arcs->Graph::List::AddToLst(REF currArc);
            }
        }
        file.close();
    }
