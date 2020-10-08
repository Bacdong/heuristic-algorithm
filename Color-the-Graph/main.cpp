#include <iostream>
#include <cstring>
#include <fstream>

#define maxN 10

using namespace std;

int arr[maxN][maxN];
int qtyColor = 0;
int qtyVertices;
int arrColor[maxN];

void readFile();
void handle();
void exportResult();

int main() {
    readFile();

    cout << "The number of vertices in the graph is " << qtyVertices << endl;

    handle();
    exportResult();

    return 0;
}

void readFile() {
    int p, q;
    ifstream graph ("graph.txt");
    if (graph.is_open()) {
        graph >> qtyVertices;

        while (!graph.eof()) {
            graph >> q;
            graph >> p;
            arr[q][p] = 1;
            arr[p][q] = 1;
        }
        graph.close();
    } else cout << "File not found, try again!" << endl;
}

void handle() {
    int kt;
    for(int i=1; i<=qtyVertices; ++i) {
        if(!arrColor[i]) {
            qtyColor++;
            arrColor[i] = qtyColor;

            for(int j=i+1; j<=qtyVertices; ++j) {
                if((arr[i][j] == 0) && (arrColor[j] == 0)) {
                    kt = 1;

                    for(int k=i+1;k<j;k++)
                        if((arr[k][j] == 1) && (arrColor[i] == arrColor[k])) {
                            kt=0;
                            break;
                        }
                    if(kt == 1) arrColor[j]=qtyColor;
                }       
            }            
        }
    }
}

void exportResult() {
    for(int i=1; i<=qtyColor; ++i) {
        cout << "Color " << i << " -----> ";
        for(int j=1; j<=qtyVertices; ++j) 
            if(arrColor[j] == i) 
                cout << "Vertices " << j << " ";
        cout << endl;
    }
}