#include <iostream>
#include "Constants.h"
#include <fstream>
#include <list>

using namespace std;

int main(int argc,char** argv) {

    return 0;
}


void readFile(int argc, char** argv){
    int n; //num of vertexes
    int s; //start vertex
    int t; //destination vertex
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
    cout << endl;
}

