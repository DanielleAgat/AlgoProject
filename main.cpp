#include <iostream>
#include "Constants.h"

int main(int argc,char** argv) {
#include <fstream>

using namespace std;

void readFile(int,char**);



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

    int arc[3];
    while (!file.eof()) {
        if (!file.good()) {
            cout << "invalid input" << endl;
            exit(1);
        }
        file >> arc[0] >> arc[1] >> arc[2];
    }
    file.close();
    cout << endl;
}

