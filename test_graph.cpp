//
// Created by Tr on 29.07.2021.
//

#include "test_graph.h"

void test_graph() {
    {//test1 breadth search
        std::cout << "----- breadth search ------" << std::endl;
        const int VERTEX_AMOUNT = 10;
        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);
        my_graph->breadthFirst(4);

        delete my_graph;
        std::cout << "----- end breadth search ------" << std::endl;
    }

    {//test2 depth search
        std::cout << "----- depth search ------" << std::endl;
        const int VERTEX_AMOUNT = 10;
        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);
        my_graph->depthFirst(4);

        delete my_graph;
        std::cout << "----- end depth search ------" << std::endl;
    }

    {//test3 find adjective vertex with head vertes
        std::cout << "----- task 2.1 ------" << std::endl;
        const int VERTEX_AMOUNT = 10;
        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);

        for (int central_element = 0; central_element < my_graph->getNVertex(); central_element++) {
            std::cout << "look for adjacent for V " << central_element << " : ";
            auto infoVertex = my_graph->countAdjVertexWithMain(central_element);

            std::pair<int, int> vertex_info;
            while (infoVertex->pop(vertex_info)) {
                if (vertex_info.second == 0) {
                    std::cout << "other relations vertex is zero" << std::endl;
                    break;
                }
                std::cout << "( " << vertex_info.first << " - " << vertex_info.second << " ) ";
            }
//            std::cout << std::endl;
        }


        delete my_graph;
        std::cout << "----- end ------" << std::endl;
    }
    {//test3 find adjective vertex with head vertes
        std::cout << "----- task 2.2 -----" << std::endl;
        const int VERTEX_AMOUNT = 10;

        int adjMatrix[VERTEX_AMOUNT][VERTEX_AMOUNT] = { {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},    //0
                                                        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},    //1
                                                        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},    //2
                                                        {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},    //3
                                                        {0, 0, 0, 1, 0, 0, 1, 1, 0, 0},    //4
                                                        {1, 0, 0, 1, 0, 0, 1, 0, 0, 0},    //5
                                                        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},    //6
                                                        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},    //7
                                                        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},    //8
                                                        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}     //9
        };

        GRAPH *my_graph = new GRAPH();
        my_graph->copyGraph(&adjMatrix[0][0], VERTEX_AMOUNT);
        auto infoVertex = my_graph->GetListVertex();

        std::pair<int,int> vertex_info;
        std::cout << "( V - R )" << std::endl;
        while(infoVertex->pop(vertex_info)) {
            std::cout << "( " << vertex_info.first << " - " << vertex_info.second << " )" << std::endl;
        }

        delete infoVertex;

        delete my_graph;
        std::cout << "----- end ------" << std::endl;
    }

    std::cout << "Graph tests passed OK" << std::endl;

}
