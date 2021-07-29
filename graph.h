//
// Created by Tr on 29.07.2021.
//

#ifndef CPP_PROJ_GRAPH_H
#define CPP_PROJ_GRAPH_H

#include <iostream>
#include <stdio.h>
#include "stack_filo.h"
#include "stack_fifo.h"

#define SHOW_VERTEX

class GRAPH {
private :
    int** AdjMatrix;    //adjacency - просто чтобы слово запомнить....
    int N_vertex;

    void removeGraph();


public :
    GRAPH();
    GRAPH(int nVertex);
    ~GRAPH();

    void copyGraph(int *ar, int count_vertex);


    void SetRelation(int vertex1, int vertex2);
    void SetDirRelation(int from_vertex, int to_vertex, bool bidir = false);


    void breadthFirst(int vertex) const;
    void depthFirst(int vertex) const;
};

#endif //CPP_PROJ_GRAPH_H
