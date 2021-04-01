#include <iostream>
#include "Constants.h"
#include <fstream>
#include <list>

using namespace std;
list<arc> readFile(int, char**, int&, int&, int&);


int main(int argc,char** argv) {
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
    list<arc> arcs; //List of arcs
    arcs = readFile(argc,argv,n,s,t);

    

    return 0;
}


list<arc> readFile(int argc, char** argv,int& n, int& s, int& t){
    ifstream file;
    string fileName = argv[1];
    fileName += ".txt";
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

