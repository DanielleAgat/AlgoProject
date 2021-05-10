#include <iostream>
#include "Constants.h"
#include "AdjList.h"
#include "AdjMatrix.h"
#include "List.h"
#include <fstream>

using namespace std;
using namespace Graph;

void readFile(List* arcs,const string &, int &, int &, int &);

int main() {
    /////////////////////////////////////** ReadFile**///////////////////////////////////
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
    //list<arc> arcs; //List of arcs
    auto* arcs=new Graph::List();
    //string inputFileName = argv[1]; good
    string inputFileName = "readmePLS"; //TODO: replace with program args
    inputFileName += ".txt";
    string outputFileName  = "output.txt"; //TODO: replace with program args
    // string outputFileName = argv[2]; good
    // outputFileName += ".txt";
    try{
        readFile(arcs,inputFileName, REF n, REF s, REF t);
    }catch(exception &ex){
        cout << ex.what() << endl;
        exit(1);
    }
    /////////////////////////////////////** Make graphs**///////////////////////////////////
    AdjMatrix adjMat(n+1);
    AdjList adjLst(n+1);
    adjLst.makeGraph(REF arcs);//
    adjMat.makeGraph(REF arcs);
    cout<<"AdjList: \n"<<adjLst;
    cout<<"AdjMatrix:  \n"<<adjMat;

    /////////////////////////////////////** Call Algos**///////////////////////////////////
    //Adjacency Dijkstra heap :
    auto start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    cout << "Adjacency Dijkstra heap <" << adjLst.dijkstraHeap(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
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
    cout << "Adjacency Dijkstra array <" << adjLst.dijkstraArray(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Adjacency Dijkstra heap  <" << fixed << time_taken << setprecision(9) << ">" << endl;

    //Adjacency Bellman Ford :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    cout << "Adjacency Bellman Ford <" << adjLst.BellmanFord(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Adjacency Dijkstra heap <" << fixed << time_taken << setprecision(9) << ">" << endl;


    //Matrix Dijkstra heap :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    cout << "Matrix Dijkstra heap <" << adjMat.dijkstraHeap(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Matrix Dijkstra heap <" << fixed << time_taken << setprecision(9) << ">" << endl;

    //Matrix Dijkstra array  :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    cout << "Matrix Dijkstra array <" << adjMat.dijkstraArray(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
    end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

    myfile << "Matrix Dijkstra array <" << fixed << time_taken << setprecision(9) << ">" << endl;


    //Matrix Bellman Ford :
    start = chrono::high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    cout << "Matrix Bellman Ford <" << adjMat.BellmanFord(s,t).weight << ">" << endl;// Here you put the name of the function you wish to measure
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
            cout << "invalid input" << endl;
            exit(1);
        }
        file >> n >> s >> t;
        Graph::arc currArc;

        for(int i=0;i<n;i++){
            if (!file.good()) {
                cout << "invalid input" << endl;
                exit(1);
            }
            file >> currArc.i_start >> currArc.j_end >> currArc.weight;
            if(currArc.weight<0)
                throw invalid_argument("invalid input");
            arcs->Graph::List::AddToLst(REF currArc);
        }

        file.close();
        if(arcs->getNumOfArcsInLst()!=n)
            throw invalid_argument("invalid input");
    }
