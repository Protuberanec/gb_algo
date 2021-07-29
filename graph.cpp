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
    presence = new int [N_vertex];
    memset(presence, 0x00, N_vertex * sizeof(int));

    count_relations = new int [N_vertex];
    memset(count_relations, 0x00, N_vertex * sizeof(int));
}

GRAPH::~GRAPH() {
    for (int i = 0; i < N_vertex; i++) {
        delete [] AdjMatrix[i];
    }
    delete [] AdjMatrix;

    delete [] presence;
    delete [] count_relations;
}

GRAPH::GRAPH(int nVertex) : N_vertex(nVertex) {
    AdjMatrix = new int *[N_vertex];
    for (int i = 0; i < N_vertex; i++) {
        AdjMatrix[i] = new int [N_vertex];
        memset(AdjMatrix[i], 0x00, N_vertex * sizeof(int));
    }
    presence = new int [N_vertex];
    memset(presence, 0x00, N_vertex * sizeof(int));

    count_relations = new int [N_vertex];
    memset(count_relations, 0x00, N_vertex * sizeof(int));
}
/*
 *  input       :
 *  output      :
 *  descirption :   перебор в ширину.... с использованиее стека
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
 *  descirption :   перебор в ширину.... с использование стека
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

INFO_VERTEX* GRAPH::countAdjVertexWithMain(int main_vertex) {
    restartPresence();
    restartRelations();

    countAdjVertex(0, main_vertex);

    INFO_VERTEX* infoVertex = new INFO_VERTEX(N_vertex + 1);

    for (int i = 0; i < N_vertex; i++) {
        int indMax = array1D_GetIndexMax(count_relations, N_vertex);
        infoVertex->push({indMax, count_relations[indMax]});
        count_relations[indMax] = std::numeric_limits<int>::min();
    }

    return infoVertex;
}

// 2.1 - обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
int GRAPH::depthFirst_rec(int head_vertex, int current_vertex) const {
    FIFO<int> *stack = new FIFO<int>(N_vertex);
    int count = 0;

    for (int i = 0; i < N_vertex; i++) {
        if (presence[i] != 1 && AdjMatrix[current_vertex][i] == 1) {
            stack->push(i);
            presence[i] = 1;
            if (current_vertex == head_vertex) {
                count++;
            }
        }
    }
    int next_element;
    if (stack->pop(next_element)) {
        count += depthFirst_rec(head_vertex, next_element);
    }

    delete stack;

    return count;
}

// 2.2 - обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести
//       два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.
/*  input       :   vertex - start go through graph,
 *                  adjVertex is adjacent vertex relative to count relations
 *  output      :   change of array (presence, and count_relations) in class
 *  date        :   2021.07.29
 *  author      :   我
 *  description :   recursive....
 */
int GRAPH::countAdjVertex(int vertex, int adjVertex) {
    if (presence[vertex] == 1)
        return 0;
    presence[vertex] = 1;
    for (int i = 0; i < N_vertex; i++) {
        if (AdjMatrix[vertex][i] == 1) {
            if (i == adjVertex) {
                count_relations[vertex]++;
            }
            else if (adjVertex == -1) {
                count_relations[vertex]++;
            }
            if (presence[i] == 0) {
                countAdjVertex(i, adjVertex);
            }
        }
    }
    return 0;
}

INFO_VERTEX* GRAPH::GetListVertex() {
    restartPresence();
    restartRelations();

    countAdjVertex(0);

    INFO_VERTEX* infoVertex = new INFO_VERTEX(N_vertex + 1);

    for (int i = 0; i < N_vertex; i++) {
        int indMax = array1D_GetIndexMax(count_relations, N_vertex);
        infoVertex->push({indMax, count_relations[indMax]});
        count_relations[indMax] = std::numeric_limits<int>::min();
    }

    return infoVertex;
}

int GRAPH::getNVertex() const {
    return N_vertex;
}

