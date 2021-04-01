#include <iostream>
#include <fstream>

using namespace std;

void readFile(int,char**);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


void readFile(int argc, char** argv){
    int n; //num of vertexs
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

    while (!file.eof()) {
        if (!file.good()) {
            cout << "invalid input" << endl;
            exit(1);
        }
        cout << val << ", ";
        file >> val;
    }
    file.close();
    cout << endl;
}

