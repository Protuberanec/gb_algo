//
// Created by Tr on 29.07.2021.
//

#ifndef CPP_PROJ_GRAPH_H
#define CPP_PROJ_GRAPH_H

#include <iostream>
#include <stdio.h>
#include "stack_filo.h"
#include "stack_fifo.h"
#include "array_func.h"

#define SHOW_VERTEX

using INFO_VERTEX = FIFO<std::pair<int/*vertex*/, int /*count relations*/>>;

class GRAPH {
private :
    int** AdjMatrix;    //adjacency - просто чтобы слово запомнить....
    int* presence;
    int* count_relations;
    int N_vertex;
public:
    int getNVertex() const;

private:

    void removeGraph();
    void restartPresence() {
        memset(presence, 0x00, N_vertex * sizeof(int));
    }
    void restartRelations() {
        memset(count_relations, 0x00, N_vertex * sizeof(int));
    }

    int depthFirst_rec(int head_vertex, int current_vertex) const;
    int countAdjVertex(int vertex, int adjVertex = -1);

public :
    GRAPH();
    GRAPH(int nVertex);
    ~GRAPH();

    void copyGraph(int *ar, int count_vertex);

    void SetRelation(int vertex1, int vertex2);
    void SetDirRelation(int from_vertex, int to_vertex, bool bidir = false);
    void deleteVertex(int vertex);

    void breadthFirst(int vertex) const;
    void depthFirst(int vertex) const;

    INFO_VERTEX* countAdjVertexWithMain(int main_vertex);

    INFO_VERTEX* GetListVertex();

};

#endif //CPP_PROJ_GRAPH_H
