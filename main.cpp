
#include <iostream>
#include <limits>
#include <assert.h>
#include <cstring>
#include <string>
#include <iterator>
#include <algorithm>
#include <regex>
#include "array_func.h" //standard function to work with array... very usefull...
#include "ConsoleWork.h"    //stupid attempt to write own lib to work with console...

#include "graph.h"
#include "test_graph.h"


using namespace std;


//1. Реализовать обход в глубину с использованием стека - сделано в функции my_graph->breadthFirst(4);

//2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями. Нужно обойти этот граф двумя способами и
//  подсчитать количество ссылок на каждый из узлов графа (полустепень захода):
//      2.1 - обход графа рекурсивной функцией (с подсчётом только смежных со стартовой вершин)
//      2.2 - обход графа по матрице смежности (с подсчётом всех вершин графа) В конце обхода вывести
//              два получившихся списка всех узлов в порядке уменьшения количества ссылок на них.

//Полустепень захода вершины - количество дуг, заходящих в эту вершину.

int main(int argc, char** argv) {

    test_graph();
    std::cout << "\t\tall tests passed OK" << std::endl;

    return 0;
}
