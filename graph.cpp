//
// Created by Tr on 29.07.2021.
//

#include "graph.h"

using namespace std;

GRAPH::GRAPH() {
    N_vertex = 10;
    AdjMatrix = new int *[N_vertex];
    for (int i = 0; i < N_vertex; i++) {
        AdjMatrix[i] = new int [N_vertex];
        memset(AdjMatrix[i], 0x00, N_vertex * sizeof(int));
    }
}

GRAPH::~GRAPH() {
    for (int i = 0; i < N_vertex; i++) {
        delete [] AdjMatrix[i];
    }
    delete [] AdjMatrix;
}

GRAPH::GRAPH(int nVertex) : N_vertex(nVertex) {
    AdjMatrix = new int *[N_vertex];
    for (int i = 0; i < N_vertex; i++) {
        AdjMatrix[i] = new int [N_vertex];
        memset(AdjMatrix[i], 0x00, N_vertex * sizeof(int));
    }
}
/*
 *  input       :
 *  output      :
 *  descirption :   перебор в ширину....
 *  author      :   我
 *  date        :   2021.07.29
 */
void GRAPH::breadthFirst(int vertex) const {
    FIFO<int> *newElements = new FIFO<int>(N_vertex + 1);

    int *matrix_presense = new int [N_vertex+1];
    memset(matrix_presense, 0x00, (N_vertex + 1) * sizeof(int));

    int current_vertex = vertex;
    matrix_presense[vertex] = 1;

    while (1) {
        cout << current_vertex << " : ";
        for (int i = 0; i < N_vertex; i++) {
            if (AdjMatrix[current_vertex][i] == 1 && matrix_presense[i] == 0) {
                newElements->push(i);
                matrix_presense[i] = 1;
                cout << i << " ";
            }
        }
        cout << endl;
        if (!newElements->pop(current_vertex)) {
            break;  //elements is end...
        }
    }
    delete [] matrix_presense;
}

/*
 *  input       :
 *  output      :
 *  descirption :   перебор в ширину....
 *  author      :   我
 *  date        :   2021.07.29
 */
void GRAPH::depthFirst(int vertex) const {
    FILO<int> *newElements = new FILO<int>(N_vertex * 2);

    int *matrix_presense = new int [N_vertex+1];
    memset(matrix_presense, 0x00, (N_vertex + 1) * sizeof(int));

    int current_vertex = vertex;
    cout << current_vertex << " ";
    flush(cout);

    newElements->push(vertex);
    int prev_vertex;
    while (1) {
        matrix_presense[current_vertex] = 1;
        int i = 0;
        for (; i < N_vertex; i++) {
            if (AdjMatrix[current_vertex][i] == 1 && matrix_presense[i] == 0) {
                newElements->push(i);
                current_vertex = i;
                break;
            }
        }

        if (i >= N_vertex) {
            if(!newElements->pop(current_vertex)) {
                break;
            }
        }
        else {
#ifdef SHOW_VERTEX
            cout << current_vertex << " ";
            flush(cout);
#endif
        }
    }
    cout << endl;
    delete [] matrix_presense;
}

void GRAPH::copyGraph(int *ar, int count_vertex) {
    removeGraph();
    N_vertex = count_vertex;
    AdjMatrix = new int *[N_vertex];
    for (int i = 0; i < N_vertex; i++) {
        AdjMatrix[i] = new int [N_vertex];
        memcpy(AdjMatrix[i], &ar[i*count_vertex], count_vertex * sizeof(int));
    }
}

void GRAPH::removeGraph() {
    for (int i = 0; i < N_vertex; i++) {
        delete [] AdjMatrix[i];
    }
    delete [] AdjMatrix;
    N_vertex = 0;
}
