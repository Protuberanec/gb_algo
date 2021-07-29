//
// Created by Tr on 29.07.2021.
//

#include "test_graph.h"

void test_graph() {
    {//test1 breadth search
        std::cout << "----- breadth search ------" << std::endl;
        const int VERTEX_AMOUNT = 10;
        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);
        my_graph->breadthFirst(4);

        delete my_graph;
        std::cout << "----- end breadth search ------" << std::endl;
    }

    {//test1 depth search
        std::cout << "----- depth search ------" << std::endl;
        const int VERTEX_AMOUNT = 10;
        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);
        my_graph->depthFirst(4);

        delete my_graph;
        std::cout << "----- end depth search ------" << std::endl;
    }

}
