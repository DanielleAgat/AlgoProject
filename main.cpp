#include <iostream>
#include "Constants.h"
#include <fstream>
#include <list>

using namespace std;
list<arc> readFile(const string& , char**, int&, int&, int&);


int main(int argc,char** argv) {
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
    list<arc> arcs; //List of arcs
    string fileName = argv[1];
    fileName += ".txt";
    arcs = readFile(fileName,argv,n,s,t);

    //TODO: Build Graph twice, once with matrix once with list
    //TODO: Run 6 Algos
    //TODO: Print all path weights
    //TODO: print runtime of all 6 algos to another file (argv[2])



    return 0;
}


list<arc> readFile(const string& fileName, char** argv,int& n, int& s, int& t){
    ifstream file;
    file.open(fileName);
    if (!file) {
        cout << "invalid input" << endl;
        exit(1);
    }

    file >> n >> s >> t;
    list<arc> arcs;
    arc currArc;
    file >> currArc.i >> currArc.j >> currArc.weight;
    arcs.push_back(currArc);
    while (!file.eof()) {
        if (!file.good()) {
            cout << "invalid input" << endl;
            exit(1);
        }
        file >> currArc.i >> currArc.j >> currArc.weight;
        arcs.push_back(currArc);
    }
    file.close();
    return arcs;
}

